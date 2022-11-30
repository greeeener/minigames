#include "Defines.h"

clock_t startTime, endTime, startGroundTime; // time.h�� ���ǵ� ����ü�� ����Ͽ� ���� ����
RECT blockSize; // windows.h�� ���ǵ� ����ü�� ����Ͽ� ���� ����
int x = 8, y = 0;
int blockForm;
int blockChange = 0;
bool gameOver = false;

// ����11 + 1ĭ ��, ����10 + 2ĭ ��
int space[11 + 1][10 + 2] =
{
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1}
};

int block[8][4][4][4] = {
	{ // +�� 
		{
			{0,0,0,0},
			{0,1,0,0},
			{1,1,1,0},
			{0,1,0,0}
		},
		{
			{0,0,0,0},
			{0,1,0,0},
			{1,1,1,0},
			{0,1,0,0}
		},
		{
			{0,0,0,0},
			{0,1,0,0},
			{1,1,1,0},
			{0,1,0,0}
		},
		{
			{0,0,0,0},
			{0,1,0,0},
			{1,1,1,0},
			{0,1,0,0}
		}
	},
	{   // �׸�� 
		{
			{0,0,0,0},
			{0,1,1,0},
			{0,1,1,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{0,1,1,0},
			{0,1,1,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{0,1,1,0},
			{0,1,1,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{0,1,1,0},
			{0,1,1,0},
			{0,0,0,0}
		}
	},
	{   // l�� ��
		{
			{0,1,0,0},
			{0,1,0,0},
			{0,1,0,0},
			{0,1,0,0}
		},
		{
			{0,0,0,0},
			{0,0,0,0},
			{1,1,1,1},
			{0,0,0,0}
		},
		{
			{0,1,0,0},
			{0,1,0,0},
			{0,1,0,0},
			{0,1,0,0}
		},
		{
			{0,0,0,0},
			{0,0,0,0},
			{1,1,1,1},
			{0,0,0,0}
		}
	},
	{ // T��
		{
			{0,0,0,0},
			{0,1,0,0},
			{1,1,1,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{0,1,0,0},
			{0,1,1,0},
			{0,1,0,0}
		},
		{
			{0,0,0,0},
			{0,0,0,0},
			{1,1,1,0},
			{0,1,0,0}
		},
		{
			{0,0,0,0},
			{0,1,0,0},
			{1,1,0,0},
			{0,1,0,0}
		}
	},
	{    // ���� ��
		{
			{0,0,0,0},
			{0,1,1,0},
			{1,1,0,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{1,0,0,0},
			{1,1,0,0},
			{0,1,0,0}
		},
		{
			{0,0,0,0},
			{0,1,1,0},
			{1,1,0,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{1,0,0,0},
			{1,1,0,0},
			{0,1,0,0}
		}
	},
	{   // ���� �� �ݴ�
		{
			{0,0,0,0},
			{1,1,0,0},
			{0,1,1,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{0,1,0,0},
			{1,1,0,0},
			{1,0,0,0}
		},
		{
			{0,0,0,0},
			{1,1,0,0},
			{0,1,1,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{0,1,0,0},
			{1,1,0,0},
			{1,0,0,0}
		}
	},
	{   // L�� 
		{
			{0,0,0,0},
			{1,0,0,0},
			{1,1,1,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{1,1,0,0},
			{1,0,0,0},
			{1,0,0,0}
		},
		{
			{0,0,0,0},
			{1,1,1,0},
			{0,0,1,0},
			{0,0,0,0}
		},
		{
			{0,1,0,0},
			{0,1,0,0},
			{1,1,0,0},
			{0,0,0,0}
		}
	},
	{   // L�� �ݴ� 
		{
			{0,0,0,0},
			{0,0,1,0},
			{1,1,1,0},
			{0,0,0,0}
		},
		{
			{1,0,0,0},
			{1,0,0,0},
			{1,1,0,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{1,1,1,0},
			{1,0,0,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{1,1,0,0},
			{0,1,0,0},
			{0,1,0,0}
		}
	}

};

// �浹 ���� �Լ�
bool CheckCrash(int x, int y) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (block[blockForm][blockChange][i][j] == 1) {
				int a = space[i + y][j + x / 2];
				if (a == 1 || a == 2) { // ���� ��, ���� ��
					return true;
				}
			}
		}
	}
	return false;
}

// ������ ���� �Լ�
void RandomBlock() {
	blockForm = rand() % 8;
}

//���� �������� �ð� �Լ�
void DropBlockTime() {
	endTime = clock();
	if ((float)(endTime - startTime) >= 800)
	{
		if (CheckCrash(x, y + 1) == true)
			return;
		y++;
		startTime = clock();
		startGroundTime = clock();
		system("cls");
	}
}
//���� ���� ��Ƽ� ������ ���ϴ� �Լ�
void BlockMeetGround() {
	if (CheckCrash(x, y + 1) == true) {
		if ((float)(endTime - startGroundTime) > 1500)
		{
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					if (block[blockForm][blockChange][i][j] == 1) {
						space[i + y][j + x / 2] = 2;
					}
				}
			}
			x = 8;
			y = 0;
			RandomBlock();
		}
	}
}
// �� ���� �Լ�
void RemoveBlock() {
	for (int i = 11; i >= 0; i--) { // ������ ������ ��
		int cnt = 0;
		for (int j = 1; j < 11; j++) { // 
			if (space[i][j] == 2) {
				cnt++;
			}
		}
		if (cnt >= 10) { // ������ �� �� ���
			for (int j = 0; i - j >= 0; j++) {
				for (int x = 1; x < 11; x++) {
					if (i - j - 1 >= 0)
						space[i - j][x] = space[i - j - 1][x];
					else {
						// õ���� ��� 0
						space[i - j][x] = 0;

					}
				}
			}
		}
	}
}
// ���� ȭ�� �κа� ���� ���� �׸��� �Լ�
void DrawMap() {
	gotoxy(0, 0);
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			if (space[i][j] == 1) {
				gotoxy(j * 2, i);
				printf("��");
			}
			else if (space[i][j] == 2) {
				gotoxy(j * 2, i);
				printf("��");
			}
		}
	}
}
// ���� �� �׸��� �Լ�
void DrawBlock() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (block[blockForm][blockChange][i][j] == 1) {
				gotoxy(x + j * 2, y + i);
				printf("��");
			}
		}
	}
}
// Ű�� �̿��� ������ �����ϴ� �Լ�
void Key() {
	if (_kbhit() && CheckCrash(x, y + 1) == false) {
		int key = _getch();
		switch (key) {
		case SPACEBAR: // ���� ����� ��ȭ��Ŵ
			blockChange++;
			if (blockChange >= 4)
				blockChange = 0;
			startGroundTime = clock();
			break;
		case LEFT: // �������� ���� ������
			if (CheckCrash(x - 2, y) == false) {
				x -= 2;
				startGroundTime = clock();
			}
			break;
		case RIGHT: // ���������� ���� ������
			if (CheckCrash(x + 2, y) == false) {
				x += 2;
				startGroundTime = clock();
			}
			break;
		case DOWN: // �Ʒ��� ������ ���� ����
			if (CheckCrash(x, y + 1) == false)
				y++;
			startGroundTime = clock();
			break;
		}
		system("cls");
	}


}

void ShowGameOver()
{
	system("cls");

	gotoxy(x, y + 6);
	printf("Game Over");
	gotoxy(x - 2, y + 8);
	printf("RETRY : press 'r'");
	gotoxy(x - 2, y + 9);
	printf("MAIN : press 'm'");
	inittetris(space);

	int ch = _getch();
	switch (ch) {
	case 'r':
		system("cls");
		run_tetris();
	case 'm':
		system("cls");
		selectGamesScreen();
	default:
		gotoxy(x, y + 11);
		printf("WRONG PRESS");
		Sleep(500);
		printf("           ");
		ShowGameOver();
	}
}

void sizeCon() {
	system("mode con:cols=25 lines=12");
}

void run_tetris() {

	sizeCon();
	CursorView();
	startTime = clock();
	RandomBlock();

	while (gameOver == false) {
		DrawMap();
		DrawBlock();
		DropBlockTime();
		BlockMeetGround();
		RemoveBlock();
		Key();
		gameOver = checkover(space);
	}
	ShowGameOver();
}

bool checkover(int space[12][12]) {
	int n = 0;
	for (int i = 1; i < 10; i++) {
		if (space[0][i] == 2)
			return true;
	}
	return false;
}

void inittetris(int (*space)[12][12]) {

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			if (j == 0 || j == 11 || i==11)
				(*space)[i][j] = 1;
			else
				(*space)[i][j] = 0;
		}
	}
	gameOver = false;
}