#include "GV.h"

//��
int x = 200;
static int flag = 1;//0�ɂ���ƒl������������o�O������
static int count = 1;//0�ɂ���ƒl������������o�O������


//�Q�[���������[�v
void condition_update() {
	gpUpdateMouse();

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

	DrawFormatString(300, 300, GetColor(255, 255, 255), "%d", Mouse[0]);
	DrawFormatString(300, 200, GetColor(255, 255, 255), "%d", flag);
	DrawFormatString(300, 310, GetColor(255, 255, 255), "%d", count);

	if (Mouse[0] == 1) { // ���N���b�N��������Ă�����
		flag = 2;                       // �E�ֈړ�
	}

	if (flag == 2) {
		count++;
		if (count >= 100)
			Game_Scene = 2;
	}

}

//�`�揈��
void condition_draw() {
	
	DrawBox(100, 301, 150, 100, GetColor(255, 255, 255), FALSE);
	DrawBox(100, x, 150, 300, GetColor(255, 0, 0), TRUE);
}


//�������֐�
void condition_initialize() {

}


//�Q�[�������̏I���֐�
void condition_finalize() {

}