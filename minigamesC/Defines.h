#pragma once
#ifndef DEFINES_H
#define DEFINES_H

#include <Windows.h>
#include <stdio.h>
#include <time.h>
//#include <stdbool.h>

#include "Pacman.h"
#include "Util.h"

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

void init();
void startMainScreen();
void selectGamesScreen();

void printTitle29(int map[][29], int h, int w, int x, int y);
void printTitle34(int map[][34], int h, int w, int x, int y);

#endif