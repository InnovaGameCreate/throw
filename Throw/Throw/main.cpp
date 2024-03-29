#include <math.h>
#include "GV.h"

static int mStartTime;      //測定開始時刻
static int mCount;          //カウンタ
static float mFps;          //fps
static const int N = 60;	//平均を取るサンプル数
static const int FPS = 60;	//設定したFPSz 

int Game_Scene = 0;
int game_loop = 0;
int power;
int condition;
int timing;


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
	gpUpdateMouse();
	switch (Game_Scene) {
	case 0://スタートメニュー
		startmenu_update();
		break;
	case 1://コンディション
		condition_update();
		break;
	case 2://パワー
		power_update();
		break;
	case 3://タイミング
		timing_update();
		break;
	case 4://リザルト
		result_update();
		break;
	case 5://レコード
		record_update();
		break;
	}

	return true;
}

void Draw() {

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
		case 5://レコード
			record_draw();
			break;
	}

	//DrawFormatString(0, 0, GetColor(255, 255, 255), "%.1f  %d", mFps, Game_Scene);//デバック用

}

void Wait() {
	int tookTime = GetNowCount() - mStartTime;	//かかった時間
	int waitTime = mCount * 1000 / FPS - tookTime;	//待つべき時間
	if (waitTime > 0) {
		Sleep(waitTime);	//待機
	}
}



//初期化
void initialize() {
	condition_initialize();
	power_initialize();
	record_initialize();
	result_initialize();
	save_initialize();
	startmenu_initialize();
	timing_initialize();
	music_initialize();
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	ChangeWindowMode(TRUE);
	SetGraphMode(WINDOW_WIDE, WINDOW_HEIGHT, 16);//ウィンドウの大きさ変更
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);
	
	initialize();
	
	
	while (ProcessMessage() == 0 && ClearDrawScreen() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
		Update();	//更新
		Draw();		//描画
		ScreenFlip();
		Wait();		//待機
	

		if (game_loop == 1)
			break;
	}	
	


	DxLib_End();
	return 0;
}

