#include "GV.h"
#include <stdlib.h>


FILE *file;
int record[RECORD_N];//�L�^�̒l
int i;

//�Q�[���������[�v
void save_update() {
	
}

//�`�揈��
void save_draw() {
	for (i = 0; i < RECORD_N; i++) {
		DrawFormatString(130, i * 30, GetColor(255, 255, 255), "%d", record[i]);
	}

}



//�������֐�
void save_initialize() {
	//save_load();//�L�^�̃��[�h
}


//�Q�[�������̏I���֐�
void save_finalize() {

}

//�L�^��ǂݍ��ފ֐�
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



//�L�^���o�͂���֐�
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