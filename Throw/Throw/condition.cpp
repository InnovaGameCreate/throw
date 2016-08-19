#include "GV.h"

//仮
static int font;//フォント用
static char *fonttype;//フォントタイプ
static int gage_x = 200;
static int flag = 1;//0にすると値が増え続けるバグが発生
static int count = 1;//0にすると値が増え続けるバグが発生
static char condition_char[64];


//ゲーム処理ループ
void condition_update() {
	gpUpdateMouse();

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

	/*DrawFormatString(300, 300, GetColor(255, 255, 255), "%d", Mouse[0]);
	DrawFormatString(300, 200, GetColor(255, 255, 255), "%d", flag);
	DrawFormatString(300, 310, GetColor(255, 255, 255), "%d", count);
	*/

	if (Mouse[0] == 1) { // 左クリックが押されていたら
		flag = 2;                       // 右へ移動
	}

	if (flag == 2) {
		count++;
		if (count >= 100)
			Game_Scene = 2;
	}
	sprintf(condition_char, "%d", (gage_x - 100) * 500 / 200);
}

//描画処理
void condition_draw() {
	
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
		///exit(-1);
	}
}


//ゲーム処理の終了関数
void condition_finalize() {

}