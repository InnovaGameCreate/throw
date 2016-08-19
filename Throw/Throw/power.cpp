#include "GV.h"

static int font;//�t�H���g�p
static char *fonttype;//�t�H���g�^�C�v
static int gage_y = 200;
static int flag = 1;//0�ɂ���ƒl������������o�O������
int power = 1;//0�ɂ���ƒl������������o�O������
static int count = 1;//0�ɂ���ƒl������������o�O������
static char power_char[64];

//�Q�[���������[�v
void power_update() {
	gpUpdateMouse();

	if (gage_y <= 100 && flag == 0) {
		flag = 1;
	}
	else if (gage_y >= 300 && flag == 1) {
		flag = 0;
	}

	if (flag == 0) {
		gage_y -= 4;
	}
	else if (flag == 1) {
		gage_y += 4;
	}

	
	if (Mouse[0] == 1) { // ���N���b�N��������Ă�����
		flag = 2;                       // �E�ֈړ�
	}
	sprintf(power_char, "%d", (200 - gage_y + 100) * 500 / 200);
	if (flag == 2) {
		count++;
		if (count >= 100)
			Game_Scene = 3;
	}
}

//�`�揈��
void power_draw() {
	DrawBox(100, gage_y, 150, 300, GetColor(255, 0, 0), TRUE);
	DrawBox(100, 301, 150, 100, GetColor(255, 255, 255), FALSE);

	DrawStringToHandle(300, 200, power_char, GetColor(255, 255, 255), font);

}



//�������֐�
void power_initialize() {
	fonttype = "Segoe Script";

	font = CreateFontToHandle(fonttype, 50, 3, DX_FONTTYPE_ANTIALIASING_EDGE);//�t�H���g������
	if (font == -1) {
		printf("not find " + *fonttype);
		///exit(-1);
	}
}


//�Q�[�������̏I���֐�
void power_finalize() {

}