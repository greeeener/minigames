
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <stdbool.h>
#define size_y 10
#define size_x 20

enum { BLK, WAL, HUM, OBS };

typedef struct Coordinate
{
	int x, y;
}person;

int map[size_y][size_x];


int StartScreen();          
void mapbase();              
void mapping();           
void Jump();                 
void Gravity();              
void Obstacle();          
void MapMove();              
int Gameover();             
void gotoxy(int x, int y);    
void CursorView(bool show);  
