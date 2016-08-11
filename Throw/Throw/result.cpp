#include "GV.h"

#define PI 3.14

static int move_img, enemy_img;
static int move_img_x1 = 0, move_img_x2 = WINDOW_WIDE;
static int move_speed = 4;
static int count = 0;
static int distance = 2000;
//�Q�[���������[�v
void result_update() {
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
	}
}

//�`�揈��
void result_draw() {
	DrawGraph(move_img_x1, 0, move_img, TRUE); //�摜�̕`��
	DrawGraph(move_img_x2, 0, move_img, TRUE); //�摜�̕`��
	DrawFormatString(300, 150, GetColor(255, 0, 0), "%d", count);
	DrawRotaGraph(100, 200, 0.3, PI / 180 * (count % 360), enemy_img, TRUE);
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
}


//�Q�[�������̏I���֐�
void result_finalize() {

}