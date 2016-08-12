#include "GV.h"

#define PI 3.14

static int move_img, enemy_img, great_img;//画像用
static int move_img_x1 = 0, move_img_x2 = WINDOW_WIDE;//背景の移動用
static int move_speed = 4;//背景の動く速さ
static int count = 0;//どれだけ動いたか
static int distance = -1;//投げる距離（−１の時は未計算）
static int result_scene = 0;

int decide_distance();//投げる距離を計算



//ゲーム処理ループ
void result_update() {
	if (distance == -1)
		distance = decide_distance();//投げる距離を計算


	//背景の移動
	move_img_x1 -= move_speed;
	if (move_img_x1 <= -(WINDOW_WIDE))
		move_img_x1 = WINDOW_WIDE;
	move_img_x2 -= move_speed;
	if (move_img_x2 <= -(WINDOW_WIDE))
		move_img_x2 = WINDOW_WIDE;



	if (count < distance) {//飛距離で止める
		count += 5;
	}else{
		count = distance;
		if (distance >= 0)
			result_scene = 1;//成功
		else
			result_scene = 2;//失敗
	}
}

//描画処理
void result_draw() {
	if (result_scene == 0) {
		DrawGraph(move_img_x1, 0, move_img, TRUE); //画像の描画
		DrawGraph(move_img_x2, 0, move_img, TRUE); //画像の描画

		DrawFormatString(300, 150, GetColor(255, 0, 0), "%d", count);//距離

		DrawRotaGraph(100, 200, 0.3, PI / 180 * (count % 360), enemy_img, TRUE);//敵
	}
	else if (result_scene == 1) {
		DrawGraph(0, 0, great_img, TRUE); //画像の描画
	}
	else if (result_scene == 2) {

	}
}


//初期化関数
void result_initialize() {
	move_img = LoadGraph("img/mati1.jpg");//画像ロード
	if (move_img == -1) {
		printf("not find mati1.jpg");
		///exit(-1);
	}
	enemy_img = LoadGraph("img/sample.png");//画像ロード
	if (enemy_img == -1) {
		printf("not find sample.png");
		///exit(-1);
	}
	great_img = LoadGraph("img/mati4.jpg");//画像ロード
	if (great_img == -1) {
		printf("not find mati4.jpg");
		///exit(-1);
	}
}


//ゲーム処理の終了関数
void result_finalize() {

}

//投げる距離を計算
int decide_distance() {
	int power = 200;
	int condition = 500;
	int timing = 2;

	return (power + condition) * timing;
}