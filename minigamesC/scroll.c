#include "Defines.h"

//메인 함수***************************************************************************
void run_s() {
	int turn = 1;
	int ch, t = 0;
	int score;
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
			if (ch == 32) Jump();
		}
		if (t % 30 == 0) MapMove();
		if (t % 150 == 0) Gravity();
		if (t % 500 == 0) Obstacle();
		gotoxy(0, 0);
		mapping();
		turn = Gameover(&t);
		t++;
		score = t / 500;
		printf("\nSCORE : %d", score);
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
			printf("\nⓦ : 메뉴 커서 위로 이동      Space : 플레이어 점프\n\nⓢ : 메뉴 커서 아래로 이동    Enter : 메뉴 선택\n");
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
			printf("\nⓦ : 메뉴 커서 위로 이동      Space : 플레이어 점프\n\nⓢ : 메뉴 커서 아래로 이동    Enter : 메뉴 선택\n");
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
			system("cls");
			selectGamesScreen();
			break;
		}
	}
	return r;
}
//배열에 값을 입력********************************************************************
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
//맵을 화면에 출력********************************************************************
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
	printf("\nⓦ : 메뉴 커서 위로 이동      Space : 플레이어 점프\n\nⓢ : 메뉴 커서 아래로 이동    Enter : 메뉴 선택\n");

}
//점프********************************************************************************
void Jump()
{
	int c;

	if (map[person.y - 1][person.x] == BLK)
	{
		c = map[person.y][person.x];
		map[person.y][person.x] = map[person.y - 1][person.x];
		map[person.y - 1][person.x] = c;
		person.y --;
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
//맵 한칸씩 밀기*************************************************************
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
int Gameover(int* t)
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
			printf("■           FINAL SCORE : %d     \n", *t / 500);
			printf("■                                    ■\n");
			printf("■■■■■■■■■■■■■■■■■■■■\n");
			printf("\nⓦ : 메뉴 커서 위로 이동      Space : 플레이어 점프\n\nⓢ : 메뉴 커서 아래로 이동    Enter : 메뉴 선택\n");
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
			printf("■           FINAL SCORE : %d          \n", *t / 500);
			printf("■                                    ■\n");
			printf("■■■■■■■■■■■■■■■■■■■■\n");
			printf("\nⓦ : 메뉴 커서 위로 이동      Space : 플레이어 점프\n\nⓢ : 메뉴 커서 아래로 이동    Enter : 메뉴 선택\n");
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
			*t = 0;
			break;
		}
		else if (ech == 13 && select == 1)
		{
			system("cls");
			selectGamesScreen();
			break;
		}
	}

	return er;
}
