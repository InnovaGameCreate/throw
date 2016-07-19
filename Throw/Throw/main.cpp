#include <math.h>
#include "DxLib.h"
#include "GV.h"
#include "define.h"

static int mStartTime;      //����J�n����
static int mCount;          //�J�E���^
static float mFps;          //fps
static const int N = 60;	//���ς����T���v����
static const int FPS = 60;	//�ݒ肵��FPSz 

int Game_Scene = 1;

bool Update() {
	if (mCount == 0) { //1�t���[���ڂȂ玞�����L��
		mStartTime = GetNowCount();
	}
	if (mCount == N) { //60�t���[���ڂȂ畽�ς��v�Z����
		int t = GetNowCount();
		mFps = 1000.f / ((t - mStartTime) / (float)N);
		mCount = 0;
		mStartTime = t;
	}
	mCount++;

	switch (Game_Scene) {
	case 0://�X�^�[�g���j���[
		startmenu_draw();
		break;
	case 1://�R���f�B�V����
		condition_update();
		break;
	case 2://�p���[
		power_draw();
		break;
	case 3://�^�C�~���O
		timing_draw();
		break;
	case 4://���U���g
		result_draw();
		break;
	}

	return true;
}

void Draw() {
	DrawFormatString(0, 0, GetColor(255, 255, 255), "%.1f", mFps);

	switch (Game_Scene) {
		case 0://�X�^�[�g���j���[
			startmenu_draw();
			break;
		case 1://�R���f�B�V����
			condition_draw();
			break;
		case 2://�p���[
			power_draw();
			break;
		case 3://�^�C�~���O
			timing_draw();
			break;
		case 4://���U���g
			result_draw();
			break;
	}

}

void Wait() {
	int tookTime = GetNowCount() - mStartTime;	//������������
	int waitTime = mCount * 1000 / FPS - tookTime;	//�҂ׂ�����
	if (waitTime > 0) {
		Sleep(waitTime);	//�ҋ@
	}
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK);

	while (ProcessMessage() == 0 && ClearDrawScreen() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
		Update();	//�X�V
		Draw();		//�`��
		ScreenFlip();
		Wait();		//�ҋ@
	}

	DxLib_End();
	return 0;
}