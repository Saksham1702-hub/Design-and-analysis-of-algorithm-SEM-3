// Day 3

// Given an array of daily temperatures, find the length of the longest consecutive strictly increasing streak.


// Input:  [10, 12, 15, 14, 16, 18, 20]
// Output: 4

// Explanation: 14, 16, 18, 20 is the longest increasing streak.

#include <stdio.h>

int main()
{
    int arr[] = {10, 12, 15, 14, 16, 18, 20};
    int n = 7;

    int current = 1;
    int longest = 1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            current++;
        }
        else
        {
            current = 1;
        }

        if (current > longest)
        {
            longest = current;
        }
    }

    printf("Longest increasing streak = %d", longest);

    return 0;
}