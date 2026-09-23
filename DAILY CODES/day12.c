#include <stdio.h>

int main() {
    int arr[100], n, i, j = 0;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter sorted array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Remove duplicates
    for (i = 1; i < n; i++) {
        if (arr[i] != arr[j]) {
            j++;
            arr[j] = arr[i];
        }
    }

    printf("Array after removing duplicates: ");
    for (i = 0; i <= j; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}