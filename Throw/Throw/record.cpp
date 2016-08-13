//記録
#include "GV.h"

static int font[2];//フォント用
static char *fonttype; //フォントタイプ
static char record_char[RECORD_N][64];//描画用
static char number[RECORD_N][3];//描画用
static int mouse_x, mouse_y, mouse;//マウスの情報格納用
static int delete_x = 150, delete_y = 350, delete_x_size = 180, delete_y_size = 30;//「delete」描画の座標
static int back_x = 450, back_y = 350, back_x_size = 90, back_y_size = 30;//「back」の座標
static int back_f = 0, delete_f = 0;//マウスで選択されているかのフラグ
static int background;//画像用

void all_delete();//記録を消去する関数


//ゲーム処理ループ
void record_update() {
	mouse = GetMouseInput();                //マウスの入力状態取得
	GetMousePoint(&mouse_x, &mouse_y);                //マウスの座標取得
	

	//マウスがbackの上にあるかの判定
	if (mouse_x > back_x - back_f * 10 && mouse_x < back_x + back_f * 10 + back_x_size && mouse_y > back_y - back_f * 10 && mouse_y < back_y + back_f * 10 + back_y_size)
		back_f = 1;
	else
		back_f = 0;

	//マウスがdeleteの上にあるかの判定
	if (mouse_x > delete_x - delete_f * 10 && mouse_x < delete_x + delete_f * 10 + delete_x_size && mouse_y > delete_y - delete_f * 10 && mouse_y < delete_y + delete_f * 10 + delete_y_size)
		delete_f = 1;
	else
		delete_f = 0;


	if (mouse & MOUSE_INPUT_LEFT) { //マウスの左ボタンが押されていたら
		if (back_f == 1)
			Game_Scene = 0;
		if (delete_f == 1)
			all_delete();
	}
}

//描画処理
void record_draw() {
	DrawGraph(0, 0, background, TRUE); //画像の描画

	 //文字描画
	DrawStringToHandle(100, 50, "Record", GetColor(255, 255, 255), font[1]);
	DrawStringToHandle(delete_x - delete_f * 10, delete_y - delete_f * 10, "delete", GetColor(255, 255, 255), font[delete_f]);
	DrawStringToHandle(back_x - back_f * 10, back_y - back_f * 10, "back", GetColor(255, 255, 255), font[back_f]);
	
	
	int i;
	for (i = 0; i < RECORD_N; i++) {//数字描画
		if(record[i] != -1)	
			DrawStringToHandle(100, 130 + i * 50, record_char[i], GetColor(255, 255, 255), font[1]);
		DrawStringToHandle(100, 130 + i * 50, number[i], GetColor(255, 255, 255), font[1]);
	}
}


//初期化関数
void record_initialize() {
	fonttype = "Segoe Script";
	
	font[1] = CreateFontToHandle(fonttype, 50, 3, DX_FONTTYPE_ANTIALIASING_EDGE);//フォント初期化
	if (font[1] == -1) {
		printf("not find "+ *fonttype);
		///exit(-1);
	}


	font[0] = CreateFontToHandle(fonttype, 30, 3, DX_FONTTYPE_ANTIALIASING_EDGE);//フォント初期化
	if (font[0] == -1) {
		printf("not find " + *fonttype);
		///exit(-1);
	}

	save_load();//記録のロード

	int i;
	for (i = 0; i < RECORD_N; i++) {//数字を文字に変換
		sprintf(record_char[i], "     %d", record[i]);
		sprintf(number[i], "%d", i + 1);
	}

	background = LoadGraph("img/mati2.jpg");//画像ロード
	if (background == -1) {
		printf("not find mati1.jpg");
		///exit(-1);
	}

}


//ゲーム処理の終了関数
void record_finalize() {

}

//記録を消去する関数
void all_delete() {
	int i;
	for (i = 0; i < RECORD_N; i++) {
		record[i] = -1;
	}
}