#include <iostream>
using namespace std;

// Linear searching algorithm

int linearSearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            cout << "The element was found on index no: " << i << endl;
        }
    }
    return -1;
}

int binarySearch(int arr[], int size, int element)
{
    int low, mid, high;
    low = 0;
    high = size - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            cout << "The element was found on index: " << mid;
        }
        if (arr[mid] < element)
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
    int arr[] = {1, 5, 8, 9, 45, 56, 59, 66, 69};
    int size = sizeof(arr) / sizeof(int);
    int ele = 69;
    // linearSearch(arr,size,ele);
    binarySearch(arr, size, ele);
    return 0;
}
