//タイミングゲージ
#include "GV.h"

#define PI 3.14

static int font;//フォント用
static char *fonttype;//フォントタイプ
static double x = 0, y = 0;
static double z = 0;
static int flag = 1;//0にすると値が増え続けるバグが発生
static int count = 1;//0にすると値が増え続けるバグが発生
static char timing_char[64];


					
int timig_decide(); //タイミング決定

//ゲーム処理ループ
void timing_update() {
	if (flag == 1) {
		z += 0.1;
		x = cos(z);
		y = sin(z);
		timing = timig_decide();
	}
	if (Mouse[0] == 1) { // 左クリックが押されていたら
		flag = 2;                   
		//timing = timig_decide();
		//z += 0.1;
	}
	//if (Mouse[1] == 1)
	//	z -= 0.1;

	//if (timing == -2)
	//	flag = 2;

	if (flag == 2) {
		count++;
		if (count >= 100) {
			//flag = 1;
			//count = 0;

			Game_Scene = 4;
		}
	}

	sprintf(timing_char, "%d", timing);
}


//描画処理
void timing_draw() {

	DrawFormatString(300, 300, GetColor(255, 255, 255), "x:%.1f    y:%.1f    z:%.1f", x, y, z);

	DrawFormatString(300, 350, GetColor(255, 100, 0), "timing:%d", timing);

	DrawCircle(100, 100, 100, GetColor(255, 0, 0), TRUE);//円を描画

	DrawLine(100 * (-0.9) + 100, 100 * (-0.4) + 100, 100, 100, GetColor(255, 100, 0));//線を描画
	DrawLine(100 * (-0.3) + 100, 100 * (-1.0) + 100, 100, 100, GetColor(255, 100, 0));//線を描画
	DrawLine(100 * (-0.8) + 100, 100 * 0.6 + 100, 100, 100, GetColor(255, 100, 0));//線を描画
	DrawLine(100 * (-0.1) + 100, 100 * 1.0 + 100, 100, 100, GetColor(255, 100, 0));//線を描画
	DrawLine(100 * 0.6 + 100, 100 * (-0.8) + 100, 100, 100, GetColor(255, 100, 0));//線を描画
	DrawLine(100 * 1.0 + 100, 100 * 0.1 + 100, 100, 100, GetColor(255, 100, 0));//線を描画


	DrawStringToHandle(40, 20, "2", GetColor(255, 255, 255), font);
	DrawStringToHandle(90, 10, "1", GetColor(255, 255, 255), font);
	DrawStringToHandle(20, 80, "1", GetColor(255, 255, 255), font);
	DrawStringToHandle(50, 130, "0", GetColor(255, 255, 255), font);
	DrawStringToHandle(140, 50, "0", GetColor(255, 255, 255), font);
	DrawStringToHandle(110, 120, "-1", GetColor(255, 255, 255), font);



	DrawLine(100 * x + 100, 100 * y + 100, 100, 100, GetColor(255, 255, 255));//線を描画

	DrawStringToHandle(300, 200, timing_char, GetColor(255, 255, 255), font);

}


//初期化関数
void timing_initialize() {
	fonttype = "Segoe Script";

	font = CreateFontToHandle(fonttype, 50, 3, DX_FONTTYPE_ANTIALIASING_EDGE);//フォント初期化
	if (font == -1) {
		printf("not find " + *fonttype);
		///exit(-1);
	}
}


//ゲーム処理の終了関数
void timing_finalize() {

}


//タイミング決定
int timig_decide() {
	int int_x = x * 10;
	int int_y = y * 10;
	if (int_x >= -9 && int_x <= -3 && int_y >= -10 && int_y <= -4)
		return 2;

	if (int_x >= -10 && int_x <= -8 && int_y >= -4 && int_y <= 6)
		return 1;
	if (int_x >= -3 && int_x <= 6 && int_y >= -10 && int_y <= -8)
		return 1;
	
	if (int_x >= -8 && int_x <= -1 && int_y >= 6 && int_y <= 10)
		return 0;
	if (int_x >= 6 && int_x <= 10 && int_y >= -8 && int_y <= 1)
		return 0;

	if (int_x >= -1 && int_x <= 10 && int_y >= 1 && int_y <= 10)
		return -1;
	
	return -2;
}