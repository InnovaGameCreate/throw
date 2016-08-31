#include "GV.h"

/*マウス操作に関するファイル*/
/*
使用例
ループ内
gpUpdateMouse();　　　　　　　　宣言

if (Mouse[0] == 1) {			左クリックが押された瞬間
	flag = 2;					フラグを2に変える
}
*/

int mouse_x, mouse_y, mouse;//マウスに関する情報格納用

int Mouse[8]; // 左クリックが押されているフレーム数を格納する


int gpUpdateMouse() {// 左クリックの入力状態を更新する

	mouse = GetMouseInput();                //マウスの入力状態取得
	GetMousePoint(&mouse_x, &mouse_y);      //マウスの座標取得

	int tmpMouse[8]; // 現在のキーの入力状態を格納する

	tmpMouse[0] = mouse & MOUSE_INPUT_LEFT;
	tmpMouse[1] = mouse & MOUSE_INPUT_RIGHT;
	tmpMouse[2] = mouse & MOUSE_INPUT_MIDDLE;
	tmpMouse[3] = mouse & MOUSE_INPUT_4;
	tmpMouse[4] = mouse & MOUSE_INPUT_5;
	tmpMouse[5] = mouse & MOUSE_INPUT_6;
	tmpMouse[6] = mouse & MOUSE_INPUT_7;
	tmpMouse[7] = mouse & MOUSE_INPUT_8;

	for (int i = 0; i<8; i++){

	if (tmpMouse[i] != 0) {//ボタンが押されているとき
		Mouse[i]++;     // 加算
	}
	else {              // 押されていなければ
		Mouse[i] = 0;   // 0にする
	}
}
return 0;
}