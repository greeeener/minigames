#include "Defines.h"

Player player;
Enemy e1; //enemy(39, 22);
Enemy e2; //enemy(51, 19);
Enemy e3; //enemy(65, 20);
Enemy e4; //enemy(81, 13);

int pm_score = 0;

void pacman() { //팩맨 실행

	startPacman();
	Sleep(1000);
	system("cls");

	int map[21][34] = {
		{9,9,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,9,9},
		{9,9,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,1,1,9,9},
		{9,9,1,0,2,2,2,2,2,2,2,0,0,1,0,0,2,2,0,0,1,1,0,0,2,2,2,2,2,0,0,1,9,9},
		{9,9,1,0,2,2,0,0,3,0,2,2,0,0,0,2,2,0,2,0,0,0,0,2,2,0,0,0,2,2,0,1,9,9},
		{9,9,1,0,2,2,0,0,0,0,2,2,0,0,2,2,0,4,0,2,0,0,2,2,0,0,1,0,0,2,0,1,9,9},
		{9,9,1,0,2,2,0,2,2,2,2,0,0,2,2,2,2,0,2,2,2,0,2,2,5,1,1,1,0,0,0,1,9,9},
		{9,9,1,0,2,2,0,0,0,0,0,0,0,2,2,0,0,0,0,2,2,0,2,2,0,0,1,0,0,2,0,1,9,9},
		{9,9,1,0,2,2,0,0,1,1,1,0,0,2,2,0,1,1,0,2,2,0,0,2,2,0,0,0,2,2,0,1,9,9},
		{9,9,1,0,2,2,0,1,0,0,0,1,0,2,2,0,0,1,0,2,2,0,0,0,2,2,2,2,2,0,0,1,9,9},
		{1,1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,1,1},
		{1,9,9,0,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,0,1,0,1,1,1,0,0,1,1,1,0,9,9,9},
		{1,1,1,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,1,0,0,0,0,1,1,0,0,0,0,0,1,1,1},
		{9,9,1,0,2,2,0,0,0,0,2,2,0,1,0,0,2,2,0,0,1,0,2,0,0,1,1,0,2,2,0,1,9,9},
		{9,9,1,0,2,2,2,0,0,2,2,2,0,0,0,2,2,0,2,0,0,0,2,2,0,0,1,0,2,2,0,1,9,9},
		{9,9,1,0,2,2,2,2,2,2,2,2,0,0,2,2,7,0,0,2,0,0,2,2,2,0,0,0,2,2,0,1,9,9},
		{9,9,1,0,2,2,0,2,2,6,2,2,0,2,2,2,2,0,2,2,2,0,2,2,0,2,0,0,2,2,0,1,9,9},
		{9,9,1,0,2,2,0,0,0,0,2,2,0,2,2,0,0,0,0,2,2,0,2,2,0,8,2,0,2,2,0,1,9,9},
		{9,9,1,0,2,2,0,1,1,0,2,2,0,2,2,0,1,1,0,2,2,0,2,2,0,0,0,2,2,2,0,1,9,9},
		{9,9,1,0,2,2,0,1,1,0,2,2,0,2,2,0,1,1,0,2,2,0,2,2,0,1,0,0,2,2,0,1,9,9},
		{9,9,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,9,9},
		{9,9,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,9,9}
	};

	drawmap(map);
	initenemy();
	initplayer();

	int xy;
	Player* pp = &player;

	while (1) {
#if 1
		if (player.pos.x == 91 && player.pos.y == 19
			|| player.pos.x == e1.pos.x && player.pos.y == e1.pos.y
			|| player.pos.x == e2.pos.x && player.pos.y == e2.pos.y
			|| player.pos.x == e3.pos.x && player.pos.y == e3.pos.y
			|| player.pos.x == e4.pos.x && player.pos.y == e4.pos.y) {
			endpacman();
			break;
		}
#endif

		update(map);

		if (kbhit()) {
			int xy = getch();
			moveplayer(map, pp, xy);
		}
		else
			continue;

		Sleep(10);

	}

}

void startPacman() { //팩맨 시작화면
	textcolor(15);
	gotoxy(40, 17);
	printf("####     #     ####  #   #    #    #   # \n");
	gotoxy(40, 18);
	printf("#   #   # #   #      ## ##   # #   ##  # \n");
	gotoxy(40, 19);
	printf("####   #####  #      # # #  #####  # # # \n");
	gotoxy(40, 20);
	printf("#      #   #  #      #   #  #   #  #  ## \n");
	gotoxy(40, 21);
	printf("#      #   #   ####  #   #  #   #  #   # \n");
}

