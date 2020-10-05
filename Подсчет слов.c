#include<ctype.h>
#include<stdlib.h>
#include<stdio.h>

int main()
{

	char a[]= "My name is Danil.";
	int characters = 0;
	int words = 0;
	int digits = 0;
	printf("\nlengh of massiv%d \n", strlen(a));
	int size = strlen(a);
	printf("Input \n");
	size_t i = 0; 
	while (i<size)
	{
		if (a[i] == ' ') 
		{
			if ((a[i - 1] >= '0' && a[i - 1] <= '9'))
				digits++;
			if ((a[i - 1] >= 'a' && a[i - 1] <= 'z') || (a[i - 1] >= 'A' && a[i - 1] <= 'Z') || (a[i-1] = '.'||','||'-'||'='||'+'||'/'||'*'))
				words += 1;
			
		}
		i++;  
	}

	printf("Колличество слов %d\n", words);
	printf("Колличество цифр %d\n", digits);

	system("pause");
	return 0;
}