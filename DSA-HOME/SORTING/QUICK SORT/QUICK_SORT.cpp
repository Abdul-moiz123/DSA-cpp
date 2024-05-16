#include <iostream>
#include <iomanip>
using namespace std;

int partition(int arr[] , int low , int high){
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++){
        if(arr[j] <= pivot){
            i++;
            int temp = arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    i++;
    int temp = arr[i];
    arr[i]=arr[high];
    arr[high]=temp;
    return i;
}

void Quick_Sort(int arr[] , int low , int high){
    if(low < high){
        int pivot_index = partition(arr , low , high);

        Quick_Sort(arr , low , pivot_index-1);
        Quick_Sort(arr , pivot_index+1 , high);
    }
}

int main(){

    int arr[] = {6,3,9,5,2,8};
    int n = sizeof(arr) / sizeof(arr[0]);


    cout << "unsorted array:  ";
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;


    Quick_Sort(arr , 0 , n-1);


    cout << "sorted array:  ";
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

   return 0;
}