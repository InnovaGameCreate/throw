//タイミングゲージ
#include "GV.h"
double x = 0, y = 0;
double z = 0;

//ゲーム処理ループ
void timing_update() {
	z += 0.1;
	x = cos(z);
	y = sin(z);
}


//描画処理
void timing_draw() {
	DrawFormatString(300, 300, GetColor(255, 255, 255), "%.1f", x);

	DrawCircle(100, 100, 100, GetColor(255, 0, 0), TRUE);//円を描画

	DrawLine(100 * x + 100, 100 * y + 100, 100, 100, GetColor(255, 255, 255));//線を描画

}


//初期化関数
void timing_initialize() {
	//sqrt(pow(x, 2.0) + pow(y, 2.0)) = 1;
}


//ゲーム処理の終了関数
void timing_finalize() {

}