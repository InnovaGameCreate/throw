//�^�C�~���O�Q�[�W
#include "GV.h"
double x = 0, y = 0;
double z = 0;

//�Q�[���������[�v
void timing_update() {
	z += 0.1;
	x = cos(z);
	y = sin(z);
}


//�`�揈��
void timing_draw() {
	DrawFormatString(300, 300, GetColor(255, 255, 255), "%.1f", x);

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