#include<ctype.h>
#include<stdlib.h>
#include<stdio.h>

int main()
{
	int a, b, count1 = 0, count2 = 0;
    srand(time(NULL));
	printf("выбери режим:\n");
	printf("1.загадай число сам\n");
	printf("2.отгадай число от пк\n");
	int inputov;
	char input;
	scanf("%d", &inputov);  // 
	switch (inputov) 
	{
	    case 1: 
		{
		    printf("\nправила таковы:b - больше, m - меньше, = - равно. а теперь введи число\n");
		    scanf("%d", &a);
		    b = rand() % 1000;
		    while (input != '=') 
			{
			    
			    printf("твое число %d?\n",b);
			    count1 += 1;
			    scanf("%c", &input);
			    scanf("%c", &input);
			    if (input == 'b') b = b + rand() % (1000 - b + 1);
			    if (input == 'm') b = rand() % (b + 1);
		    }
		    printf("кол-во подходов %d", count1 / 2);
		    break; 
		}
	    case 2: 
		{
			a = 0 + rand() % 1000;
		    printf("\nкомп загадал число, угадывай: b - больше, m - меньше, = - равно");
		    printf("\nвведи число\n");
		    scanf("%d", &b);
		    printf("\nи проси подсказку\n");
			while (a != b)
			{
				count2 += 1;
				scanf("%d", &b);
				printf("\nподсказка: \n");
				scanf("%c", &input);

				if (input == 'm')
				{
					if (a < b) printf("да");
					else printf("нет");
				}
				if (input == 'b')
				{
					if (a > b) printf("да");
					else printf("нет");
				}
			}
		    printf("ты угадал, это число %d\n", a);
		    printf("кол-во подходов %d", count2);
		    break;
	    }
}
system("pause");
return 0;
}