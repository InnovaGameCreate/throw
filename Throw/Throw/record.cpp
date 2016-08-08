//記録
#include "GV.h"

static int font[2];
static char *fonttype; 
static char record_char[RECORD_N][64];
static char number[RECORD_N][3];
static int mouse_x, mouse_y, mouse;
static int delete_x = 100, delete_y = 350, delete_x_size = 180, delete_y_size = 30;
static int back_x = 400, back_y = 350, back_x_size = 90, back_y_size = 30;
static int back_f = 1, delete_f = 1;

void all_delete();//記録を消去する関数


//ゲーム処理ループ
void record_update() {
	mouse = GetMouseInput();                //マウスの入力状態取得
	GetMousePoint(&mouse_x, &mouse_y);                //マウスの座標取得
	
	if (mouse_x > back_x && mouse_x < back_x + back_x_size && mouse_x > back_y && mouse_y < back_y + back_y_size)
		back_f = 0;
	else
		back_f = 1;

	if (mouse_x > delete_x && mouse_x < delete_x + delete_x_size && mouse_y > delete_y && mouse_y < delete_y + delete_y_size)
		delete_f = 0;
	else
		delete_f = 1;
	if (mouse & MOUSE_INPUT_LEFT) { //マウスの左ボタンが押されていたら
		if (back_f == 0)
			Game_Scene = 0;
		if (delete_f == 0)
			all_delete();
	}
}

//描画処理
void record_draw() {
	DrawStringToHandle(100, 50, "Record", GetColor(255, 255, 255), font[0]);
	int i;
	for (i = 0; i < RECORD_N; i++) {
		if(record[i] != -1)	
			DrawStringToHandle(100, 130 + i * 50, record_char[i], GetColor(255, 255, 255), font[0]);
		DrawStringToHandle(100, 130 + i * 50, number[i], GetColor(255, 255, 255), font[0]);
	}
	
	DrawStringToHandle(delete_x, delete_y, "delete", GetColor(255, 255, 255), font[delete_f]);
	DrawStringToHandle(back_x, back_y, "back", GetColor(255, 255, 255), font[back_f]);
}


//初期化関数
void record_initialize() {
	fonttype = "Segoe Script";
	font[0] = CreateFontToHandle(fonttype, 50, 3, DX_FONTTYPE_ANTIALIASING_EDGE);//フォント初期化
	if (font[0] == -1) {
		printf("not find "+ *fonttype);
		exit(-1);
	}
	font[1] = CreateFontToHandle(fonttype, 30, 3, DX_FONTTYPE_ANTIALIASING_EDGE);//フォント初期化
	if (font[1] == -1) {
		printf("not find " + *fonttype);
		exit(-1);
	}

	save_load();//記録のロード

	int i;
	for (i = 0; i < RECORD_N; i++) {
		sprintf(record_char[i], "     %d", record[i]);
		sprintf(number[i], "%d", i + 1);
	}
}


//ゲーム処理の終了関数
void record_finalize() {

}

//記録を消去する関数
void all_delete() {
	int i;
	for (i = 0; i < RECORD_N; i++) {
		record[i] = -1;
	}
}