// Question 6: 
// Write a generalised code for the following pattern (example is for n=4) 
// A B C D
// B C D E
// C D E F
// D E F G

// You have to write a program that works for all value of n

#include <stdio.h>

int main()
{
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%c ", 'A' + i + j);
        }

        printf("\n");
    }

    return 0;
}