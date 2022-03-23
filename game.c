#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void initarr(char arr[ROW][COL], int row, int col)
{
	int i = 0; 
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			arr[i][j] = ' ';
		}
	}
}
void displayarr(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	for (i=0; i < row;i++)
	{
		int j = 0;
		for (j=0; j < col; j++)
		{
			printf(" %c ",arr[i][j]);
			if (j< col - 1)
				printf("|");
		}
		printf("\n");
		if (i< row - 1)
		{
			for (j=0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}
		
	}
}

void playermove(char arr[ROW][COL], int row, int col)
{
	int x;
	int y;
	while (1)
	{
		printf("请输入要下的坐标:\n");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (arr[x - 1][y - 1] == ' ')
			{
				arr[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("该坐标已被占用\n");
			}
		}
		else
			printf("请重新输入\n");
	}
}

void cmpmove(char arr[ROW][COL], int row, int col)
{
	printf("电脑走\n");
	int x=0;
	int y=0;	
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (arr[x][y] == ' ')
		{
			arr[x][y] = '#';
			break;
		}
	}
}

int isfull(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (arr[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}

char iswin(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < 3; i++)
	{
		if (arr[0][i] == arr[1][i] && arr[0][i] == arr[2][i] && arr[1][i] != ' ')
			return arr[1][i];
	}
	for (j = 0; j < 3; j++)
	{
		if (arr[j][0] == arr[j][1] && arr[j][0] == arr[j][2] && arr[j][1] != ' ')
			return arr[j][1];
	}
	if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[1][1] != ' ')
		return arr[1][1];
	if(arr[2][0] == arr[1][1] && arr[1][1] == arr[0][2] && arr[1][1] != ' ')
		return arr[1][1];
	if (1 == isfull(arr, ROW, COL))
	{
		return 'q';
	}
	else
		return 'c';
}