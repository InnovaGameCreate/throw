#include "GV.h"

static int font;//フォント用
static char *fonttype;//フォントタイプ
static int gage_y = 200;
static int flag = 0;
int power = 0;
static int count = 0;
static char power_char[64];


static int Key[256]; // キーが押されているフレーム数を格納する


// キーの入力状態を更新する
int gpUpdateKey() {
	char tmpKey[256]; // 現在のキーの入力状態を格納する
	GetHitKeyStateAll(tmpKey); // 全てのキーの入力状態を得る
	for (int i = 0; i < 256; i++) {
		if (tmpKey[i] != 0) { // i番のキーコードに対応するキーが押されていたら
			Key[i]++;     // 加算
		}
		else {              // 押されていなければ
			Key[i] = 0;   // 0にする
		}
	}
	return 0;
}

//ゲーム処理ループ
void power_update() {
	gpUpdateKey();

	if (gage_y <= 100 && flag == 0) {
		flag = 1;
	}
	else if (gage_y >= 300 && flag == 1) {
		flag = 0;
	}

	if (flag == 0) {
		gage_y -= 4;
	}
	else if (flag == 1) {
		gage_y += 2;
	}

	if (Key[KEY_INPUT_SPACE] >= 1) { // 右キーが押されていたら
		flag = 2;                       // 右へ移動
	}
	sprintf(power_char, "%d", (200 - gage_y + 100) * 500 / 200);
	if (flag == 2) {
		count++;
		if (count >= 100)
			Game_Scene = 3;
	}
}

//描画処理
void power_draw() {
	DrawBox(100, gage_y, 150, 300, GetColor(255, 0, 0), TRUE);
	DrawBox(100, 301, 150, 100, GetColor(255, 255, 255), FALSE);

	DrawStringToHandle(300, 200, power_char, GetColor(255, 255, 255), font);

}



//初期化関数
void power_initialize() {
	fonttype = "Segoe Script";

	font = CreateFontToHandle(fonttype, 50, 3, DX_FONTTYPE_ANTIALIASING_EDGE);//フォント初期化
	if (font == -1) {
		printf("not find " + *fonttype);
		///exit(-1);
	}
}


//ゲーム処理の終了関数
void power_finalize() {

}