
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
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
void Gravity();              //���� �ϰų� ���ų�, �ֱ������� �÷��̾ ������ �������� �ϴ� �Լ�(�̸��� ��հ� �߷����� �� ��)
void Obstacle();             //��ֹ�
void MapMove();              //���� �������� �� ĭ�� ��
int Gameover();             //���� ���� ȭ��
void gotoxy(int x, int y);    //ȭ���� �� �����Ÿ��� �ҷ��� �ܼ�â �� ���� �� ��� ����ϰ� �ϱ� ���� ��
void CursorView(bool show);  //Ŀ���� �� ���̰� �ϱ� ���� ��
//���� �Լ�***************************************************************************

//���� ȭ��*****************************************************************************
int StartScreen()
{
	int select = 0, ch = 0;
	int r;

	while (1)
	{
		gotoxy(0, 0);
		if (select == 0)
		{
			printf("���������������������\n");
			printf("��       ��                    ��     ��\n");
			printf("��       �� ��  �� ��        ��  ��   ��\n");
			printf("��       �� ��  �� ���  �����     ��\n");
			printf("��   ���     ��   ��  ��  ���       ��\n");
			printf("��                                    ��\n");
			printf("��          ��  Game Start            ��\n");
			printf("��                                    ��\n");
			printf("��                 Exit               ��\n");
			printf("���������������������\n");
			printf("\n�� : �޴� Ŀ�� ���� �̵�      �� : �÷��̾� ����\n\n�� : �޴� Ŀ�� �Ʒ��� �̵�    Enter : �޴� ����\n");
		}
		else if (select == 1)
		{
			printf("���������������������\n");
			printf("��       ��                    ��     ��\n");
			printf("��       �� ��  �� ��        ��  ��   ��\n");
			printf("��       �� ��  �� ���  �����     ��\n");
			printf("��   ���     ��   ��  ��  ���       ��\n");
			printf("��                                    ��\n");
			printf("��              Game Start            ��\n");
			printf("��                                    ��\n");
			printf("��          ��     Exit               ��\n");
			printf("���������������������\n");
			printf("\n�� : �޴� Ŀ�� ���� �̵�      �� : �÷��̾� ����\n\n�� : �޴� Ŀ�� �Ʒ��� �̵�    Enter : �޴� ����\n");
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
//�迭�� ���� �Է�********************************************************************
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
//���� ȭ�鿡 ���********************************************************************
void mapping()
{
	for (int i = 0; i < size_y; i++)
	{
		for (int j = 0; j < size_x; j++)
		{
			if (map[i][j] == BLK) printf("  ");
			if (map[i][j] == WAL) printf("��");
			if (map[i][j] == HUM) printf("��");
			if (map[i][j] == OBS) printf("��");
		}
		printf("\n");
	}
	printf("\n�� : �޴� Ŀ�� ���� �̵�      �� : �÷��̾� ����\n\n�� : �޴� Ŀ�� �Ʒ��� �̵�    Enter : �޴� ����\n");

}
//����********************************************************************************
void Jump()
{
	int c;

	if (map[person.y - 1][person.x] == BLK)
	{
		c = map[person.y][person.x];
		map[person.y][person.x] = map[person.y - 1][person.x];
		map[person.y - 1][person.x] = c;
		person.y--;
	}
}
//�߷�********************************************************************************
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
//��ֹ�*******************************************************************************
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
//���� �� ĭ�� �о����*************************************************************
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
//���� ȭ��*****************************************************************************
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
			printf("���������������������\n");
			printf("��                                    ��\n");
			printf("��                                    ��\n");
			printf("��         ��  Main Screen            ��\n");
			printf("��                                    ��\n");
			printf("��                Exit                ��\n");
			printf("��                                    ��\n");
			printf("��                                    ��\n");
			printf("��                                    ��\n");
			printf("���������������������\n");
			printf("\n�� : �޴� Ŀ�� ���� �̵�      �� : �÷��̾� ����\n\n�� : �޴� Ŀ�� �Ʒ��� �̵�    Enter : �޴� ����\n");
		}
		else if (select == 1)
		{
			printf("���������������������\n");
			printf("��                                    ��\n");
			printf("��                                    ��\n");
			printf("��             Main Screen            ��\n");
			printf("��                                    ��\n");
			printf("��         ��     Exit                ��\n");
			printf("��                                    ��\n");
			printf("��                                    ��\n");
			printf("��                                    ��\n");
			printf("���������������������\n");
			printf("\n�� : �޴� Ŀ�� ���� �̵�      �� : �÷��̾� ����\n\n�� : �޴� Ŀ�� �Ʒ��� �̵�    Enter : �޴� ����\n");
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
//Ŀ�� �� ���̰� ����*****************************************************************
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
