//Write a C program that accepts a positive integer containing digits from 0 to 9. Exactly one digit is missing, while the remaining nine digits appear exactly once
#include <stdio.h>

int main()
{
    int num, digit;
    int sum = 0;

    printf("Enter the number: ");
    scanf("%d", &num);

    while (num > 0)
    {
        digit = num % 10;
        sum = sum + digit;
        num = num / 10;
    }

    int missing = 45 - sum;

    printf("Missing digit = %d", missing);

    return 0;
}