//�L�^
#include "GV.h"

static int font[2];//�t�H���g�p
static char *fonttype; //�t�H���g�^�C�v
static char record_char[RECORD_N][64];//�`��p
static char number[RECORD_N][3];//�`��p
static int mouse_x, mouse_y, mouse;//�}�E�X�̏��i�[�p
static int delete_x = 150, delete_y = 350, delete_x_size = 180, delete_y_size = 30;//�udelete�v�`��̍��W
static int back_x = 450, back_y = 350, back_x_size = 90, back_y_size = 30;//�uback�v�̍��W
static int back_f = 0, delete_f = 0;//�}�E�X�őI������Ă��邩�̃t���O
static int background;//�摜�p

void all_delete();//�L�^����������֐�


//�Q�[���������[�v
void record_update() {
	mouse = GetMouseInput();                //�}�E�X�̓��͏�Ԏ擾
	GetMousePoint(&mouse_x, &mouse_y);                //�}�E�X�̍��W�擾
	

	//�}�E�X��back�̏�ɂ��邩�̔���
	if (mouse_x > back_x - back_f * 10 && mouse_x < back_x + back_f * 10 + back_x_size && mouse_y > back_y - back_f * 10 && mouse_y < back_y + back_f * 10 + back_y_size)
		back_f = 1;
	else
		back_f = 0;

	//�}�E�X��delete�̏�ɂ��邩�̔���
	if (mouse_x > delete_x - delete_f * 10 && mouse_x < delete_x + delete_f * 10 + delete_x_size && mouse_y > delete_y - delete_f * 10 && mouse_y < delete_y + delete_f * 10 + delete_y_size)
		delete_f = 1;
	else
		delete_f = 0;


	if (mouse & MOUSE_INPUT_LEFT) { //�}�E�X�̍��{�^����������Ă�����
		if (back_f == 1)
			Game_Scene = 0;
		if (delete_f == 1)
			all_delete();
	}
}

//�`�揈��
void record_draw() {
	DrawGraph(0, 0, background, TRUE); //�摜�̕`��

	 //�����`��
	DrawStringToHandle(100, 50, "Record", GetColor(255, 255, 255), font[1]);
	DrawStringToHandle(delete_x - delete_f * 10, delete_y - delete_f * 10, "delete", GetColor(255, 255, 255), font[delete_f]);
	DrawStringToHandle(back_x - back_f * 10, back_y - back_f * 10, "back", GetColor(255, 255, 255), font[back_f]);
	
	
	int i;
	for (i = 0; i < RECORD_N; i++) {//�����`��
		if(record[i] != -1)	
			DrawStringToHandle(100, 130 + i * 50, record_char[i], GetColor(255, 255, 255), font[1]);
		DrawStringToHandle(100, 130 + i * 50, number[i], GetColor(255, 255, 255), font[1]);
	}
}


//�������֐�
void record_initialize() {
	fonttype = "Segoe Script";
	
	font[1] = CreateFontToHandle(fonttype, 50, 3, DX_FONTTYPE_ANTIALIASING_EDGE);//�t�H���g������
	if (font[1] == -1) {
		printf("not find "+ *fonttype);
		///exit(-1);
	}


	font[0] = CreateFontToHandle(fonttype, 30, 3, DX_FONTTYPE_ANTIALIASING_EDGE);//�t�H���g������
	if (font[0] == -1) {
		printf("not find " + *fonttype);
		///exit(-1);
	}

	save_load();//�L�^�̃��[�h

	int i;
	for (i = 0; i < RECORD_N; i++) {//�����𕶎��ɕϊ�
		sprintf(record_char[i], "     %d", record[i]);
		sprintf(number[i], "%d", i + 1);
	}

	background = LoadGraph("img/mati2.jpg");//�摜���[�h
	if (background == -1) {
		printf("not find mati1.jpg");
		///exit(-1);
	}

}


//�Q�[�������̏I���֐�
void record_finalize() {

}

//�L�^����������֐�
void all_delete() {
	int i;
	for (i = 0; i < RECORD_N; i++) {
		record[i] = -1;
	}
}