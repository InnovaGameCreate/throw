#include "GV.h"

static int font[2];
static char *fonttype;
static int start_y = 150;


//�Q�[���������[�v
void startmenu_update() {

}

//�`�揈��
void startmenu_draw() {

}


//�������֐�
void startmenu_initialize() {
	fonttype = "Segoe Script";
	font[0] = CreateFontToHandle(fonttype, 50, 3, DX_FONTTYPE_ANTIALIASING_EDGE);//�t�H���g������
	if (font[0] == -1) {
		printf("not find " + *fonttype);
		exit(-1);
	}
	font[1] = CreateFontToHandle(fonttype, 30, 3, DX_FONTTYPE_ANTIALIASING_EDGE);//�t�H���g������
	if (font[1] == -1) {
		printf("not find " + *fonttype);
		exit(-1);
	}
}


//�Q�[�������̏I���֐�
void startmenu_finalize() {

}