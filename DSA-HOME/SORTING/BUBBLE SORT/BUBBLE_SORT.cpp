#include <iostream>
#include <iomanip>
using namespace std;

void Bubble_Sort(int arr[] , int size){
    for (int i = 0; i < size-1; i++){
        for (int j = 0; j <size-i-1 ; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

int main(){

    int arr[] = {7,8,3,1,2};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "unsorted array: ";
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    
    Bubble_Sort( arr , n);

    cout << "sorted array: ";
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;


   return 0;
}