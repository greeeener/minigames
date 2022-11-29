#define LEFT 75
#define RIGHT 77
#define SPACEBAR 32
#define DOWN 80
#include <stdio.h>
#include <windows.h> 
#include <conio.h>
#include <time.h> 
#include<stdbool.h>


clock_t startTime, endTime, startGroundTime; // time.h에 정의된 구조체를 사용하여 변수 선언
RECT blockSize; // windows.h에 정의된 구조체를 사용하여 변수 선언
int x = 8, y = 0;
int blockForm;
int blockChange = 0;

// 세로11 + 1칸 수, 가로10 + 2칸 수
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
	{ // +블럭 
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
	{   // 네모블럭 
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
	{   // l자 블럭
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
	{ // T블럭
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
	{    // 번개 블럭
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
	{   // 번개 블럭 반대
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
	{   // L블럭 
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
	{   // L블럭 반대 
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

// 하얀색 커서의 깜빡임을 없애주는 함수
void RemoveCursor() {
	CONSOLE_CURSOR_INFO cursorInfo;
	cursorInfo.dwSize = TRUE;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}
// 커서좌표를 나타내는 함수
void gotoxy(int x, int y) {
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
// 충돌 감지 함수
bool CheckCrash(int x, int y) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (block[blockForm][blockChange][i][j] == 1) {
				int a = space[i + y][j + x / 2];
				if (a == 1 || a == 2) { // 벽일 때, 블럭일 때
					return true;
				}
			}
		}
	}
	return false;
}
// 블럭형태 랜덤 함수
void RandomBlock() {
	blockForm = rand() % 8;
}
//블럭이 내려가는 시간 함수
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
//블럭이 땅에 닿아서 땅으로 변하는 함수
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
// 블럭 제거 함수
void RemoveBlock() {
	for (int i = 11; i >= 0; i--) { // 벽라인 제외한 값
		int cnt = 0;
		for (int j = 1; j < 11; j++) { // 
			if (space[i][j] == 2) {
				cnt++;
			}
		}
		if (cnt >= 10) { // 벽돌이 다 찬 경우
			for (int j = 0; i - j >= 0; j++) {
				for (int x = 1; x < 11; x++) {
					if (i - j - 1 >= 0)
						space[i - j][x] = space[i - j - 1][x];
					else      // 천장일 경우 0
						space[i - j][x] = 0;
				}
			}
		}
	}
}
// 게임 화면 부분과 쌓인 블럭을 그리는 함수
void DrawMap() {
	gotoxy(0, 0);
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			if (space[i][j] == 1) {
				gotoxy(j * 2, i);
				printf("□");
			}
			else if (space[i][j] == 2) {
				gotoxy(j * 2, i);
				printf("■");
			}
		}
	}
}
// 현재 블럭 그리는 함수
void DrawBlock() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (block[blockForm][blockChange][i][j] == 1) {
				gotoxy(x + j * 2, y + i);
				printf("■");
			}
		}
	}
}
// 키를 이용해 게임을 진행하는 함수
void Key() {
	if (_kbhit() && CheckCrash(x, y + 1) == false) {
		int key = _getch();
		switch (key) {
		case SPACEBAR: // 블럭의 모양을 변화시킴
			blockChange++;
			if (blockChange >= 4)
				blockChange = 0;
			startGroundTime = clock();
			break;
		case LEFT: // 왼쪽으로 블럭을 움직임
			if (CheckCrash(x - 2, y) == false) {
				x -= 2;
				startGroundTime = clock();
			}
			break;
		case RIGHT: // 오른쪽으로 블럭을 움직임
			if (CheckCrash(x + 2, y) == false) {
				x += 2;
				startGroundTime = clock();
			}
			break;
		case DOWN: // 아래로 빠르게 블럭을 내림
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

	system("mode con:cols=25 lines=12"); // 콘솔창의 크기 변화

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
