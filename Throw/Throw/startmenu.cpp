#include "GV.h"

static int font[2];
static char *fonttype;
static int start_y = 150;


//ゲーム処理ループ
void startmenu_update() {

}

//描画処理
void startmenu_draw() {

}


//初期化関数
void startmenu_initialize() {
	fonttype = "Segoe Script";
	font[0] = CreateFontToHandle(fonttype, 50, 3, DX_FONTTYPE_ANTIALIASING_EDGE);//フォント初期化
	if (font[0] == -1) {
		printf("not find " + *fonttype);
		exit(-1);
	}
	font[1] = CreateFontToHandle(fonttype, 30, 3, DX_FONTTYPE_ANTIALIASING_EDGE);//フォント初期化
	if (font[1] == -1) {
		printf("not find " + *fonttype);
		exit(-1);
	}
}


//ゲーム処理の終了関数
void startmenu_finalize() {

}