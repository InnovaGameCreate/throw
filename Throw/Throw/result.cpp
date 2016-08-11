#include "GV.h"

#define PI 3.14

static int move_img, enemy_img;
static int move_img_x1 = 0, move_img_x2 = WINDOW_WIDE;
static int move_speed = 4;
static int count = 0;
static int distance = 2000;
//ƒQ[ƒ€ˆ—ƒ‹[ƒv
void result_update() {
	move_img_x1 -= move_speed;
	if (move_img_x1 <= -(WINDOW_WIDE))
		move_img_x1 = WINDOW_WIDE;
	move_img_x2 -= move_speed;
	if (move_img_x2 <= -(WINDOW_WIDE))
		move_img_x2 = WINDOW_WIDE;


	if (count < distance) {//”ò‹——£‚Å~‚ß‚é
		count += 5;
	}else{
		count = distance;
	}
}

//•`‰æˆ—
void result_draw() {
	DrawGraph(move_img_x1, 0, move_img, TRUE); //‰æ‘œ‚Ì•`‰æ
	DrawGraph(move_img_x2, 0, move_img, TRUE); //‰æ‘œ‚Ì•`‰æ
	DrawFormatString(300, 150, GetColor(255, 0, 0), "%d", count);
	DrawRotaGraph(100, 200, 0.3, PI / 180 * (count % 360), enemy_img, TRUE);
}


//‰Šú‰»ŠÖ”
void result_initialize() {
	move_img = LoadGraph("img/mati1.jpg");//‰æ‘œƒ[ƒh
	if (move_img == -1) {
		printf("not find mati1.jpg");
		///exit(-1);
	}
	enemy_img = LoadGraph("img/sample.png");//‰æ‘œƒ[ƒh
	if (enemy_img == -1) {
		printf("not find sample.png");
		///exit(-1);
	}
}


//ƒQ[ƒ€ˆ—‚ÌI—¹ŠÖ”
void result_finalize() {

}