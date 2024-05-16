#include <iostream>
using namespace std;

// ARRAY DECLARTION
const int size = 10;
int array[size];
int heap = 0;

// HEAPIFY FUNCTION
void maxHeapify(int index){
    int parent = (index - 1) / 2;
    while (index > 0 && array[index] > array[parent]){
        int temp = array[index];
        array[index] = array[parent];
        array[parent] = temp;
        index = parent;
        parent = (index - 1) / 2;
    }
}

// INSERT FUNCTION
void insert(int data){
    if (heap == size - 1){
        cout << "array is full";
        return;
    }
    else{
        array[heap] = data;
        maxHeapify(heap);
        heap++;
    }
}

// DELETE FUNCTION
void delete_value(){
    array[0] = array[heap - 1];
    heap--;
    
    int index = 0;
    while (true){
        int left = (2 * index) + 1;
        int right = (2 * index) + 2;
        int largest = index;

        if (left < heap && array[left] > array[largest]){
            largest = left;
        }
        if (right < heap && array[right] > array[largest]){
            largest = right;
        }
        if (largest != index){
            int temp = array[index];
            array[index] = array[largest];
            array[largest] = temp;
            index = largest;
        }
        else{
            break;
        }
    }
}

// PRINT FUNCTION
void print(){
    for (int a = 0; a < heap; a++){
        cout << array[a] << " ";
    }
}

// MAIN FUNCTION
int main(){
    insert(5);
    insert(10);
    insert(3);
    insert(7);
    insert(1);
    delete_value();
    // delete_value();
    // delete_value();
    print();
    return 0;
}