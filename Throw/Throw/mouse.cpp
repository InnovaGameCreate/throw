#include "GV.h"

/*�}�E�X����Ɋւ���t�@�C��*/
/*
�g�p��
���[�v��
gpUpdateMouse();�@�@�@�@�@�@�@�@�錾

if (Mouse[0] == 1) {			���N���b�N�������ꂽ�u��
	flag = 2;					�t���O��2�ɕς���
}
*/

int mouse_x, mouse_y, mouse;//�}�E�X�Ɋւ�����i�[�p

int Mouse[8]; // ���N���b�N��������Ă���t���[�������i�[����


int gpUpdateMouse() {// ���N���b�N�̓��͏�Ԃ��X�V����

	mouse = GetMouseInput();                //�}�E�X�̓��͏�Ԏ擾
	GetMousePoint(&mouse_x, &mouse_y);      //�}�E�X�̍��W�擾

	int tmpMouse[8]; // ���݂̃L�[�̓��͏�Ԃ��i�[����

	tmpMouse[0] = mouse & MOUSE_INPUT_LEFT;
	tmpMouse[1] = mouse & MOUSE_INPUT_RIGHT;
	tmpMouse[2] = mouse & MOUSE_INPUT_MIDDLE;
	tmpMouse[3] = mouse & MOUSE_INPUT_4;
	tmpMouse[4] = mouse & MOUSE_INPUT_5;
	tmpMouse[5] = mouse & MOUSE_INPUT_6;
	tmpMouse[6] = mouse & MOUSE_INPUT_7;
	tmpMouse[7] = mouse & MOUSE_INPUT_8;

	for (int i = 0; i<8; i++){

	if (tmpMouse[i] != 0) {//�{�^����������Ă���Ƃ�
		Mouse[i]++;     // ���Z
	}
	else {              // ������Ă��Ȃ����
		Mouse[i] = 0;   // 0�ɂ���
	}
}
return 0;
}