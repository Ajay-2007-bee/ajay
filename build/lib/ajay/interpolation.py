def interpolation_search(arr, x):
    low = 0
    high = len(arr) - 1

    while low <= high and arr[low] <= x <= arr[high]:

        if arr[high] == arr[low]:
            break

        pos = low + int(
            ((x - arr[low]) * (high - low)) /
            (arr[high] - arr[low])
        )

        if arr[pos] == x:
            return pos

        elif arr[pos] < x:
            low = pos + 1
        else:
            high = pos - 1

    return -1


# Example
if __name__ == "__main__":
    arr = [10, 20, 30, 40, 50]
    print(interpolation_search(arr, 30))