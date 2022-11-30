#include "Defines.h"

clock_t startTime, endTime, startGroundTime; // time.h에 정의된 구조체를 사용하여 변수 선언
RECT blockSize; // windows.h에 정의된 구조체를 사용하여 변수 선언
int x = 8, y = 0;
int blockForm;
int blockChange = 0;
bool gameOver = false;

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
					else {
						// 천장일 경우 0
						space[i - j][x] = 0;

					}
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
	Sleep(800);
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
