#include "GV.h"

//��
int x = 200;
int flag = 0;


//�Q�[���������[�v
void condition_update() {

	if (x <= 100) {
		flag = 1;
	}
	else if (x >= 300) {
		flag = 0;
	}

	if (flag == 0) {
		x -= 4;
	}
	else if (flag == 1) {
		x += 4;
	}

}

//�`�揈��
void condition_draw() {
	
	DrawBox(100, 302, 150, 100, GetColor(255, 255, 255), FALSE);
	DrawBox(100, x, 150, 300, GetColor(255, 0, 0), TRUE);
}


//�������֐�
void condition_initialize() {

}


//�Q�[�������̏I���֐�
void condition_finalize() {

}