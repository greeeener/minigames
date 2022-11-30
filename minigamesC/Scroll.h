#pragma once

#ifndef SCROLL_H
#define SCROLL_H

#define size_y 10
#define size_x 20

//�����******************************************************************************
enum { BLK, WAL, HUM, OBS };

//���� ����***************************************************************************
int map[size_y][size_x];

//����ü******************************************************************************
struct Coordinate
{
	int x, y;
}person;

//�Լ� ����***************************************************************************
int StartScreen();          //���� ȭ��
void mapbase();              //�ʿ� �� ����
void mapping();              //�� ���
void Jump();                 //����
void Gravity();              //�ֱ������� �÷��̾ ������ �������� �ϴ� �Լ�
void Obstacle();             //��ֹ�
void MapMove();              //���� �������� �� ĭ�� ��
int Gameover(int* t);             //���� ���� ȭ��
void run_s();



#endif