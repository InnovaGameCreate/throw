#include "GV.h"

//仮
int x = 200;
int flag = 0;


//ゲーム処理ループ
void condition_update() {

	if (x <= 100) {
		flag = 1;
	}
	else if (x >= 300) {
		flag = 0;
	}

	if (flag == 0) {
		x -= 4;
	}
	else if (flag == 1) {
		x += 4;
	}

}

//描画処理
void condition_draw() {
	
	DrawBox(100, 302, 150, 100, GetColor(255, 255, 255), FALSE);
	DrawBox(100, x, 150, 300, GetColor(255, 0, 0), TRUE);
}


//初期化関数
void condition_initialize() {

}


//ゲーム処理の終了関数
void condition_finalize() {

}