#include "GV.h"

#define PI 3.14

static int font[3];//�t�H���g�p
static char *fonttype; //�t�H���g�^�C�v
static char *fonttype2; //�t�H���g�^�C�v�Q
static char draw_distance[10];
static int move_img, great_img, miss_img;//�摜�p
static int move_img_x1 = 0, move_img_x2 = WINDOW_WIDE;//�w�i�̈ړ��p
static int move_speed = 4;//�w�i�̓�������
static int count = 0;//�ǂꂾ����������
static int distance = -1;//�����鋗���i�|�P�̎��͖��v�Z�j
static int result_scene = 0;
static char distance_char[64];

int enemy_img, hera_img;

int decide_distance();//�����鋗�����v�Z

static int place_x = 260;//������x���W
static int start_y = 250, start_x_size = 150, start_y_size = 30;//start�̍��W
static int record_y = 310, record_x_size = 150, record_y_size = 30; //record�̍��W
static int close_y = 370, close_x_size = 150, close_y_size = 30;//close�̍��W
static int start_f = 0, record_f = 0, close_f = 0;//�}�E�X�őI������Ă��邩�̃t���O



//�Q�[���������[�v
void result_update() {
	if (distance == -1) {
		distance = decide_distance();//�����鋗�����v�Z
		ranking(distance);//�V�����L�^�������L���O�ɑ}��
		save_output();//�Z�[�u
		create_char();

		if (distance < 0) {
			move_img_x2 = -(WINDOW_WIDE);
		}

	}
	//�w�i�̈ړ�
	if (distance >= 0) {
		move_img_x1 -= move_speed;
		if (move_img_x1 <= -(WINDOW_WIDE))
			move_img_x1 = WINDOW_WIDE;
		move_img_x2 -= move_speed;
		if (move_img_x2 <= -(WINDOW_WIDE))
			move_img_x2 = WINDOW_WIDE;
	}
	else {
		move_img_x1 += move_speed;
		if (move_img_x1 >= WINDOW_WIDE)
			move_img_x1 = 0;
		move_img_x2 += move_speed;
		if (move_img_x2 >= WINDOW_WIDE)
			move_img_x2 = 0;
	}

	if(distance >= 0 && count < distance){
			count += 5;
	}
	else if (distance < 0 && count > distance) {
		count -= 5;
	}
	else{
		if (count != distance) {
			start_music(2);

			count = distance;
		}
		sprintf(draw_distance, "%dm", distance);

		//�}�E�X��start�̏�ɂ��邩�̔���
		if (mouse_x > place_x - start_f * 10 && mouse_x < place_x + start_f * 10 + start_x_size && mouse_y > start_y - start_f * 10 && mouse_y < start_y + start_f * 10 + start_y_size)
			start_f = 1;
		else
			start_f = 0;

		//�}�E�X��record�̏�ɂ��邩�̔���
		if (mouse_x > place_x - record_f * 10 && mouse_x < place_x + record_f * 10 + record_x_size && mouse_y > record_y - record_f * 10 && mouse_y < record_y + record_f * 10 + record_y_size)
			record_f = 1;
		else
			record_f = 0;

		//�}�E�X��close�̏�ɂ��邩�̔���
		if (mouse_x > place_x - close_f * 10 && mouse_x < place_x + close_f * 10 + close_x_size && mouse_y > close_y - close_f * 10 && mouse_y < close_y + close_f * 10 + close_y_size)
			close_f = 1;
		else
			close_f = 0;

		if (Mouse[0] == 1) { //�}�E�X�̍��{�^����������Ă�����
			if (start_f == 1) {
				Game_Scene = 1;
				distance = -1;
				result_scene = 0;
				count = 0;
				move_img_x1 = 0;
				move_img_x2 = WINDOW_WIDE;
			}
			if (record_f == 1)
				Game_Scene = 5;
			if (close_f == 1)
				game_loop = 1;
		}


		if (distance >= 0)
			result_scene = 1;//����
		else
			result_scene = 2;//���s
	}
	sprintf(distance_char, "%d", count);

}

void restart() {
	distance = -1;
	result_scene = 0;
	count = 0;
	move_img_x1 = 0;
	move_img_x2 = WINDOW_WIDE;
}

