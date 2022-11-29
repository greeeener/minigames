#include "Defines.h"

gotoxy(int x, int y) { //위치 설정
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void init() { //콘솔 크기, 이름 설정 / cmd 업데이트 했더니 크기 적용 안됨..
	system("mode con cols=120 lines=40 | title MINI GAMES");
}

void textcolor(int text) { //텍스트 색 설정
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

void textnbackcolor(int text, int back) { //텍스트,배경 색 설정
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text | (back << 4));
}

void CursorView() { //커서 안 보이게 하는 함수
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.bVisible = FALSE;
	cursorInfo.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), & cursorInfo);
}