#pragma once

#ifndef SCROLL_H
#define SCROLL_H

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
int Gameover(int* t);             //게임 오버 화면
void run_s();



#endif