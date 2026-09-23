#include <stdio.h>

int main() {
    int arr[100], n, k, i;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter array elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter k: ");
    scanf("%d", &k);

    k = k % n;

    // Rotate k times
    while (k > 0) {
        int last = arr[n - 1];

        for (i = n - 1; i > 0; i--) {
            arr[i] = arr[i - 1];
        }

        arr[0] = last;
        k--;
    }

    printf("Rotated array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}