#include <stdio.h>

int interpolationSearch(int arr[], int n, int x) {
    int low = 0, high = n - 1;

    while (low <= high && x >= arr[low] && x <= arr[high]) {

        if (arr[high] == arr[low])
            break;

        int pos = low + ((x - arr[low]) * (high - low)) /
                          (arr[high] - arr[low]);

        if (arr[pos] == x)
            return pos;

        if (arr[pos] < x)
            low = pos + 1;
        else
            high = pos - 1;
    }

    return -1;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = 5;
    int x = 30;

    int result = interpolationSearch(arr, n, x);

    if (result != -1)
        printf("Element found at index %d", result);
    else
        printf("Element not found");

    return 0;
}