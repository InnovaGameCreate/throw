#include "GV.h"

//仮
int x = 200;
static int flag = 1;//0にすると値が増え続けるバグが発生
static int count = 1;//0にすると値が増え続けるバグが発生


//ゲーム処理ループ
void condition_update() {
	gpUpdateMouse();

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

	DrawFormatString(300, 300, GetColor(255, 255, 255), "%d", Mouse[0]);
	DrawFormatString(300, 200, GetColor(255, 255, 255), "%d", flag);
	DrawFormatString(300, 310, GetColor(255, 255, 255), "%d", count);

	if (Mouse[0] == 1) { // 左クリックが押されていたら
		flag = 2;                       // 右へ移動
	}

	if (flag == 2) {
		count++;
		if (count >= 100)
			Game_Scene = 2;
	}

}

//描画処理
void condition_draw() {
	
	DrawBox(100, 301, 150, 100, GetColor(255, 255, 255), FALSE);
	DrawBox(100, x, 150, 300, GetColor(255, 0, 0), TRUE);
}


//初期化関数
void condition_initialize() {

}


//ゲーム処理の終了関数
void condition_finalize() {

}