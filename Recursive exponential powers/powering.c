#include <stdio.h>
#include <time.h>

//Normal method
int normalPower(int x, int n)
{
    int result = 1;

    for (int i = 0; i < n; i++)
    {
        result = result * x;
    }

    return result;
}

//Recursive fast power
int recursivePower(int x, int n)
{
    if (n == 0)
        return 1;

    if (n % 2 == 0)
        return recursivePower(x * x, n / 2);
    else
        return x * recursivePower(x * x, (n - 1) / 2);
}

int main()
{
    int x, n;
    volatile int result1, result2;
    clock_t start, end;
    double time1, time2;

    printf("Enter base: ");
    scanf("%d", &x);

    printf("Enter power: ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("Enter a non-negative power.\n");
        return 0;
    }

    // Normal method timing
    start = clock();

    for (int i = 0; i < 1000000; i++)
    {
        result1 = normalPower(x, n);
    }

    end = clock();

    time1 = (double)(end - start) / CLOCKS_PER_SEC;


    // Recursive method timing
    start = clock();

    for (int i = 0; i < 1000000; i++)
    {
        result2 = recursivePower(x, n);
    }

    end = clock();

    time2 = (double)(end - start) / CLOCKS_PER_SEC;


    printf("\nNormal Method Result = %d\n", result1);
    printf("Recursive Method Result = %d\n", result2);

    printf("\nTime taken by Normal Method = %f seconds\n", time1);
    printf("Time taken by Recursive Method = %f seconds\n", time2);

    return 0;
}