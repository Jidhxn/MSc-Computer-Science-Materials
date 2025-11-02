#include <stdio.h>

struct Pair {
    int min;
    int max;
};

struct Pair findMaxMin(int arr[], int start, int end) {
    struct Pair result, left, right, mid;
    int midIndex;

    // Base case: If only one element is present
    if (start == end) {
        result.min = arr[start];
        result.max = arr[start];
        return result;
    }

    // If there are two elements
    if (end == start + 1) {
        result.min = (arr[start] < arr[end]) ? arr[start] : arr[end];
        result.max = (arr[start] > arr[end]) ? arr[start] : arr[end];
        return result;
    }

    // Divide the array into two halves
    midIndex = (start + end) / 2;
    left = findMaxMin(arr, start, midIndex);
    right = findMaxMin(arr, midIndex + 1, end);

    // Merge the results
    result.min = (left.min < right.min) ? left.min : right.min;
    result.max = (left.max > right.max) ? left.max : right.max;

    return result;
}

int main() {
    int arr[] = {3, 1, 9, 12, 5, 6, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    struct Pair result = findMaxMin(arr, 0, n - 1);

    printf("Minimum element: %d\n", result.min);
    printf("Maximum element: %d\n", result.max);

    return 0;
}

