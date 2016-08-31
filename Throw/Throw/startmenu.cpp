#include "GV.h"

static int font[2];//フォント用
static char *fonttype;//フォントタイプ
static int place_x = 260;//文字のx座標
static int start_y = 250, start_x_size = 150, start_y_size = 30;//startの座標
static int record_y = 310, record_x_size = 150, record_y_size = 30; //recordの座標
static int close_y = 370, close_x_size = 150, close_y_size = 30;//closeの座標
static int start_f = 0, record_f = 0, close_f = 0;//マウスで選択されているかのフラグ

static int background, rogo;//画像用


//ゲーム処理ループ
void startmenu_update() {

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
		start_music(3);
		if (start_f == 1)
			Game_Scene = 1;
		if (record_f == 1)
			Game_Scene = 5;
		if (close_f == 1)
			game_loop = 1;
	}
}

//描画処理
void startmenu_draw() {
	DrawGraph(0, 0, background, TRUE); //画像の描画

	DrawStringToHandle(place_x - start_f * 10, start_y - start_f * 10, "start", GetColor(255, 255, 255), font[start_f]);
	DrawStringToHandle(place_x - record_f * 10, record_y - record_f * 10, "record", GetColor(255, 255, 255), font[record_f]);
	DrawStringToHandle(place_x - close_f * 10, close_y - close_f * 10, "close", GetColor(255, 255, 255), font[close_f]);

	DrawGraph(220, 100, rogo, TRUE); //画像の描画
}


//初期化関数
void startmenu_initialize() {
	fonttype = "Segoe Script";
	
	font[1] = CreateFontToHandle(fonttype, 50, 3, DX_FONTTYPE_ANTIALIASING_EDGE);//フォント初期化
	if (font[0] == -1) {
		printf("not find " + *fonttype);
		exit(-1);
	}

	font[0] = CreateFontToHandle(fonttype, 30, 3, DX_FONTTYPE_ANTIALIASING_EDGE);//フォント初期化
	if (font[1] == -1) {
		printf("not find " + *fonttype);
		exit(-1);
	}

	background = LoadGraph("img/mati2.jpg");//画像ロード
	if (background == -1) {
		printf("not find mati1.jpg");
		exit(-1);
	}
	
	rogo = LoadGraph("img/rogo1.png");//画像ロード
	if (rogo == -1) {
		printf("not find rogo1.png");
		exit(-1);
	}
}


//ゲーム処理の終了関数
void startmenu_finalize() {

}