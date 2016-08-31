#include "GV.h"

//仮
static int font;//フォント用
static char *fonttype;//フォントタイプ
static int gage_x = 200;
static int flag = 0;
static int count = 0;
static char condition_char[64];
static int background;//画像用
static int flag_re = 0;


//ゲーム処理ループ
void condition_update() {
	if (flag_re == 0) {
		restart();
		flag_re = 1;
	}
	if (gage_x <= 100) {
		flag = 1;
	}
	else if (gage_x >= 300) {
		flag = 0;
	}

	if (flag == 0) {
		gage_x -= 4;
	}
	else if (flag == 1) {
		gage_x += 4;
	}


	if (Mouse[0] == 1) { // 左クリックが押されていたら
		start_music(1);
		Game_Scene = 2;
		flag_re = 0;

	}


	if (gage_x <= 200) {
		condition = (gage_x - 100) * 5;
	}
	else if (gage_x >= 200) {
		condition = (300 - gage_x) * 5;
	}
		sprintf(condition_char, "%d", condition);

}

//描画処理
void condition_draw() {
	DrawGraph(0, 0, background, TRUE); //画像の描画

	DrawBox(100, 100, gage_x, 150, GetColor(255, 0, 0), TRUE);
	DrawBox(100, 100, 300, 150, GetColor(255, 255, 255), FALSE);

	DrawStringToHandle(300, 200, condition_char, GetColor(255, 255, 255), font);
}


//初期化関数
void condition_initialize() {
	fonttype = "Segoe Script";

	font = CreateFontToHandle(fonttype, 50, 3, DX_FONTTYPE_ANTIALIASING_EDGE);//フォント初期化
	if (font == -1) {
		printf("not find " + *fonttype);
		exit(-1);
	}

	background = LoadGraph("img/mati5.jpg");//画像ロード
	if (background == -1) {
		printf("not find mati1.jpg");
		exit(-1);
	}

}


//ゲーム処理の終了関数
void condition_finalize() {

}