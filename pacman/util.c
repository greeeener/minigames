#include "Defines.h"

void emptyScreen() {
	printf(" ");
}

gotoxy(int x, int y) {
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void init() {
	system("mode con cols=120 lines=40 | title MINI GAMES");
}

void textcolor(int cnum) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), cnum);
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