void drawmap(int(*map)[34]) { //맵 그리기 함수

	gotoxy(30, 7);
	textcolor(8);
	printf("P A C M A N ");

	textcolor(15);
	gotoxy(76, 7);
	printf("SCORE:");
	gotoxy(83, 7);
	printf("%d", pm_score);

	int j = 0;
	int k = 0;

	for (int i = 0; i < 21; i++) {
		gotoxy(25, 9 + i);
		while (k < 68) {
			gotoxy(25 + k, 9 + i);
			if (map[i][j] == 0) {
				textcolor(6);
				printf("＊");
			}
			else if (map[i][j] == 1 || map[i][j] == 2) {
				textnbackcolor(7,7);
				printf("■");
			}
			else if (map[i][j] == 3) {
				textcolor(9);
				printf("P ");
			}
			else if (map[i][j] == 4) {
				textcolor(12);
				printf("A ");
			}
			else if (map[i][j] == 5) {
				textcolor(2);
				printf("C ");
			}
			else if (map[i][j] == 6) {
				textcolor(11);
				printf("M ");
			}
			else if (map[i][j] == 7) {
				textcolor(10);
				printf("A ");
			}
			else if (map[i][j] == 8) {
				textcolor(13);
				printf("N ");
			}
			k += 2;
			j++;
		}
		j = 0;
		k = 0;
		printf("\n");
	}

	textcolor(15);
	gotoxy(88, 19);
	printf("EXIT");
}

void initplayer() { //플레이어 초기 위치 설정
	player.pos.x = 27;
	player.pos.y = 19;
	int X = 27, Y = 19;
	textcolor(14);
	gotoxy(X, Y);
	printf("●");
	pm_score = 0;
}

void moveplayer(int(*map)[34], Player *p, int xy) { //플레이어 이동

	bool check = true;

	textcolor(14);
	gotoxy((*p).pos.x, (*p).pos.y);
	printf("  ");

	switch (xy) {
	case UP:
		(*p).pos.y--;
		check = block(map, (*p).pos.x, (*p).pos.y);
		if (check == true)
			(*p).pos.y += 1;
		break;

	case DOWN:
		(*p).pos.y += 1;
		check = block(map, (*p).pos.x, (*p).pos.y);
		if (check == true)
			(*p).pos.y -= 1;
		break;

	case LEFT:
		(*p).pos.x -= 2;
		check = block(map, (*p).pos.x, (*p).pos.y);
		if (check == true)
			(*p).pos.x += 2;
		break;

	case RIGHT:
		(*p).pos.x += 2;
		check = block(map, (*p).pos.x, (*p).pos.y);
		if (check == true)
			(*p).pos.x -= 2;
		break;
	}

	gotoxy((*p).pos.x, (*p).pos.y);
	printf("●");
	printxy((*p).pos.x, (*p).pos.y);
	pm_score = score(map, player, pm_score);
}

void initenemy() { //적 초기 위치 설정
	e1.pos.x = 39;
	e1.pos.y = 22;
	e2.pos.x = 51;
	e2.pos.y = 19;
	e3.pos.x = 65;
	e3.pos.y = 20;
	e4.pos.x = 81;
	e4.pos.y = 13;
	e1.movetime = 200;
	e1.oldtime = clock();
	drawenemy(e1);
	drawenemy(e2);
	drawenemy(e3);
	drawenemy(e4);
}

void drawenemy(Enemy e) { //적 그리기
	textcolor(12);
	gotoxy(e.pos.x, e.pos.y);
	printf("▲");
}

