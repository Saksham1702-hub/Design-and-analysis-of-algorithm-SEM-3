// Day 5 question:
// Input a number from the user and print
// a. Number of 1 and number of 0 in its binary representation.
// b. Number of consecutive 1 in the binary representation.

#include <stdio.h>

int main()
{
    int n;
    int ones = 0;
    int zeros = 0;
    int current = 0;
    int maximum = 0;
    int bit;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n == 0)
    {
        printf("Number of 1s = 0\n");
        printf("Number of 0s = 1\n");
        printf("Consecutive 1s = 0\n");

        return 0;
    }

    while (n > 0)
    {
        bit = n % 2;
        n = n / 2;

        if (bit == 1)
        {
            ones++;
            current++;

            if (current > maximum)
            {
                maximum = current;
            }
        }
        else
        {
            zeros++;
            current = 0;
        }
    }

    printf("Number of 1s = %d\n", ones);
    printf("Number of 0s = %d\n", zeros);
    printf("Consecutive 1s = %d\n", maximum);

    return 0;
}