#include <iostream>
using namespace std;

// Function to print an array
void printArray(int A[], int size)
{
for (int i = 0; i < size; i++)
cout << A[i] << " ";
}

void merge(int array[], int begin, int mid, int end)
{
int i = 0, j = 0, k = begin;
int size_subarr1 = mid - begin + 1;
int size_subarr2 = end - mid;
int subarr1[size_subarr1];
int subarr2[size_subarr2];
//copy left subarray to subarr1
for (int x = 0; x < size_subarr1; x++)
subarr1[x] = array[begin + x];
//copy right subarray to subarr2
for (int x = 0; x < size_subarr2; x++)
subarr2[x] = array[mid +1 + x];
// Traverse both array
while (i<size_subarr1 && j <size_subarr2)
{
// Check if current element of first
// array is smaller than current element
// of second array. If yes, store first
// array element and increment first array
// index. Otherwise do same with second array
if (subarr1[i] < subarr2[j])
array[k++] = subarr1[i++];
else
array[k++] = subarr2[j++];
}

// Store remaining elements of first array
while (i < size_subarr1)
array[k++] = subarr1[i++];

// Store remaining elements of second array
while (j < size_subarr2)
array[k++] = subarr2[j++];
}

void mergeSort(int array[], int const begin, int const end)
{
if (begin >= end)
return; // Returns recursively

auto mid = begin + (end - begin) / 2;
mergeSort(array, begin, mid);
mergeSort(array, mid + 1, end);
merge(array, begin, mid, end);
}

int main()
{
int arr[] = { 25, 34, 12, 4, 17, 4, 13 };
int arr_size = sizeof(arr) / sizeof(arr[0]);

cout << "Given array is \n";
printArray(arr, arr_size);

mergeSort(arr, 0, arr_size - 1);

cout << "\nSorted array is \n";
printArray(arr, arr_size);
return 0;
}