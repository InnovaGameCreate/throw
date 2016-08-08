//�L�^
#include "GV.h"

int font;
char *fonttype; 
char record_char[RECORD_N][64];

//�Q�[���������[�v
void record_update() {
	
}

//�`�揈��
void record_draw() {
	DrawStringToHandle(100, 50, "Record", GetColor(255, 255, 255), font);
	int i;
	for (i = 0; i < RECORD_N; i++) {
		DrawStringToHandle(100, 100 + i * 50, record_char[i], GetColor(255, 255, 255), font);
	}
}


//�������֐�
void record_initialize() {
	fonttype = "Segoe Script";
	font = CreateFontToHandle(fonttype, 50, 3, DX_FONTTYPE_ANTIALIASING_EDGE);//"���C���I"  ��30pt,����3�̃t�H���g���쐬
	if (font == -1) {
		printf("not find "+ *fonttype);
		exit(-1);
	}

	save_load();//�L�^�̃��[�h

	int i;
	for (i = 0; i < RECORD_N; i++) {
		sprintf(record_char[i], "%d   %d", i + 1 , record[i]);
	}
}


//�Q�[�������̏I���֐�
void record_finalize() {

}