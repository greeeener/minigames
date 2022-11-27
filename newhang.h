#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <time.h>
#include <Windows.h>
#include<conio.h>
#define LIFE 10;

int life = LIFE;
char ch;
int cnt = 0;

//  등록된 단어 사전​
char* dic[] = { "boy", "good", "student", "university", "chair", "desk", "computer", "mask", "holiday" };
int wnum = sizeof(dic) / sizeof(char*);  // 등록된 단어의 개수
int i;
int sel;
char* word;
char* pword;
int len;
int correct = 0;

void gotoxy(int x, int y) {
    COORD pos = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void run() {
    srand(time(NULL));
    sel = rand() % wnum;   // 임의의 단어 첨자
    word = dic[sel];          // 임의의 단어 포인터

    len = strlen(word);       // 단어의 길이

    pword = (char*)malloc(len + 1);   // 화면에 나타나는 단어 배열

    for (i = 0; i < len; i++)
        pword[i] = '_';     //  화면에 나타나는 단어 _ 로 초기화
    pword[len] = '\0';


    gotoxy(50, 0);
    printf("== 단어 맞추기 게임 ==");

    while (life > 0) {
        gotoxy(80, 3);
        printf("[ life : %d ]", life);
        gotoxy(50, 5);
        printf("맞출단어 : %s  ", pword);
        gotoxy(40, 8);
        printf(" 빈칸에 들어갈 문자 입력 :");
        ch = _getch();   //  문자입력
        gotoxy(67, 8);
        printf("%c", ch);
        cnt++;                                    // 시도 회수 카운트
        if (word[i] != ch) {
            life--;
        }


        for (i = 0; i < len; i++)
            if (pword[i] == '_' && word[i] == ch)   // 입력된 문자가 아직 가려져 있으면
                pword[i] = ch;                          // 화면에 그 문자를 나타냄



        for (i = 0; i < len; i++)

            if (pword[i] == '_') break;       //  가려져 있는 문자가 있는가?   

        if (i == len) {    // 가려진 문자가 없으면, 즉 다 맞추었으면
            gotoxy(70, 10);
            printf("%d 번만에 %s를 맞추었습니다. 다음문제", cnt, pword);
            correct++;
        }




    }
    gotoxy(40, 10);
    printf("수고했습니다. 당신은 % d 개의 단어를 맞췄습니다!", correct);
}
