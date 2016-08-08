#include "GV.h"
#include <stdlib.h>


FILE *file;
int record[RECORD_N];//記録の値
int i;

//ゲーム処理ループ
void save_update() {
	
}

//描画処理
void save_draw() {
	for (i = 0; i < RECORD_N; i++) {
		DrawFormatString(130, i * 30, GetColor(255, 255, 255), "%d", record[i]);
	}

}



//初期化関数
void save_initialize() {
	//save_load();//記録のロード
}


//ゲーム処理の終了関数
void save_finalize() {

}

//記録を読み込む関数
void save_load() {
	errno_t err;
	err = fopen_s(&file, "record.txt", "rb");
	if (err){
		printf("The file 'record.txt' was not opened\n");
		exit(-1);
	}

	for (i = 0; i < RECORD_N; i++) {
		char a[60] = "23";
		fgets(a, 256, file);
		record[i] = atoi(a);
		}

	fclose(file);
}



//記録を出力する関数
void save_output() {
	errno_t err;
	err = fopen_s(&file, "record.txt", "w");
	if (err){
		printf("The file 'record.txt' was not opened\n");
		exit(-1);
	}
	for (i = 0; i < RECORD_N; i++)
		fprintf(file, "%d\n", record[i]);

	fclose(file);
}