//�`�揈��
void result_draw() {
	if (result_scene == 0) {
		DrawGraph(move_img_x1, 0, move_img, TRUE); //�摜�̕`��
		DrawGraph(move_img_x2, 0, move_img, TRUE); //�摜�̕`��

		DrawStringToHandle(350, 150, distance_char, GetColor(255, 255, 255), font[2]);

		DrawRotaGraph(100, 200, 0.3, PI / 180 * (count % 360), enemy_img, TRUE);//�G


	}
	else if (result_scene == 1) {
		DrawGraph(0, 0, great_img, TRUE); //�摜�̕`��
		DrawStringToHandle(100, 50, "�����I", GetColor(255, 255, 255), font[2]);
		DrawStringToHandle(320, 50, draw_distance, GetColor(255, 255, 255), font[2]);

		DrawStringToHandle(place_x - start_f * 10, start_y - start_f * 10, "restart", GetColor(255, 255, 255), font[start_f]);
		DrawStringToHandle(place_x - record_f * 10, record_y - record_f * 10, "record", GetColor(255, 255, 255), font[record_f]);
		DrawStringToHandle(place_x - close_f * 10, close_y - close_f * 10, "close", GetColor(255, 255, 255), font[close_f]);
	}
	else if (result_scene == 2) {
		DrawGraph(0, 0, miss_img, TRUE); //�摜�̕`��
		DrawStringToHandle(100, 50, "���s...", GetColor(255, 255, 255), font[2]);
		DrawStringToHandle(350, 50, draw_distance, GetColor(255, 255, 255), font[2]);

		DrawStringToHandle(place_x - start_f * 10, start_y - start_f * 10, "restart", GetColor(255, 255, 255), font[start_f]);
		DrawStringToHandle(place_x - record_f * 10, record_y - record_f * 10, "record", GetColor(255, 255, 255), font[record_f]);
		DrawStringToHandle(place_x - close_f * 10, close_y - close_f * 10, "close", GetColor(255, 255, 255), font[close_f]);
	}


}


//�������֐�
void result_initialize() {
	move_img = LoadGraph("img/mati1.jpg");//�摜���[�h
	if (move_img == -1) {
		printf("not find mati1.jpg");
		exit(-1);
	}
	enemy_img = LoadGraph("img/enemy.png");//�摜���[�h
	if (enemy_img == -1) {
		printf("not find sample.png");
		exit(-1);
	}
	great_img = LoadGraph("img/mati3.jpg");//�摜���[�h
	if (great_img == -1) {
		printf("not find mati4.jpg");
		exit(-1);
	}

	miss_img = LoadGraph("img/miss.jpg");//�摜���[�h
	if (miss_img == -1) {
		printf("not find miss.jpg");
		exit(-1);
	}

	hera_img = LoadGraph("img/hera.png");//�摜���[�h
	if (hera_img == -1) {
		printf("not find hera.png");
		exit(-1);
	}

	fonttype = "MS �S�V�b�N";// "Segoe Script";

	font[2] = CreateFontToHandle(fonttype, 50, 3, DX_FONTTYPE_ANTIALIASING_EDGE);//�t�H���g������
	if (font[2] == -1) {
		printf("not find " + *fonttype);
		exit(-1);
	}

	fonttype2 = "Segoe Script";

	font[1] = CreateFontToHandle(fonttype2, 50, 3, DX_FONTTYPE_ANTIALIASING_EDGE);//�t�H���g������
	if (font[0] == -1) {
		printf("not find " + *fonttype2);
		exit(-1);
	}

	font[0] = CreateFontToHandle(fonttype2, 30, 3, DX_FONTTYPE_ANTIALIASING_EDGE);//�t�H���g������
	if (font[1] == -1) {
		printf("not find " + *fonttype2);
		exit(-1);
	}
}


//�Q�[�������̏I���֐�
void result_finalize() {

}

//�����鋗�����v�Z
int decide_distance() {
	return (power + condition) * timing;
}



//�V�����L�^��}��
void ranking(int get) {
	int i, j;
	for (i = 0; i < RECORD_N; i++) {
		if (record[i] < get || record[i] == -1) {
			for (j = RECORD_N; j > i; j--)
				record[j] = record[j - 1];

			record[i] = get;
			break;
		}
	}
}