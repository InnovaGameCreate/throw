#include <math.h>
#include "DxLib.h"
#include "GV.h"
#include "define.h"

static int mStartTime;      //測定開始時刻
static int mCount;          //カウンタ
static float mFps;          //fps
static const int N = 60;	//平均を取るサンプル数
static const int FPS = 60;	//設定したFPSz 

int Game_Scene = 1;

bool Update() {
	if (mCount == 0) { //1フレーム目なら時刻を記憶
		mStartTime = GetNowCount();
	}
	if (mCount == N) { //60フレーム目なら平均を計算する
		int t = GetNowCount();
		mFps = 1000.f / ((t - mStartTime) / (float)N);
		mCount = 0;
		mStartTime = t;
	}
	mCount++;

	switch (Game_Scene) {
	case 0://スタートメニュー
		startmenu_draw();
		break;
	case 1://コンディション
		condition_update();
		break;
	case 2://パワー
		power_draw();
		break;
	case 3://タイミング
		timing_draw();
		break;
	case 4://リザルト
		result_draw();
		break;
	}

	return true;
}

void Draw() {
	DrawFormatString(0, 0, GetColor(255, 255, 255), "%.1f", mFps);

	switch (Game_Scene) {
		case 0://スタートメニュー
			startmenu_draw();
			break;
		case 1://コンディション
			condition_draw();
			break;
		case 2://パワー
			power_draw();
			break;
		case 3://タイミング
			timing_draw();
			break;
		case 4://リザルト
			result_draw();
			break;
	}

}

void Wait() {
	int tookTime = GetNowCount() - mStartTime;	//かかった時間
	int waitTime = mCount * 1000 / FPS - tookTime;	//待つべき時間
	if (waitTime > 0) {
		Sleep(waitTime);	//待機
	}
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK);

	while (ProcessMessage() == 0 && ClearDrawScreen() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
		Update();	//更新
		Draw();		//描画
		ScreenFlip();
		Wait();		//待機
	}

	DxLib_End();
	return 0;
}