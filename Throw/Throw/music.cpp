#include "GV.h"

int bgm1;
int decide, result;


//�������֐�
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


//�Q�[�������̏I���֐�
void music_finalize() {

}

//���y��炷
void start_music(int h) {
	switch (h)
	{

	case 0://BGM1
		PlaySoundMem(bgm1, DX_PLAYTYPE_LOOP); // ���ʉ����Đ�����
		break;
	case 1://���艹
		PlaySoundMem(decide, DX_PLAYTYPE_NORMAL); // ���ʉ����Đ�����
		break;

	case 2://���ʕ\����
		PlaySoundMem(result, DX_PLAYTYPE_NORMAL); // ���ʉ����Đ�����
		break;

	}
}

//���y���~�߂�
void stop_music(int h) {

	switch (h)
	{
	case 0://BGM1
		StopSoundMem(bgm1);
		break;
	case 1://���艹
		StopSoundMem(decide);
		break;

	case 2://���ʕ\����
		StopSoundMem(result);
		break;

	}

}