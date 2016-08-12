#include "GV.h"

#define PI 3.14

static int move_img, enemy_img;//‰æ‘œ—p
static int move_img_x1 = 0, move_img_x2 = WINDOW_WIDE;//”wŒi‚ÌˆÚ“®—p
static int move_speed = 4;//”wŒi‚Ì“®‚­‘¬‚³
static int count = 0;//‚Ç‚ê‚¾‚¯“®‚¢‚½‚©
static int distance = -1;//“Š‚°‚é‹——£i|‚P‚Ì‚Í–¢ŒvZj


int decide_distance();//“Š‚°‚é‹——£‚ğŒvZ



//ƒQ[ƒ€ˆ—ƒ‹[ƒv
void result_update() {
	if (distance == -1)
		distance = decide_distance();//“Š‚°‚é‹——£‚ğŒvZ


	//”wŒi‚ÌˆÚ“®
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

	DrawFormatString(300, 150, GetColor(255, 0, 0), "%d", count);//‹——£
	
	DrawRotaGraph(100, 200, 0.3, PI / 180 * (count % 360), enemy_img, TRUE);//“G
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

//“Š‚°‚é‹——£‚ğŒvZ
int decide_distance() {
	int power = 20;
	int condition = 50;
	int timing = 2;

	return (power + condition) * timing;
}