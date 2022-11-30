#pragma once
#ifndef TETRIS_H
#define TETRIS_H

bool CheckCrash(int x, int y);
void RandomBlock();
void DropBlockTime();
void BlockMeetGround();
void RemoveBlock();
void DrawMap();
void DrawBlock();
void Key();
void ShowGameOver();
void sizeCon();
void run_tetris();
bool checkover(int space[12][12]);
void inittetris(int(*space)[12][12]);

#endif