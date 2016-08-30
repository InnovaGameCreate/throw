#include "GV.h"

#define PI 3.14

static int font[3];//フォント用
static char *fonttype; //フォントタイプ
static char *fonttype2; //フォントタイプ２
static char draw_distance[10];
static int move_img, great_img, miss_img;//画像用
static int move_img_x1 = 0, move_img_x2 = WINDOW_WIDE;//背景の移動用
static int move_speed = 4;//背景の動く速さ
static int count = 0;//どれだけ動いたか
static int distance = -1;//投げる距離（－１の時は未計算）
static int result_scene = 0;
static char distance_char[64];

int enemy_img, hera_img;

int decide_distance();//投げる距離を計算

static int place_x = 260;//文字のx座標
static int start_y = 250, start_x_size = 150, start_y_size = 30;//startの座標
static int record_y = 310, record_x_size = 150, record_y_size = 30; //recordの座標
static int close_y = 370, close_x_size = 150, close_y_size = 30;//closeの座標
static int start_f = 0, record_f = 0, close_f = 0;//マウスで選択されているかのフラグ



//ゲーム処理ループ
void result_update() {
	if (distance == -1) {
		distance = decide_distance();//投げる距離を計算
		ranking(distance);//新しい記録をランキングに挿入
		save_output();//セーブ
		create_char();

		if (distance < 0) {
			move_img_x2 = -(WINDOW_WIDE);
		}

	}
	//背景の移動
	if (distance >= 0) {
		move_img_x1 -= move_speed;
		if (move_img_x1 <= -(WINDOW_WIDE))
			move_img_x1 = WINDOW_WIDE;
		move_img_x2 -= move_speed;
		if (move_img_x2 <= -(WINDOW_WIDE))
			move_img_x2 = WINDOW_WIDE;
	}
	else {
		move_img_x1 += move_speed;
		if (move_img_x1 >= WINDOW_WIDE)
			move_img_x1 = 0;
		move_img_x2 += move_speed;
		if (move_img_x2 >= WINDOW_WIDE)
			move_img_x2 = 0;
	}

	if(distance >= 0 && count < distance){
			count += 5;
	}
	else if (distance < 0 && count > distance) {
		count -= 5;
	}
	else{
		if (count != distance) {
			start_music(2);

			count = distance;
		}
		sprintf(draw_distance, "%dm", distance);

		//マウスがstartの上にあるかの判定
		if (mouse_x > place_x - start_f * 10 && mouse_x < place_x + start_f * 10 + start_x_size && mouse_y > start_y - start_f * 10 && mouse_y < start_y + start_f * 10 + start_y_size)
			start_f = 1;
		else
			start_f = 0;

		//マウスがrecordの上にあるかの判定
		if (mouse_x > place_x - record_f * 10 && mouse_x < place_x + record_f * 10 + record_x_size && mouse_y > record_y - record_f * 10 && mouse_y < record_y + record_f * 10 + record_y_size)
			record_f = 1;
		else
			record_f = 0;

		//マウスがcloseの上にあるかの判定
		if (mouse_x > place_x - close_f * 10 && mouse_x < place_x + close_f * 10 + close_x_size && mouse_y > close_y - close_f * 10 && mouse_y < close_y + close_f * 10 + close_y_size)
			close_f = 1;
		else
			close_f = 0;

		if (Mouse[0] == 1) { //マウスの左ボタンが押されていたら
			if (start_f == 1) {
				Game_Scene = 1;
				distance = -1;
				result_scene = 0;
				count = 0;
				move_img_x1 = 0;
				move_img_x2 = WINDOW_WIDE;
			}
			if (record_f == 1)
				Game_Scene = 5;
			if (close_f == 1)
				game_loop = 1;
		}


		if (distance >= 0)
			result_scene = 1;//成功
		else
			result_scene = 2;//失敗
	}
	sprintf(distance_char, "%d", count);

}

void restart() {
	distance = -1;
	result_scene = 0;
	count = 0;
	move_img_x1 = 0;
	move_img_x2 = WINDOW_WIDE;
}

