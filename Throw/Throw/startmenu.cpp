#include "GV.h"

static int font[2];
static char *fonttype;
static int place_x = 280;
static int start_y = 250, start_x_size = 150, start_y_size = 30;
static int record_y = 310, record_x_size = 150, record_y_size = 30; 
static int close_y = 370, close_x_size = 150, close_y_size = 30;
static int start_f = 0, record_f = 0, close_f = 0;
static int mouse_x, mouse_y, mouse;
static int background;


//ゲーム処理ループ
void startmenu_update() {
	mouse = GetMouseInput();                //マウスの入力状態取得
	GetMousePoint(&mouse_x, &mouse_y);                //マウスの座標取得

	if (mouse_x > place_x - start_f * 10 && mouse_x < place_x + start_f * 10 + start_x_size && mouse_y > start_y - start_f * 10 && mouse_y < start_y + start_f * 10 + start_y_size)
		start_f = 1;
	else
		start_f = 0;

	if (mouse_x > place_x - record_f * 10 && mouse_x < place_x + record_f * 10 + record_x_size && mouse_y > record_y - record_f * 10 && mouse_y < record_y + record_f * 10 + record_y_size)
		record_f = 1;
	else
		record_f = 0;
	
	if (mouse_x > place_x - close_f * 10 && mouse_x < place_x + close_f * 10 + close_x_size && mouse_y > close_y - close_f * 10 && mouse_y < close_y + close_f * 10 + close_y_size)
		close_f = 1;
	else
		close_f = 0;

	if (mouse & MOUSE_INPUT_LEFT) { //マウスの左ボタンが押されていたら
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
}


//ゲーム処理の終了関数
void startmenu_finalize() {

}