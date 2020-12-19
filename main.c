#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <limits.h>
#include <time.h>

int getInt (int mode);
void clear_stdin();

int main()
{
	int *a;
	int n = 0, s = 0, n_min = 0, min = INT_MAX, c = 0, t = 0, ch = 0;
	float a_mean = 0.0;
	int r = (unsigned int)(time(NULL));
	srand(r);
	do
	{
		c = 0;
		system("cls");
		printf("A. INPUT ARRAY\n");
		printf("B. PROCESS ARRAY\n");
		printf("C. OUTPUT ARRAY\n");
		printf("D. EXIT\n");
		c = getchar();
		switch (c)
		{
            case 97 :   //a
            {
                a_mean = 0.0;
                n_min = 0;
                s = 0;
                t = 0;
                min - INT_MAX;
                system("cls");
                printf("ENTER THE SIZE OF ARRAY: ");
                clear_stdin();
                n = getInt(1);
                a = (int*)malloc(n * sizeof(int));
                printf("FILL THE ARRAY WITH RANDOM VALUES? (y/n) ");
                ch = getchar();
                clear_stdin();
                switch (ch)
                    {
                    case 121 :   //y
                    {
                        for(int i = 0; i < n; i++)
                        {
                            a[i] = getInt(2);
                            printf("%i ", a[i]);
                        }
                        getchar();
                        clear_stdin();
                        break;
                    }
                    case 110 :   //n
                    {
                        for(int i = 0; i < n; i++)
                        {
                            a[i] = getInt(1);
                        }
                        break;
                    }
                    }
                ch = 0;
                c = 0;
                continue;
            }
            case 98 :   //b
            {
                if (n > 0)
                {
                    for(int i = 0; i < n; i++)
                    {
                        if (i % 2 == 0)
                        {
                            s += a[i];
                            t++;

                        };
                        if (a[i] < min)
                        {
                            min = a[i];
                            n_min = i;
                        };
                    }
                    a_mean = (float)s / t;
                }
                else
                {
                    printf("THE ARRAY IS EMPTY!\n");
                    getchar();
                    clear_stdin();
                }
                c = 0;
                continue;
            }
            case 99 :   //c
            {
			system("cls");
			printf("INPUT ARRAY: ");
			for(int i = 0; i < n; i++)
			{
				printf("%i ", a[i]);
			}
			printf("\n");
			printf("OUTPUT ARRAY: ");
			for(int i = 0; i < n; i++)
			{
				if (i == n_min)
				{
					printf("%-7.3f ", a_mean);
				}
				else
				{
					printf("%i ", a[i]);
				};
			}
			c = 0;
			getchar();
			clear_stdin();
			continue;
		}
		}
	}
	while(c != 100);
	free(a);
	return 0;
}

void clear_stdin()
{
	int ch = getchar();
	while (ch != '\n' && ch != EOF)
	{
		ch = getchar();
	}
}

int getInt (int mode)
{
	char str[512];
	int x;
	switch(mode)
	{
	case 1 :
	{
		fgets(str, sizeof(str), stdin);
		while (sscanf (str, "%d", &x) != 1)
		{
			printf("Enter correct value!\n");
			fgets(str, sizeof(str), stdin);
		}
		break;
	}
	case 2 :
	{
		x = rand() % 256 - 128;
		break;
	}
	default :
	{
		x = 0;
	}

	}
	return x;
}
