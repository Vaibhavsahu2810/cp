#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

bool isconso(char ch)
{
    if (ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u')
        return 1;
    else
        return 0;
}

int main()
{
    int n;
    printf("Enter the value of n (size of array of strings):");
    scanf("%d", &n);
    char str[n][100];
    for (int i = 0; i < n; i++)
    {
        scanf("%s", &str[i]);
    }
    printf("\n");

    while (1)
    {
        printf("Choose a number from 1 to 4 to select cases(for exit press 0):\n");
        printf("1 - Count consonants in each string \n");
        printf("2 - Reverse the whole string and print it \n");
        printf("3 - Print all strings with vowels capitalized \n");
        printf("4 - Print base address of each string  \n");
        int x;
        printf("\n Enter your choice : \n");
        scanf("%d", &x);
        if (x == 0)
            break;
        switch (x)
        {
        case 1:
        {
            for (int i = 0; i < n; i++)
            {
                int count = 0;
                for (int j = 0; j < 100; j++)
                {
                    if (str[i][j] == '\0')
                    {
                        break;
                    }
                    char ch = str[i][j];
                    if (ch < 91)
                        ch = ch + 32;
                    if (ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u')
                    {
                        count++;
                    }
                }
                printf("the number of consonants in string %d =  %d\n", i + 1, count);
            }
            break;
        }
        case 2:
        {
            for (int i = 0; i < n; i++)
            {
                char *s = str[i];
                int x = 0, y = strlen(str[i]) - 1;
                char t;
                while (x < y)
                {
                    t = s[x];
                    s[x] = s[y];
                    s[y] = t;
                    x++;
                    y--;
                }
                printf("Reversed string %d : %s \n", i + 1, str[i]);
            }
            break;
        }
        case 3:
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < 100; j++)
                {
                    if (str[i][j] == '\0')
                        break;
                    if (!isconso(str[i][j]))
                    {
                        str[i][j] = str[i][j] - 32;
                    }
                }
                printf("String %d : %s \n", i + 1, str[i]);
            }
            break;
        }

        case 4:
        {
            for (int i = 0; i < n; i++)
            {
                printf("the base address of string %d: %p\n", i + 1, &str[i]);
            }
            printf("\n");
            break;
        }

        default:
            printf("Invalid choice\n");
            break;
        }
    }
}