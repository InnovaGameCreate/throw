#include "GV.h"

#define PI 3.14

static int move_img, enemy_img;
static int move_img_x1 = 0, move_img_x2 = WINDOW_WIDE;
static int move_speed = 4;
static int count = 0;
static int distance = 2000;
//ゲーム処理ループ
void result_update() {
	move_img_x1 -= move_speed;
	if (move_img_x1 <= -(WINDOW_WIDE))
		move_img_x1 = WINDOW_WIDE;
	move_img_x2 -= move_speed;
	if (move_img_x2 <= -(WINDOW_WIDE))
		move_img_x2 = WINDOW_WIDE;


	if (count < distance) {//飛距離で止める
		count += 5;
	}else{
		count = distance;
	}
}

//描画処理
void result_draw() {
	DrawGraph(move_img_x1, 0, move_img, TRUE); //画像の描画
	DrawGraph(move_img_x2, 0, move_img, TRUE); //画像の描画
	DrawFormatString(300, 150, GetColor(255, 0, 0), "%d", count);
	DrawRotaGraph(100, 200, 0.3, PI / 180 * (count % 360), enemy_img, TRUE);
}


//初期化関数
void result_initialize() {
	move_img = LoadGraph("img/mati1.jpg");//画像ロード
	if (move_img == -1) {
		printf("not find mati1.jpg");
		///exit(-1);
	}
	enemy_img = LoadGraph("img/sample.png");//画像ロード
	if (enemy_img == -1) {
		printf("not find sample.png");
		///exit(-1);
	}
}


//ゲーム処理の終了関数
void result_finalize() {

}