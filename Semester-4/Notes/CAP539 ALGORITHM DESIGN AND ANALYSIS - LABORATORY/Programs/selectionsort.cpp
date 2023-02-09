#include <iostream>
using namespace std;
void selectionsort(int arr[], int size)
{
    for(int i=0; i< (size-1);i++){
        for(int j = i+1; j<size;j++){
            if(arr[i]>arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void print(int arr[], int size){
    for(int i=0; i < size;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[] = {7, 3, 5, 13, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    selectionsort(arr,size);
    cout<<"Sorted Array is : \n";
    print(arr, size);
    return 0;

}