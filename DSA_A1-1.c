#include <stdio.h>

int main() {
    int n;
    float sum = 0, average = 0, greaterSum = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    average = sum / n;

    for (int i = 0; i < n; i++) {
        if (arr[i] > average) {
            greaterSum += arr[i];
        }
    }

    printf("Average of the array = %.2f\n", average);
    printf("Sum of elements greater than the average = %.2f\n", greaterSum);

    return 0;
}



Assignment 1
