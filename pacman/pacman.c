#include "Defines.h"

Player player;
Enemy e1; //enemy(39, 22);
Enemy e2; //enemy(51, 19);
Enemy e3; //enemy(65, 20);
Enemy e4; //enemy(81, 13);


int pm_score = 0;

void pacman() {

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

	while (1) {
		update(map);

		/*
		int xy = getch();

		if (xy != NULL) {
			moveplayer(map, player, xy);
			xy = NULL;
		}
		else
			continue;
			*/

	}

}

void startPacman() {
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

void drawmap(int(*map)[34]) {

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
				printf("£ª");
			}
			else if (map[i][j] == 1) {
				textcolor(7);
				printf("¡á");
			}
			else if (map[i][j] == 2) {
				textcolor(7);
				printf("¡á");
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

void initplayer() {
	player.pos.x = 27;
	player.pos.y = 19;
	int X = 27, Y = 19;
	textcolor(14);
	gotoxy(X, Y);
	printf("¡Ü");
}

void moveplayer(int(*map)[34], Player p, int xy) {

	bool check = true;

	textcolor(14);
	gotoxy(p.pos.x, p.pos.y);
	printf("  ");

	switch (xy) {
	case UP:
		p.pos.y--;
		check = block(map, p.pos.x, p.pos.y);
		if (check == true)
			p.pos.y += 1;
		break;

	case DOWN:
		p.pos.y += 1;
		check = block(map, p.pos.x, p.pos.y);
		if (check == true)
			p.pos.y -= 1;
		break;

	case LEFT:
		p.pos.x -= 2;
		check = block(map, p.pos.x, p.pos.y);
		if (check == true)
			p.pos.x += 2;
		break;

	case RIGHT:
		p.pos.x += 2;
		check = block(map, p.pos.x, p.pos.y);
		if (check == true)
			p.pos.x -= 2;
		break;
	}

	gotoxy(p.pos.x, p.pos.y);
	printf("¡Ü");
	printxy(p.pos.x, p.pos.y);
	pm_score = score(map, player, pm_score);

	if (p.pos.x == 91 && p.pos.y == 19) {
		endpacman();
	}
}

void initenemy() {
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

void drawenemy(Enemy e) {
	textcolor(12);
	gotoxy(e.pos.x, e.pos.y);
	printf("¡ã");
}

void moveenemy(Enemy *e, int(*map)[34]) {
	gotoxy((*e).pos.x, (*e).pos.y);

	int n = *(*(map + (*e).pos.y) + (*e).pos.x);
	int randnum = 0;
	bool check = true;
	bool isUpEmpty = false; //0
	bool isDownEmpty = false; //1
	bool isLeftEmpty = false; //2
	bool isRightEmpty = false; //3

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


	if (n == 0) {
		textcolor(6);
		printf("£ª");
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

	gotoxy((*e).pos.x, (*e).pos.y);
	textcolor(12);
	printf("¡ã");
}

void update(int(*map)[34]) {

	Enemy* ptr1 = &e1;
	Enemy* ptr2 = &e2;
	Enemy* ptr3 = &e3;
	Enemy* ptr4 = &e4;

	clock_t ct = clock();
	if (ct - e1.oldtime > e1.movetime) {
		e1.oldtime = ct;
		moveenemy(ptr1, map);
		moveenemy(ptr2, map);
		moveenemy(ptr3, map);
		moveenemy(ptr4, map);
	}

}

bool block(int(*map)[34], int x, int y) {

	bool check = true;

	y -= 9;
	int rx = (x - 25) / 2;
	
	int n = *(*(map + y) + rx);

	if (n == 1 || n == 2) //¡á
		check = true;
	else
		check = false;

	return check;
}

int score(int(*map)[34], Player p, int pm_score) {

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

void printxy(int x, int y) {
	gotoxy(0, 0);
	printf("X: %d", x);
	printf(", Y: %d", y);
}

void endpacman() {
	system("cls");
	gotoxy(55, 19);
	printf("SCORE : %d", pm_score);
}