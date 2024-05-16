#include <iostream>
#include <iomanip>
using namespace std;

// INSERT FUNCTION
void insert(int array[] , int size , int key){
    int index = key % size;
    if(array[index]==-1){
        array[index]=key;
    }
    else{
        int new_index = (index+1)%size;
        while (array[new_index]!=-1 && index!=new_index){
            new_index = (new_index+1)%size;
        }
        if(new_index==index){
            cout << "the list is full" << endl;
        }
        else{
            array[new_index]=key;
        }        
    }
}

// SEARCH FUNCTION
void search(int array[] , int size , int key){
    int index = key % size;
    if(array[index]==key){
        cout << "found the data" << endl;
    }
    else{
        int new_index = (index+1)%size;
        while (array[new_index]!=-1 && array[new_index]!=key &&index!=new_index){
            new_index = (new_index+1)%size;
        }
        if(array[new_index]==key){
            cout << "found the data" << endl;
        }
        else{
            cout << "not found the data in the list" << endl;
        }
    }
}

// PRINT FUNCTION
void print(int array[] , int size){
    for (int i = 0; i < size; i++){
        cout << "the data is: " << array[i] << endl;
    }
}

// MAIN FUNCTION
int main(){
    int size;
    cout << "enter the size of the array: ";
    cin >> size;
    int array[size];

    for (int i = 0; i < size; i++){
        array[i]=-1;
    }

    int key;
    for (int i = 0; i < size; i++){
        cout << "enter the data: ";
        cin >> key;
        insert(array , size , key);
    }

    int tosearch;
    cout << "enter the data that you want to search: ";
    cin >> tosearch;
    search(array , size , tosearch);

    int yes;
    cout << "enter 1 to print the list or 0 to exit: ";
    cin >> yes;
    if(yes==1){
        print(array , size); 
    }
    else{
        cout << "thanks for using the program " << endl;
    }

   return 0;
}