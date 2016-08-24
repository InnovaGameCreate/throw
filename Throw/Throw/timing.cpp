//ƒ^ƒCƒ~ƒ“ƒOƒQ[ƒW
#include "GV.h"

#define PI 3.14

static int font;//ƒtƒHƒ“ƒg—p
static char *fonttype;//ƒtƒHƒ“ƒgƒ^ƒCƒv
static double x = 0, y = 0;
static double z = 0;
static int flag = 0;
static int count = 0;
static char timing_char[64];
static int background;//‰æ‘œ—p


					
int timig_decide(); //ƒ^ƒCƒ~ƒ“ƒOŒˆ’è

//ƒQ[ƒ€ˆ—ƒ‹[ƒv
void timing_update() {
	if (flag == 0) {
		z += 0.1;
		x = cos(z);
		y = sin(z);
		timing = timig_decide();
	}
	if (Mouse[0] == 1) { // ¶ƒNƒŠƒbƒN‚ª‰Ÿ‚³‚ê‚Ä‚¢‚½‚ç
		flag = 1;                   
		//timing = timig_decide();
		//z += 0.1;
	}
	//if (Mouse[1] == 1)
	//	z -= 0.1;

	//if (timing == -2)
	//	flag = 2;

	if (flag == 1) {
		count++;
		if (count >= 100) {
			flag = 0;
			count = 0;

			Game_Scene = 4;
		}
	}

	sprintf(timing_char, "%d", timing);
}


//•`‰æˆ—
void timing_draw() {
	DrawGraph(0, 0, background, TRUE); //‰æ‘œ‚Ì•`‰æ

	DrawFormatString(300, 300, GetColor(255, 255, 255), "x:%.1f    y:%.1f    z:%.1f", x, y, z);

	DrawFormatString(300, 350, GetColor(255, 100, 0), "timing:%d", timing);

	DrawCircle(100, 100, 100, GetColor(255, 0, 0), TRUE);//‰~‚ğ•`‰æ

	DrawLine(100 * (-0.9) + 100, 100 * (-0.4) + 100, 100, 100, GetColor(255, 100, 0));//ü‚ğ•`‰æ
	DrawLine(100 * (-0.3) + 100, 100 * (-1.0) + 100, 100, 100, GetColor(255, 100, 0));//ü‚ğ•`‰æ
	DrawLine(100 * (-0.8) + 100, 100 * 0.6 + 100, 100, 100, GetColor(255, 100, 0));//ü‚ğ•`‰æ
	DrawLine(100 * (-0.1) + 100, 100 * 1.0 + 100, 100, 100, GetColor(255, 100, 0));//ü‚ğ•`‰æ
	DrawLine(100 * 0.6 + 100, 100 * (-0.8) + 100, 100, 100, GetColor(255, 100, 0));//ü‚ğ•`‰æ
	DrawLine(100 * 1.0 + 100, 100 * 0.1 + 100, 100, 100, GetColor(255, 100, 0));//ü‚ğ•`‰æ


	DrawStringToHandle(40, 20, "2", GetColor(255, 255, 255), font);
	DrawStringToHandle(90, 10, "1", GetColor(255, 255, 255), font);
	DrawStringToHandle(20, 80, "1", GetColor(255, 255, 255), font);
	DrawStringToHandle(50, 130, "0", GetColor(255, 255, 255), font);
	DrawStringToHandle(140, 50, "0", GetColor(255, 255, 255), font);
	DrawStringToHandle(110, 120, "-1", GetColor(255, 255, 255), font);



	DrawLine(100 * x + 100, 100 * y + 100, 100, 100, GetColor(255, 255, 255));//ü‚ğ•`‰æ

	DrawStringToHandle(300, 200, timing_char, GetColor(255, 255, 255), font);

}


//‰Šú‰»ŠÖ”
void timing_initialize() {
	fonttype = "Segoe Script";

	font = CreateFontToHandle(fonttype, 50, 3, DX_FONTTYPE_ANTIALIASING_EDGE);//ƒtƒHƒ“ƒg‰Šú‰»
	if (font == -1) {
		printf("not find " + *fonttype);
		///exit(-1);
	}

	background = LoadGraph("img/mati5.jpg");//‰æ‘œƒ[ƒh
	if (background == -1) {
		printf("not find mati1.jpg");
		///exit(-1);
	}
}


//ƒQ[ƒ€ˆ—‚ÌI—¹ŠÖ”
void timing_finalize() {

}


//ƒ^ƒCƒ~ƒ“ƒOŒˆ’è
int timig_decide() {
	int int_x = x * 10;
	int int_y = y * 10;
	if (int_x >= -9 && int_x <= -3 && int_y >= -10 && int_y <= -4)
		return 2;

	if (int_x >= -10 && int_x <= -8 && int_y >= -4 && int_y <= 6)
		return 1;
	if (int_x >= -3 && int_x <= 6 && int_y >= -10 && int_y <= -8)
		return 1;
	
	if (int_x >= -8 && int_x <= -1 && int_y >= 6 && int_y <= 10)
		return 0;
	if (int_x >= 6 && int_x <= 10 && int_y >= -8 && int_y <= 1)
		return 0;

	if (int_x >= -1 && int_x <= 10 && int_y >= 1 && int_y <= 10)
		return -1;
	
	return -2;
}