void moveenemy(Enemy *e, int(*map)[34]) { //적 이동 (랜덤 방향)
	gotoxy((*e).pos.x, (*e).pos.y);

	int randnum = 0;
	bool check = true;
	bool isUpEmpty = false; //0
	bool isDownEmpty = false; //1
	bool isLeftEmpty = false; //2
	bool isRightEmpty = false; //3

	int y = (*e).pos.y - 9;
	int x = ((*e).pos.x - 25) / 2;

	int n = *(*(map + y) + x);

	if (n == 0) {
		textcolor(6);
		printf("＊");
	}
	else if (n == 3) {
		textcolor(9);
		printf("P ");
	}
	else if (n == 4) {
		textcolor(12);
		printf("A ");
	}
	else if (n == 5) {
		textcolor(2);
		printf("C ");
	}
	else if (n == 6) {
		textcolor(11);
		printf("M ");
	}
	else if (n == 7) {
		textcolor(10);
		printf("A ");
	}
	else if (n == 8) {
		textcolor(13);
		printf("N ");
	}
	else {
		printf("  ");
	}

	do {
		randnum = rand() % 4;

		if (randnum == 0) {
			check = block(map, (*e).pos.x, (*e).pos.y - 1);
			if (check == false) {
				isUpEmpty = true;
				(*e).pos.y--;
			}	
		}
		else if (randnum == 1) {
			check = block(map, (*e).pos.x, (*e).pos.y + 1);
			if (check == false) {
				isDownEmpty = true;
				(*e).pos.y++;
			}
		}
		else if (randnum == 2) {
			check = block(map, (*e).pos.x - 2, (*e).pos.y);
			if (check == false) {
				isLeftEmpty = true;
				(*e).pos.x -= 2;
			}
		}
		else if (randnum == 3) {
			check = block(map, (*e).pos.x + 2, (*e).pos.y);
			if (check == false) {
				isRightEmpty = true;
				(*e).pos.x += 2;
			}
		}

	} while (isUpEmpty == false && isDownEmpty == false && isLeftEmpty == false && isRightEmpty == false);


	gotoxy((*e).pos.x, (*e).pos.y);
	textcolor(12);
	printf("▲");
}

void update(int(*map)[34]) { //적 위치 업데이트

	Enemy* ptr1 = &e1;
	Enemy* ptr2 = &e2;
	Enemy* ptr3 = &e3;
	Enemy* ptr4 = &e4;

	clock_t ct = clock();
	if (ct - e1.oldtime > e1.movetime) {
		e1.oldtime = ct;
		moveenemy(ptr1, map);
		Sleep(10);
		moveenemy(ptr2, map);
		Sleep(10);
		moveenemy(ptr3, map);
		Sleep(10);
		moveenemy(ptr4, map);
		Sleep(10);
	}

}

bool block(int(*map)[34], int x, int y) { //벽인지 확인

	bool check = true;

	y -= 9;
	int rx = (x - 25) / 2;
	
	int n = *(*(map + y) + rx);

	if (n == 1 || n == 2) //■
		check = true;
	else
		check = false;

	return check;
}

int score(int(*map)[34], Player p, int pm_score) { //점수 계산

	p.pos.y -= 9;
	p.pos.x = (p.pos.x - 25) / 2;

	int check = 1;
	int n = *(*(map + p.pos.y) + p.pos.x);

	if (n == 0) {
		pm_score += 10;
		*(*(map + p.pos.y) + p.pos.x) = 10;
	}
	else if (n >= 3 && n <=8) { //P
		pm_score += 100;
		*(*(map + p.pos.y) + p.pos.x) = 10;

		if (n == 3) { //P
			gotoxy(30, 7);
			textcolor(9);
			printf("P");
		}
		else if (n == 4) { //A
			gotoxy(32, 7);
			textcolor(12);
			printf("A");
		}
		else if (n == 5) { //C
			gotoxy(34, 7);
			textcolor(2);
			printf("C");
		}
		else if (n == 6) { //M
			gotoxy(36, 7);
			textcolor(11);
			printf("M");
		}
		else if (n == 7) { //A
			gotoxy(38, 7);
			textcolor(10);
			printf("A");
		}
		else if (n == 8) { //N
			gotoxy(40, 7);
			textcolor(13);
			printf("N");
		}
	}

	gotoxy(83, 7);
	printf("%d", pm_score);

	return pm_score;
}

void printxy(int x, int y) { //플레이어 현재 위치 출력
	gotoxy(0, 0);
	printf("X: %d", x);
	printf(", Y: %d", y);
}

void endpacman() { //팩맨 종료 화면

	system("cls");

	textcolor(12);

	if (pm_score == 3400) {
		gotoxy(56, 13);
		printf("SUCCESS!!");
	}
	else {
		gotoxy(51, 13);
		printf("YOU CAN DO BETTER");
	}

	gotoxy(54, 15);
	printf("SCORE : %d", pm_score);
	gotoxy(52, 18);
	printf("RETRY : press 'r'");
	gotoxy(49, 19);
	printf("GO TO MAIN : press 'm'");

	int ch = getch();

	if (ch == 'r') {
		system("cls");
		pacman();
	}
	else if (ch == 'm') {
		system("cls");
		selectGamesScreen();
	}
	else {
		gotoxy(55, 22);
		printf("WRONG PRESS");
		Sleep(500);
		endpacman();
	}

}