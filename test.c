#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void menu()
{
	printf("*********************\n");
	printf("***1.play   0.exit***\n");
	printf("*********************\n");
}

void game()
{
	char ret = 0;
	char arr[ROW][COL] = { 0 }; 
	initarr(arr, ROW, COL);
	displayarr(arr,ROW,COL);
	while (1)
	{
		playermove(arr, ROW, COL);
		displayarr(arr, ROW, COL);
		ret = iswin(arr, ROW, COL);
		if (ret != 'c')
		{
			break;
		}
		cmpmove(arr, ROW, COL);
		displayarr(arr, ROW, COL);
		ret = iswin(arr, ROW, COL);
		if (ret != 'c')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("你赢了\n");
	}
	if (ret == '#')
	{
		printf("你输了\n");
	}
	if (ret == 'q')
	{
		printf("平局\n");
	}
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		
		menu();
		printf("请选择; \n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
				break;
		case 0:
			printf("退出游戏");
			break;
		default:
			printf("请重新选择!");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}