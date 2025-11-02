#include <stdio.h>

// Recursive binary search function
int binarySearchRecursive(int arr[], int left, int right, int target) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if the target is present at the middle
        if (arr[mid] == target)
            return mid;

        // If the target is greater, search in the right half
        if (arr[mid] < target)
            return binarySearchRecursive(arr, mid + 1, right, target);

        // If the target is smaller, search in the left half
        return binarySearchRecursive(arr, left, mid - 1, target);
    }

    // If the target is not present in the array
    return -1;
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 12;

    int result = binarySearchRecursive(arr, 0, size - 1, target);

    if (result != -1)
        printf("Element %d found at index %d\n", target, result);
    else
        printf("Element %d not found in the array\n", target);

    return 0;
}

