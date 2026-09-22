#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000

// Copy original array
void copyArray(int source[], int destination[])
{
    for (int i = 0; i < SIZE; i++)
    {
        destination[i] = source[i];
    }
}

// Bubble Sort
void bubbleSort(int arr[])
{
    for (int i = 0; i < SIZE - 1; i++)
    {
        for (int j = 0; j < SIZE - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Selection Sort
void selectionSort(int arr[])
{
    for (int i = 0; i < SIZE - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < SIZE; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// Insertion Sort
void insertionSort(int arr[])
{
    for (int i = 1; i < SIZE; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

// Merge function
void merge(int arr[], int left, int mid, int right)
{
    int size = right - left + 1;
    int *temp = (int *)malloc(size * sizeof(int));

    int i = left;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }

    while (j <= right)
    {
        temp[k++] = arr[j++];
    }

    for (i = 0; i < size; i++)
    {
        arr[left + i] = temp[i];
    }

    free(temp);
}

// Merge Sort
void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

// Partition for Quick Sort
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;

            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

// Quick Sort
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main()
{
    int original[SIZE];
    int arr[SIZE];

    clock_t start, end;

    double bubbleTime;
    double selectionTime;
    double insertionTime;
    double mergeTime;
    double quickTime;

    srand((unsigned int)time(NULL));

    // Generate 10,000 random numbers
    for (int i = 0; i < SIZE; i++)
    {
        original[i] = rand() % 100000;
    }

    // Bubble Sort
    copyArray(original, arr);

    start = clock();
    bubbleSort(arr);
    end = clock();

    bubbleTime = (double)(end - start) / CLOCKS_PER_SEC;

    // Selection Sort
    copyArray(original, arr);

    start = clock();
    selectionSort(arr);
    end = clock();

    selectionTime = (double)(end - start) / CLOCKS_PER_SEC;

    // Insertion Sort
    copyArray(original, arr);

    start = clock();
    insertionSort(arr);
    end = clock();

    insertionTime = (double)(end - start) / CLOCKS_PER_SEC;

    // Merge Sort
    copyArray(original, arr);

    start = clock();
    mergeSort(arr, 0, SIZE - 1);
    end = clock();

    mergeTime = (double)(end - start) / CLOCKS_PER_SEC;

    // Quick Sort
    copyArray(original, arr);

    start = clock();
    quickSort(arr, 0, SIZE - 1);
    end = clock();

    quickTime = (double)(end - start) / CLOCKS_PER_SEC;

    // Display execution times
    printf("\nSorting Algorithm Performance\n");
    printf("--------------------------------------\n");

    printf("Bubble Sort    : %.6f seconds\n", bubbleTime);
    printf("Selection Sort : %.6f seconds\n", selectionTime);
    printf("Insertion Sort : %.6f seconds\n", insertionTime);
    printf("Merge Sort     : %.6f seconds\n", mergeTime);
    printf("Quick Sort     : %.6f seconds\n", quickTime);

    // Save results to CSV file
    FILE *file = fopen("sorting_times.csv", "w");

    if (file != NULL)
    {
        fprintf(file, "Algorithm,Time\n");
        fprintf(file, "Bubble Sort,%.6f\n", bubbleTime);
        fprintf(file, "Selection Sort,%.6f\n", selectionTime);
        fprintf(file, "Insertion Sort,%.6f\n", insertionTime);
        fprintf(file, "Merge Sort,%.6f\n", mergeTime);
        fprintf(file, "Quick Sort,%.6f\n", quickTime);

        fclose(file);

        printf("\nResults saved to sorting_times.csv\n");
    }
    else
    {
        printf("\nError creating CSV file.\n");
    }

    return 0;
}