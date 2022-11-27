#include <stdio.h>

#include "SCROLL.H"

int main()
{
	int turn = 1;
	int ch, t = 0;

	srand((unsigned)time(NULL));
	CursorView(0);
	turn = StartScreen();
	if (turn == 1)
	{
		gotoxy(0, 0);
		mapbase();
		mapping();
	}

	while (turn)
	{
		if (_kbhit())
		{
			ch = _getch();
			if (ch == 'j') Jump();
		}
		if (t % 30 == 0) MapMove();
		if (t % 70 == 0) Gravity();
		if (t % 500 == 0) Obstacle();
		gotoxy(0, 0);
		mapping();
		turn = Gameover();
		t++;
	}

	return 0;
}