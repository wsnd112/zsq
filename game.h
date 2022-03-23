#define _CRT_SECURE_NO_WARNINGS 1
#define ROW 3
#define COL 3
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void initarr(char arr[ROW][COL], int row ,int col);
void displayarr(char arr[ROW][COL], int row, int col);
void playermove(char arr[ROW][COL], int row, int col);
void cmpmove(char arr[ROW][COL], int row, int col);
char iswin(char arr[ROW][COL], int row, int col);