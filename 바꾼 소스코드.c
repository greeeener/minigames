#define LEFT 75
#define RIGHT 77
#define SPACEBAR 32
#define DOWN 80
#include <stdio.h>
#include <windows.h> 
#include <conio.h>
#include <time.h> 
#include<stdbool.h>


clock_t startTime, endTime, startGroundTime; // time.h�� ���ǵ� ����ü�� ����Ͽ� ���� ����
RECT blockSize; // windows.h�� ���ǵ� ����ü�� ����Ͽ� ���� ����
int x = 8, y = 0;
int blockForm;
int blockChange = 0;

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

// �Ͼ�� Ŀ���� �������� �����ִ� �Լ�
void RemoveCursor() {
	CONSOLE_CURSOR_INFO cursorInfo;
	cursorInfo.dwSize = TRUE;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}
// Ŀ����ǥ�� ��Ÿ���� �Լ�
void gotoxy(int x, int y) {
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
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
					else      // õ���� ��� 0
						space[i - j][x] = 0;
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
	if (system("cls"))
	{
		gotoxy(x, y + 6);
		printf("Game Over");
	}
}
int main() {

	system("mode con:cols=25 lines=12"); // �ܼ�â�� ũ�� ��ȭ

	RemoveCursor();
	startTime = clock();
	RandomBlock();

	while (1) {
		DrawMap();
		DrawBlock();
		DropBlockTime();
		BlockMeetGround();
		RemoveBlock();
		Key();

	}

	return 0;
}
