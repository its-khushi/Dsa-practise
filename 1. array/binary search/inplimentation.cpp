#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int key)
{
    int start = 0;
    int end = size - 1;
    int mid;
    while (start <= end)
    {

        mid = start + (end - start) / 2 ;

        if (key == arr[mid])
        {
            return mid;
        }
        if (arr[mid] > key)
        {
            end = mid-1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    cout << binarySearch(arr, 6, 2);
    return 0;
}
