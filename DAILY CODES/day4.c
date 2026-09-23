// Day 4 Question: 
// Given an integer array arr and a target value target, find the indices of two elements whose sum equals target.  Assume exactly one valid pair exists, and the same element cannot be used twice.
// Input:
// arr = [2, 7, 11, 15]
// target = 9

// Output:
// [0, 1]

#include <stdio.h>

int main()
{
    int arr[] = {2, 7, 11, 15};
    int n = 4;
    int target = 9;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == target)
            {
                printf("[%d, %d]", i, j);
                return 0;
            }
        }
    }

    return 0;
}