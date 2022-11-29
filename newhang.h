#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>


#define LIFE 9;

int life = LIFE;
int len;
int correct = 0;
char vowel[] = { 'a','e','i','o','u' };
char consonant[] = { 'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','y','z' };

void gotoxy(int x, int y) {
    COORD pos = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


void run_hang_man() {

    system("color 20");
    char ch;
    int cnt = 0;

    //  등록된 단어 사전​
    char* dic[] = { "boy", "good", "student", "university", "chair", "desk", "computer", "mask", "holiday" };
    int wnum = sizeof(dic) / sizeof(char*);  // 등록된 단어의 개수
    int i;
    int sel;
    char* word;
    char* pword;
    srand(time(NULL));
    sel = rand() % wnum;   // 임의의 단어 첨자
    word = dic[sel];          // 임의의 단어 포인터

    len = strlen(word);       // 단어의 길이

    pword = (char*)malloc(len + 1);   // 화면에 나타나는 단어 배열

    for (i = 0; i < len; i++)
        pword[i] = '_';     //  화면에 나타나는 단어 _ 로 초기화
    pword[len] = '\0';


    gotoxy(40, 0);
    printf("== 단어 맞추기 게임 ==");

    while (life > 0) {
        gotoxy(80, 3);
        printf("[ life : %d ]", life);
        gotoxy(40, 5);
        printf("맞출단어 : %s  ", pword);
        gotoxy(35, 10);
        printf(" 빈칸에 들어갈 문자 입력 :");
        gotoxy(0, 20);
        printf("모음 [ %c %c %c %c %c ]", vowel[0], vowel[1], vowel[2], vowel[3], vowel[4]);
        gotoxy(0, 22);
        printf("자음 [ %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c]", consonant[0], consonant[1], consonant[2], consonant[3], consonant[4], consonant[5], consonant[6], consonant[7], consonant[8], consonant[9], consonant[10], consonant[11], consonant[12], consonant[13], consonant[14], consonant[15], consonant[16], consonant[17], consonant[18], consonant[19], consonant[20]);
        ch = _getch();   //  문자입력
        char* ptr = strchr(word, ch);
        if (ptr == NULL) {
            for (int i = 0; i < 5; i++) {
                if (vowel[i] == ch) {
                    vowel[i] = '/';
                }
                for (int j = 0; j < 21; j++)
                    if (consonant[j] == ch) {
                        consonant[j] = '/';
                    }
            }
        }
        if (ptr != NULL) {
            for (int i = 0; i < 5; i++) {
                if (vowel[i] == ch) {
                    vowel[i] = '0';
                }
                for (int j = 0; j < 21; j++)
                    if (consonant[j] == ch) {
                        consonant[j] = '0';
                    }
            }
        }
        gotoxy(62, 10);
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
            printf("%d 번만에 %s를 맞추었습니다. ", cnt, pword);
            correct++;
        }
    }
    if (life == 0) {
        gotoxy(50, 10);
        printf("기회를 모두 소진했습니다!");
    }