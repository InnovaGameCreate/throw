#include "GV.h"

static int font;//�t�H���g�p
static char *fonttype;//�t�H���g�^�C�v
static int gage_y = 200;
static int flag = 0;
static int count = 0;
static char power_char[64];
static int background;//�摜�p

//�Q�[���������[�v
void power_update() {

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

	power = (200 - gage_y + 100) * 500 / 200;
	sprintf(power_char, "%d", power);
	if (flag == 2) {
		count++;
		if (count >= 100) {
			Game_Scene = 3;
			flag = 1;
			count = 0;
		}
	}
}

//�`�揈��
void power_draw() {
	DrawGraph(0, 0, background, TRUE); //�摜�̕`��

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

	background = LoadGraph("img/mati5.jpg");//�摜���[�h
	if (background == -1) {
		printf("not find mati1.jpg");
		///exit(-1);
	}

}


//�Q�[�������̏I���֐�
void power_finalize() {

}