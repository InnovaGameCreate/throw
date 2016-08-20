//�^�C�~���O�Q�[�W
#include "GV.h"

#define PI 3.14

static double x = 0, y = 0;
static double z = 0;
static int flag = 1;//0�ɂ���ƒl������������o�O������
static int count = 1;//0�ɂ���ƒl������������o�O������


//�Q�[���������[�v
void timing_update() {
	if (flag == 1) {
		z += 0.1;
		x = cos(z);
		y = sin(z);
	}
	if (Mouse[0] == 1) { // ���N���b�N��������Ă�����
		flag = 2;                   
		timing = 1;
	}

	if (flag == 2) {
		count++;
		if (count >= 100)
			Game_Scene = 4;
	}
}


//�`�揈��
void timing_draw() {
	DrawFormatString(300, 300, GetColor(255, 255, 255), "x:%.1f    y:%.1f    z:%.1f", x, y, z);

	DrawCircle(100, 100, 100, GetColor(255, 0, 0), TRUE);//�~��`��

	DrawLine(100 * x + 100, 100 * y + 100, 100, 100, GetColor(255, 255, 255));//����`��

}


//�������֐�
void timing_initialize() {
	//sqrt(pow(x, 2.0) + pow(y, 2.0)) = 1;
}


//�Q�[�������̏I���֐�
void timing_finalize() {

}