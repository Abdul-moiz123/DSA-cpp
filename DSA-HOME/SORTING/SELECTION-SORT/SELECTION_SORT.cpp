#include <iostream>
#include <iomanip>
using namespace std;

void Selection_Sort(int arr[] , int size){
    for (int i = 0; i < size; i++){
        int smallest_value = i;
        for (int j = i+1; j < size; j++){
            if(arr[smallest_value] > arr[j]){
                smallest_value = j;
            }
        }
        int temp = arr[smallest_value];
        arr[smallest_value]=arr[i];
        arr[i]=temp;
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
    
    Selection_Sort(arr , n);    

    cout << "sorted array: ";
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    

   return 0;
}