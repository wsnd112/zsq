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
		printf("��Ӯ��\n");
	}
	if (ret == '#')
	{
		printf("������\n");
	}
	if (ret == 'q')
	{
		printf("ƽ��\n");
	}
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		
		menu();
		printf("��ѡ��; \n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
				break;
		case 0:
			printf("�˳���Ϸ");
			break;
		default:
			printf("������ѡ��!");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}