//記録
#include "GV.h"

int font;
char *fonttype; 
char record_char[RECORD_N][64];

//ゲーム処理ループ
void record_update() {
	
}

//描画処理
void record_draw() {
	DrawStringToHandle(100, 50, "Record", GetColor(255, 255, 255), font);
	int i;
	for (i = 0; i < RECORD_N; i++) {
		DrawStringToHandle(100, 100 + i * 50, record_char[i], GetColor(255, 255, 255), font);
	}
}


//初期化関数
void record_initialize() {
	fonttype = "Segoe Script";
	font = CreateFontToHandle(fonttype, 50, 3, DX_FONTTYPE_ANTIALIASING_EDGE);//"メイリオ"  の30pt,太さ3のフォントを作成
	if (font == -1) {
		printf("not find "+ *fonttype);
		exit(-1);
	}

	save_load();//記録のロード

	int i;
	for (i = 0; i < RECORD_N; i++) {
		sprintf(record_char[i], "%d   %d", i + 1 , record[i]);
	}
}


//ゲーム処理の終了関数
void record_finalize() {

}