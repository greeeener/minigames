
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#define size_y 10
#define size_x 20
//상수값******************************************************************************
enum { BLK, WAL, HUM, OBS };
//전역 변수***************************************************************************
int map[size_y][size_x];
//구조체******************************************************************************
struct Coordinate
{
	int x, y;
}person;
//함수 선언***************************************************************************
int StartScreen();          //시작 화면
void mapbase();              //맵에 값 저장
void mapping();              //맵 출력
void Jump();                 //점프
void Gravity();              //주기적으로 플레이어를 밑으로 내려가게 하는 함수
void Obstacle();             //장애물
void MapMove();              //맵을 왼쪽으로 한 칸씩 밈
int Gameover();             //게임 오버 화면
void gotoxy(int x, int y);    //화면을 안 깜빡거리게
void CursorView(bool show);  //커서를 안 보이게 하기 
//***************************************************************************
void run_s() {
	int turn = 1;
	int ch, t = 0;

	srand((unsigned)time(NULL));
	CursorView(0);
	turn = StartScreen();
	if (turn == 1)
	{
		gotoxy(0, 0);
		mapbase();
		mapping();
	}

	while (turn)
	{
		if (_kbhit())
		{
			ch = _getch();
			if (ch == 'j') Jump();
		}
		if (t % 30 == 0) MapMove();
		if (t % 150 == 0) Gravity();
		if (t % 500 == 0) Obstacle();
		gotoxy(0, 0);
		mapping();
		turn = Gameover();
		t++;
	}
}
//시작 화면*****************************************************************************
int StartScreen()
{
	int select = 0, ch = 0;
	int r;

	while (1)
	{
		gotoxy(0, 0);
		if (select == 0)
		{
			printf("■■■■■■■■■■■■■■■■■■■■\n");
			printf("■       ■                    ■     ■\n");
			printf("■       ■ ■  ■ ■        ■  ■   ■\n");
			printf("■       ■ ■  ■ ■■  ■■■■     ■\n");
			printf("■   ■■     ■   ■  ■  ■■       ■\n");
			printf("■                                    ■\n");
			printf("■          ▶  Game Start            ■\n");
			printf("■                                    ■\n");
			printf("■                 Exit               ■\n");
			printf("■■■■■■■■■■■■■■■■■■■■\n");
			printf("\nⓦ : 메뉴 커서 위로 이동      ⓙ : 플레이어 점프\n\nⓢ : 메뉴 커서 아래로 이동    Enter : 메뉴 선택\n");
		}
		else if (select == 1)
		{
			printf("■■■■■■■■■■■■■■■■■■■■\n");
			printf("■       ■                    ■     ■\n");
			printf("■       ■ ■  ■ ■        ■  ■   ■\n");
			printf("■       ■ ■  ■ ■■  ■■■■     ■\n");
			printf("■   ■■     ■   ■  ■  ■■       ■\n");
			printf("■                                    ■\n");
			printf("■              Game Start            ■\n");
			printf("■                                    ■\n");
			printf("■          ▶     Exit               ■\n");
			printf("■■■■■■■■■■■■■■■■■■■■\n");
			printf("\nⓦ : 메뉴 커서 위로 이동      ⓙ : 플레이어 점프\n\nⓢ : 메뉴 커서 아래로 이동    Enter : 메뉴 선택\n");
		}
		ch = _getch();
		if (ch == 'w')
		{
			if (select == 0) select = 1;
			else select--;
		}
		else if (ch == 's')
		{
			if (select == 1) select = 0;
			else select++;
		}
		else if (ch == 13 && select == 0)
		{
			r = 1;
			break;
		}
		else if (ch == 13 && select == 1)
		{
			r = 0;
			break;
		}
	}
	return r;
}
//맵베이스********************************************************************
void mapbase()
{
	for (int i = 0; i < size_y; i++)
	{
		for (int j = 0; j < size_x; j++)
		{
			if (i == 0 || i == size_y - 1) map[i][j] = WAL;
			else if (j == 0 || j == size_x - 1) map[i][j] = WAL;
			else map[i][j] = BLK;
		}
	}
	map[size_y - 2][3] = HUM;
	person.x = 3;
	person.y = size_y - 2;
}
//맵출력********************************************************************
void mapping()
{
	for (int i = 0; i < size_y; i++)
	{
		for (int j = 0; j < size_x; j++)
		{
			if (map[i][j] == BLK) printf("  ");
			if (map[i][j] == WAL) printf("■");
			if (map[i][j] == HUM) printf("●");
			if (map[i][j] == OBS) printf("■");
		}
		printf("\n");
	}
	printf("\nⓦ : 메뉴 커서 위로 이동      ⓙ : 플레이어 점프\n\nⓢ : 메뉴 커서 아래로 이동    Enter : 메뉴 선택\n");

}
//점프********************************************************************************
void Jump()
{
	int c;

	if (map[person.y - 2][person.x] == BLK)
	{
		c = map[person.y][person.x];
		map[person.y][person.x] = map[person.y - 2][person.x];
		map[person.y - 2][person.x] = c;
		person.y-=2;
	}
}
//중력********************************************************************************
void Gravity()
{
	int c;

	if (map[person.y + 1][person.x] == BLK)
	{
		c = map[person.y][person.x];
		map[person.y][person.x] = map[person.y + 1][person.x];
		map[person.y + 1][person.x] = c;
		person.y++;
	}
}
//장애물*******************************************************************************
void Obstacle()
{
	int rad;

	rad = rand() % 3;

	if (rad == 0)
	{
		map[size_y - 2][size_x - 2] = OBS;
		map[size_y - 3][size_x - 2] = OBS;
	}
	else if (rad == 1)
	{
		map[size_y - 2][size_x - 2] = OBS;
		map[size_y - 2][size_x - 3] = OBS;
		map[size_y - 3][size_x - 2] = OBS;
		map[size_y - 3][size_x - 3] = OBS;
	}
	else if (rad == 2)
	{
		map[size_y - 2][size_x - 2] = OBS;
		map[size_y - 3][size_x - 2] = OBS;
		map[size_y - 3][size_x - 3] = OBS;
	}
}
//맵을 한 칸씩 밀기*************************************************************
void MapMove()
{
	int c;

	for (int i = 1; i < size_y - 1; i++)
	{
		for (int j = 1; j < size_x - 1; j++)
		{
			if (j == 1) map[i][j] = BLK;
			else if (map[i][j] == BLK && map[i][j - 1] != HUM)
			{
				c = map[i][j];
				map[i][j] = map[i][j - 1];
				map[i][j - 1] = c;
			}
			else if (map[i][j] == OBS)
			{
				map[i][j - 1] = OBS;
				map[i][j] = BLK;
			}
		}
	}
}
//엔딩 화면*****************************************************************************
int Gameover()
{
	int select = 0, ech = 0;
	int er = 1, eturn = 0;

	if (map[person.y][person.x] != HUM) eturn = 1;

	while (eturn)
	{
		gotoxy(0, 0);
		if (select == 0)
		{
			printf("■■■■■■■■■■■■■■■■■■■■\n");
			printf("■                                    ■\n");
			printf("■                                    ■\n");
			printf("■         ▶  Main Screen            ■\n");
			printf("■                                    ■\n");
			printf("■                Exit                ■\n");
			printf("■                                    ■\n");
			printf("■                                    ■\n");
			printf("■                                    ■\n");
			printf("■■■■■■■■■■■■■■■■■■■■\n");
			printf("\nⓦ : 메뉴 커서 위로 이동      ⓙ : 플레이어 점프\n\nⓢ : 메뉴 커서 아래로 이동    Enter : 메뉴 선택\n");
		}
		else if (select == 1)
		{
			printf("■■■■■■■■■■■■■■■■■■■■\n");
			printf("■                                    ■\n");
			printf("■                                    ■\n");
			printf("■             Main Screen            ■\n");
			printf("■                                    ■\n");
			printf("■         ▶     Exit                ■\n");
			printf("■                                    ■\n");
			printf("■                                    ■\n");
			printf("■                                    ■\n");
			printf("■■■■■■■■■■■■■■■■■■■■\n");
			printf("\nⓦ : 메뉴 커서 위로 이동      ⓙ : 플레이어 점프\n\nⓢ : 메뉴 커서 아래로 이동    Enter : 메뉴 선택\n");
		}
		ech = _getch();
		if (ech == 'w')
		{
			if (select == 0) select = 1;
			else select--;
		}
		else if (ech == 's')
		{
			if (select == 1) select = 0;
			else select++;
		}
		else if (ech == 13 && select == 0)
		{
			er = StartScreen();
			mapbase();
			break;
		}
		else if (ech == 13 && select == 1)
		{
			er = 0;
			break;
		}
	}
	return er;
}
//************************************************************************************
void gotoxy(int x, int y)
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
//커서 안 보이게 해줌*****************************************************************
void CursorView(bool show)
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}
//************************************************************************************
