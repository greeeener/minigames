#include "Defines.h"

gotoxy(int x, int y) { //��ġ ����
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void init() { //�ܼ� ũ��, �̸� ���� / cmd ������Ʈ �ߴ��� ũ�� ���� �ȵ�..
	system("mode con cols=120 lines=40 | title MINI GAMES");
}

void textcolor(int text) { //�ؽ�Ʈ �� ����
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text);
	// 1 darkblue		9 blue
	// 2 darkgreen		10 green
	// 3 darkskyblue	11 skyblue
	// 4 darkred		12 red
	// 5 darkpink		13 pink
	// 6 darkyellow		14 yellow
	// 7 lightgray		15 white
	// 8 darkgray
	//16~31 blue background
	//32~47 green background
}

void textnbackcolor(int text, int back) { //�ؽ�Ʈ,��� �� ����
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text | (back << 4));
}

void CursorView() { //Ŀ�� �� ���̰� �ϴ� �Լ�
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.bVisible = FALSE;
	cursorInfo.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), & cursorInfo);
}