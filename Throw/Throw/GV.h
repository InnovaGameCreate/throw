#ifndef _INCLUDE_CONDITION_
//#define _INCLUDE_CONDITION_
#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"
#include "DxLib.h"
#include "define.h"
#include "struct.h"
#include "enum.h"
#include "math.h"
#include "function.h"


/*main.cpp*/
extern int Game_Scene;

extern int record[RECORD_N];//�L�^�̒l

extern int game_loop;

extern int power;
extern int condition;
extern int timing;

/*mouse.cpp*/
extern int mouse_x, mouse_y;
extern int Mouse[8];
extern int gpUpdateMouse();

#endif