//描画処理
void result_draw() {
	if (result_scene == 0) {
		DrawGraph(move_img_x1, 0, move_img, TRUE); //画像の描画
		DrawGraph(move_img_x2, 0, move_img, TRUE); //画像の描画

		DrawStringToHandle(350, 150, distance_char, GetColor(255, 255, 255), font[2]);

		DrawRotaGraph(100, 200, 0.3, PI / 180 * (count % 360), enemy_img, TRUE);//敵


	}
	else if (result_scene == 1) {
		DrawGraph(0, 0, great_img, TRUE); //画像の描画
		DrawStringToHandle(100, 50, "成功！", GetColor(255, 255, 255), font[2]);
		DrawStringToHandle(320, 50, draw_distance, GetColor(255, 255, 255), font[2]);

		DrawStringToHandle(place_x - start_f * 10, start_y - start_f * 10, "restart", GetColor(255, 255, 255), font[start_f]);
		DrawStringToHandle(place_x - record_f * 10, record_y - record_f * 10, "record", GetColor(255, 255, 255), font[record_f]);
		DrawStringToHandle(place_x - close_f * 10, close_y - close_f * 10, "close", GetColor(255, 255, 255), font[close_f]);
	}
	else if (result_scene == 2) {
		DrawGraph(0, 0, miss_img, TRUE); //画像の描画
		DrawStringToHandle(100, 50, "失敗...", GetColor(255, 255, 255), font[2]);
		DrawStringToHandle(350, 50, draw_distance, GetColor(255, 255, 255), font[2]);

		DrawStringToHandle(place_x - start_f * 10, start_y - start_f * 10, "restart", GetColor(255, 255, 255), font[start_f]);
		DrawStringToHandle(place_x - record_f * 10, record_y - record_f * 10, "record", GetColor(255, 255, 255), font[record_f]);
		DrawStringToHandle(place_x - close_f * 10, close_y - close_f * 10, "close", GetColor(255, 255, 255), font[close_f]);
	}


}


//初期化関数
void result_initialize() {
	move_img = LoadGraph("img/mati1.jpg");//画像ロード
	if (move_img == -1) {
		printf("not find mati1.jpg");
		exit(-1);
	}
	enemy_img = LoadGraph("img/enemy.png");//画像ロード
	if (enemy_img == -1) {
		printf("not find sample.png");
		exit(-1);
	}
	great_img = LoadGraph("img/mati3.jpg");//画像ロード
	if (great_img == -1) {
		printf("not find mati4.jpg");
		exit(-1);
	}

	miss_img = LoadGraph("img/miss.jpg");//画像ロード
	if (miss_img == -1) {
		printf("not find miss.jpg");
		exit(-1);
	}

	hera_img = LoadGraph("img/hera.png");//画像ロード
	if (hera_img == -1) {
		printf("not find hera.png");
		exit(-1);
	}

	fonttype = "MS ゴシック";// "Segoe Script";

	font[2] = CreateFontToHandle(fonttype, 50, 3, DX_FONTTYPE_ANTIALIASING_EDGE);//フォント初期化
	if (font[2] == -1) {
		printf("not find " + *fonttype);
		exit(-1);
	}

	fonttype2 = "Segoe Script";

	font[1] = CreateFontToHandle(fonttype2, 50, 3, DX_FONTTYPE_ANTIALIASING_EDGE);//フォント初期化
	if (font[0] == -1) {
		printf("not find " + *fonttype2);
		exit(-1);
	}

	font[0] = CreateFontToHandle(fonttype2, 30, 3, DX_FONTTYPE_ANTIALIASING_EDGE);//フォント初期化
	if (font[1] == -1) {
		printf("not find " + *fonttype2);
		exit(-1);
	}
}


//ゲーム処理の終了関数
void result_finalize() {

}

//投げる距離を計算
int decide_distance() {
	return (power + condition) * timing;
}



//新しい記録を挿入
void ranking(int get) {
	int i, j;
	for (i = 0; i < RECORD_N; i++) {
		if (record[i] < get || record[i] == -1) {
			for (j = RECORD_N; j > i; j--)
				record[j] = record[j - 1];

			record[i] = get;
			break;
		}
	}
}