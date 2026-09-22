#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000
#define REPEAT 1000000

// Comparison function for qsort()
int compare(const void *a, const void *b)
{
    int x = *(const int *)a;
    int y = *(const int *)b;

    if (x < y)
        return -1;
    else if (x > y)
        return 1;
    else
        return 0;
}

// Linear Search
int linearSearch(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }

    return -1;
}

// Binary Search
int binarySearch(int arr[], int size, int key)
{
    int low = 0;
    int high = size - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int arr[SIZE];
    int key;
    int result;

    clock_t start, end;

    double linearTime;
    double binaryTime;

    // Initialize random number generator
    srand((unsigned int)time(NULL));

    // Generate 1000 random numbers
    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = rand() % 10000;
    }

    // Select an existing random element as the search key
    key = arr[rand() % SIZE];

    printf("Search Key: %d\n\n", key);

    // ----------------------------------
    // Linear Search
    // ----------------------------------

    start = clock();

    for (int i = 0; i < REPEAT; i++)
    {
        result = linearSearch(arr, SIZE, key);
    }

    end = clock();

    linearTime = (double)(end - start) / CLOCKS_PER_SEC;

    if (result != -1)
    {
        printf("Linear Search: Key found\n");
        printf("Time taken: %.6f seconds\n\n", linearTime);
    }

    // Sort the array for Binary Search
    qsort(arr, SIZE, sizeof(int), compare);

    // ----------------------------------
    // Binary Search
    // ----------------------------------

    start = clock();

    for (int i = 0; i < REPEAT; i++)
    {
        result = binarySearch(arr, SIZE, key);
    }

    end = clock();

    binaryTime = (double)(end - start) / CLOCKS_PER_SEC;

    if (result != -1)
    {
        printf("Binary Search: Key found\n");
        printf("Time taken: %.6f seconds\n\n", binaryTime);
    }

    // Compare performance
    if (binaryTime < linearTime)
    {
        printf("Binary Search is faster.\n");
    }
    else if (linearTime < binaryTime)
    {
        printf("Linear Search is faster.\n");
    }
    else
    {
        printf("Both searches took approximately the same time.\n");
    }

    return 0;
}