#include "GV.h"

//��
static int font;//�t�H���g�p
static char *fonttype;//�t�H���g�^�C�v
static int gage_x = 200;
static int flag = 1;//0�ɂ���ƒl������������o�O������
static int count = 1;//0�ɂ���ƒl������������o�O������
static char condition_char[64];


//�Q�[���������[�v
void condition_update() {
	gpUpdateMouse();

	if (gage_x <= 100) {
		flag = 1;
	}
	else if (gage_x >= 300) {
		flag = 0;
	}

	if (flag == 0) {
		gage_x -= 4;
	}
	else if (flag == 1) {
		gage_x += 4;
	}

	/*DrawFormatString(300, 300, GetColor(255, 255, 255), "%d", Mouse[0]);
	DrawFormatString(300, 200, GetColor(255, 255, 255), "%d", flag);
	DrawFormatString(300, 310, GetColor(255, 255, 255), "%d", count);
	*/

	if (Mouse[0] == 1) { // ���N���b�N��������Ă�����
		flag = 2;                       // �E�ֈړ�
	}

	if (flag == 2) {
		count++;
		if (count >= 100)
			Game_Scene = 2;
	}
	sprintf(condition_char, "%d", (gage_x - 100) * 500 / 200);
}

//�`�揈��
void condition_draw() {
	
	DrawBox(100, 100, gage_x, 150, GetColor(255, 0, 0), TRUE);
	DrawBox(100, 100, 300, 150, GetColor(255, 255, 255), FALSE);

	DrawStringToHandle(300, 200, condition_char, GetColor(255, 255, 255), font);
}


//�������֐�
void condition_initialize() {
	fonttype = "Segoe Script";

	font = CreateFontToHandle(fonttype, 50, 3, DX_FONTTYPE_ANTIALIASING_EDGE);//�t�H���g������
	if (font == -1) {
		printf("not find " + *fonttype);
		///exit(-1);
	}
}


//�Q�[�������̏I���֐�
void condition_finalize() {

}