#include "GV.h"

int bgm1;
int decide, result;


//初期化関数
void music_initialize() {
	
	bgm1 = LoadSoundMem("music/bgm1.ogg");
	if (bgm1 == NULL) {
		printf("not find bgm1.ogg");
		exit(-1);
	}

	decide = LoadSoundMem("music/decide.ogg");
	if (decide == NULL) {
		printf("not find decide.ogg");
		exit(-1);
	}

	result = LoadSoundMem("music/result.ogg");
	if (result == NULL) {
		printf("not find result.ogg");
		exit(-1);
	}

	start_music(0);
}


//ゲーム処理の終了関数
void music_finalize() {

}

//音楽を鳴らす
void start_music(int h) {
	switch (h)
	{

	case 0://BGM1
		PlaySoundMem(bgm1, DX_PLAYTYPE_LOOP); // 効果音を再生する
		break;
	case 1://決定音
		PlaySoundMem(decide, DX_PLAYTYPE_NORMAL); // 効果音を再生する
		break;

	case 2://結果表示音
		PlaySoundMem(result, DX_PLAYTYPE_NORMAL); // 効果音を再生する
		break;

	}
}

//音楽を止める
void stop_music(int h) {

	switch (h)
	{
	case 0://BGM1
		StopSoundMem(bgm1);
		break;
	case 1://決定音
		StopSoundMem(decide);
		break;

	case 2://結果表示音
		StopSoundMem(result);
		break;

	}

}