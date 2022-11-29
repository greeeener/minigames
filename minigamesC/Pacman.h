#pragma once
#ifndef PACMAN_H
#define PACMAN_H

typedef enum {
	false, true
} bool;

typedef struct Position {
	int x, y;
}Position;

typedef struct Player {
	Position pos;
}Player;

typedef struct Enemy {
	Position pos;
	clock_t movetime;
	clock_t oldtime;
}Enemy;

void pacman();
void startPacman();
void drawmap(int(*map)[34]);
void initplayer();
void moveplayer(int(*map)[34], Player* p, int xy);
void initenemy();
void drawenemy(Enemy e);
void moveenemy(Enemy* e, int(*map)[34]);
void update(int(*map)[34]);

bool block(int(*map)[34], int x, int y);
int score(int(*map)[34], Player p, int score);
void printxy(int x, int y);
void endpacman();
//void init_pacman();


#endif