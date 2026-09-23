#include <stdio.h>

int main() {
    int n, i;
    int arr[100], result[100];
    int left, right, pos;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter sorted array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    left = 0;
    right = n - 1;
    pos = n - 1;

    while (left <= right) {

        if (arr[left] * arr[left] > arr[right] * arr[right]) {
            result[pos] = arr[left] * arr[left];
            left++;
        } 
        else {
            result[pos] = arr[right] * arr[right];
            right--;
        }

        pos--;
    }

    printf("Squared sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}