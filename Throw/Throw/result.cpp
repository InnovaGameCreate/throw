#include "GV.h"

#define PI 3.14

static int font;//�t�H���g�p
static char *fonttype; //�t�H���g�^�C�v
static char draw_distance[10];
static int move_img, great_img, miss_img;//�摜�p
static int move_img_x1 = 0, move_img_x2 = WINDOW_WIDE;//�w�i�̈ړ��p
static int move_speed = 4;//�w�i�̓�������
static int count = 0;//�ǂꂾ����������
static int distance = -1;//�����鋗���i�|�P�̎��͖��v�Z�j
static int result_scene = 0;
int enemy_img, hera_img;

int decide_distance();//�����鋗�����v�Z



//�Q�[���������[�v
void result_update() {
	if (distance == -1) {
		distance = decide_distance();//�����鋗�����v�Z
		ranking(distance);//�V�����L�^�������L���O�ɑ}��
		save_output();//�Z�[�u
		if (distance < 0) {
			move_img_x2 = -(WINDOW_WIDE);
		}

	}
	//�w�i�̈ړ�
	if (distance >= 0) {
		move_img_x1 -= move_speed;
		if (move_img_x1 <= -(WINDOW_WIDE))
			move_img_x1 = WINDOW_WIDE;
		move_img_x2 -= move_speed;
		if (move_img_x2 <= -(WINDOW_WIDE))
			move_img_x2 = WINDOW_WIDE;
	}
	else {
		move_img_x1 += move_speed;
		if (move_img_x1 >= WINDOW_WIDE)
			move_img_x1 = 0;
		move_img_x2 += move_speed;
		if (move_img_x2 >= WINDOW_WIDE)
			move_img_x2 = 0;
	}

	if(distance >= 0 && count < distance){
		//if (count < distance) {//�򋗗��Ŏ~�߂�
			count += 5;
		//}/
	}
	else if (distance < 0 && count > distance) {
		count -= 5;
	}
	else{
		count = distance;
		sprintf(draw_distance, "%dm", distance);
		if (distance >= 0)
			result_scene = 1;//����
		else
			result_scene = 2;//���s
	}
}

//�`�揈��
void result_draw() {
	if (result_scene == 0) {
		DrawGraph(move_img_x1, 0, move_img, TRUE); //�摜�̕`��
		DrawGraph(move_img_x2, 0, move_img, TRUE); //�摜�̕`��

		DrawFormatString(300, 150, GetColor(255, 0, 0), "%d", count);//����

		DrawRotaGraph(100, 200, 0.3, PI / 180 * (count % 360), enemy_img, TRUE);//�G

		DrawFormatString(300, 300, GetColor(255, 0, 0), "power:%d    condition:%d    timing:%d", power, condition, timing);

	}
	else if (result_scene == 1) {
		DrawGraph(0, 0, great_img, TRUE); //�摜�̕`��
		DrawStringToHandle(100, 50, "�����I", GetColor(255, 255, 255), font);
		DrawStringToHandle(320, 50, draw_distance, GetColor(255, 255, 255), font);
	}
	else if (result_scene == 2) {
		DrawGraph(0, 0, miss_img, TRUE); //�摜�̕`��
		DrawStringToHandle(100, 50, "���s...", GetColor(255, 255, 255), font);
		DrawStringToHandle(350, 50, draw_distance, GetColor(255, 255, 255), font);
	}
}


//�������֐�
void result_initialize() {
	move_img = LoadGraph("img/mati1.jpg");//�摜���[�h
	if (move_img == -1) {
		printf("not find mati1.jpg");
		///exit(-1);
	}
	enemy_img = LoadGraph("img/enemy.png");//�摜���[�h
	if (enemy_img == -1) {
		printf("not find sample.png");
		///exit(-1);
	}
	great_img = LoadGraph("img/mati3.jpg");//�摜���[�h
	if (great_img == -1) {
		printf("not find mati4.jpg");
		///exit(-1);
	}

	miss_img = LoadGraph("img/miss.jpg");//�摜���[�h
	if (miss_img == -1) {
		printf("not find miss.jpg");
		///exit(-1);
	}

	hera_img = LoadGraph("img/hera.png");//�摜���[�h
	if (hera_img == -1) {
		printf("not find hera.png");
		///exit(-1);
	}

	fonttype = "MS �S�V�b�N";// "Segoe Script";

	font = CreateFontToHandle(fonttype, 50, 3, DX_FONTTYPE_ANTIALIASING_EDGE);//�t�H���g������
	if (font == -1) {
		printf("not find " + *fonttype);
		///exit(-1);
	}
}


//�Q�[�������̏I���֐�
void result_finalize() {

}

//�����鋗�����v�Z
int decide_distance() {
	/*int power = 200;
	int condition = 500;
	int timing = -1;
	*/
	return (power + condition) * timing;
}



//�V�����L�^��}��
void ranking(int get) {
	int i, j;
	for (i = 0; i < RECORD_N; i++) {
		if (record[i] < get || record[i] == -1) {
			for (j = RECORD_N; j > i; j--)
				record[j] = record[j - 1];

			record[i] = get;
			break;
		}
	}
}