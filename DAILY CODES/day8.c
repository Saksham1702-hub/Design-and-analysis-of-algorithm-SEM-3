// Question 8:
// Given an m × n matrix, return all elements of the matrix in spiral order

// Input 
// [
//  [1,  2,  3,  4],
//  [5,  6,  7,  8],
//  [9, 10, 11, 12]
// ]

// Output 
// [1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7]

#include <stdio.h>

int main()
{
    int m, n;

    printf("Enter number of rows: ");
    scanf("%d", &m);

    printf("Enter number of columns: ");
    scanf("%d", &n);

    int arr[m][n];

    printf("Enter the matrix:\n");

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    int top = 0;
    int bottom = m - 1;
    int left = 0;
    int right = n - 1;

    printf("Spiral order: ");

    while (top <= bottom && left <= right)
    {
        // 1. Left to Right
        for (int j = left; j <= right; j++)
        {
            printf("%d ", arr[top][j]);
        }
        top++;

        // 2. Top to Bottom
        for (int i = top; i <= bottom; i++)
        {
            printf("%d ", arr[i][right]);
        }
        right--;

        // 3. Right to Left
        if (top <= bottom)
        {
            for (int j = right; j >= left; j--)
            {
                printf("%d ", arr[bottom][j]);
            }
            bottom--;
        }

        // 4. Bottom to Top
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                printf("%d ", arr[i][left]);
            }
            left++;
        }
    }

    return 0;
}