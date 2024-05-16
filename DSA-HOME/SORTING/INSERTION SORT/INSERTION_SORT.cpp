#include <iostream>
#include <iomanip>
using namespace std;

void Insertion_Sort(int arr[] , int size){  
    for(int i = 1 ; i < size ; i++){
        int current = arr[i];
        int j = i-1;
        while(j>=0 && current < arr[j]){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=current;
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
    
    Insertion_Sort(arr , n);    

    cout << "sorted array: ";
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    

   return 0;
}