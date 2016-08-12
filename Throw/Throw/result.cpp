#include "GV.h"

#define PI 3.14

static int move_img, enemy_img, great_img;//�摜�p
static int move_img_x1 = 0, move_img_x2 = WINDOW_WIDE;//�w�i�̈ړ��p
static int move_speed = 4;//�w�i�̓�������
static int count = 0;//�ǂꂾ����������
static int distance = -1;//�����鋗���i�|�P�̎��͖��v�Z�j
static int result_scene = 0;

int decide_distance();//�����鋗�����v�Z



//�Q�[���������[�v
void result_update() {
	if (distance == -1)
		distance = decide_distance();//�����鋗�����v�Z


	//�w�i�̈ړ�
	move_img_x1 -= move_speed;
	if (move_img_x1 <= -(WINDOW_WIDE))
		move_img_x1 = WINDOW_WIDE;
	move_img_x2 -= move_speed;
	if (move_img_x2 <= -(WINDOW_WIDE))
		move_img_x2 = WINDOW_WIDE;



	if (count < distance) {//�򋗗��Ŏ~�߂�
		count += 5;
	}else{
		count = distance;
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
	}
	else if (result_scene == 1) {
		DrawGraph(0, 0, great_img, TRUE); //�摜�̕`��
	}
	else if (result_scene == 2) {

	}
}


//�������֐�
void result_initialize() {
	move_img = LoadGraph("img/mati1.jpg");//�摜���[�h
	if (move_img == -1) {
		printf("not find mati1.jpg");
		///exit(-1);
	}
	enemy_img = LoadGraph("img/sample.png");//�摜���[�h
	if (enemy_img == -1) {
		printf("not find sample.png");
		///exit(-1);
	}
	great_img = LoadGraph("img/mati4.jpg");//�摜���[�h
	if (great_img == -1) {
		printf("not find mati4.jpg");
		///exit(-1);
	}
}


//�Q�[�������̏I���֐�
void result_finalize() {

}

//�����鋗�����v�Z
int decide_distance() {
	int power = 200;
	int condition = 500;
	int timing = 2;

	return (power + condition) * timing;
}