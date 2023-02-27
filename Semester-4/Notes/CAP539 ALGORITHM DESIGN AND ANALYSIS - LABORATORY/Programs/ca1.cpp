#include <iostream>
using namespace std;

void optimizedBubbleSort(int arr[], int n)
{
    int i, j, temp;
    bool swapped;

    int totalSwaps = 0;
    int totalIterations = 0;

    for (i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (j = 0; j < n - i - 1; j++)
        {
            totalIterations++;
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
                totalSwaps++;
            }
        }

        if (!swapped)
            break;
    }

    cout << "Total swaps: " << totalSwaps << endl;
    cout << "Total iterations: " << totalIterations << endl;
    cout << "Sorted array: ";
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main()
{
    int arr[] = {7,6,2,5,6,4,};
    int n = sizeof(arr) / sizeof(arr[0]);

    optimizedBubbleSort(arr,n);

    return 0;
}
