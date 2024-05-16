#include <iostream>
using namespace std;

// ARRAY DECLARATION
const int size = 10;
int array[size];
int heap = 0;

// HEAPIFY FUNCTION
void minHeapify(int index){
    int parent = (index - 1) / 2;
    while (parent >= 0 && array[parent] > array[index]){
        int temp = array[index];
        array[index] = array[parent];
        array[parent] = temp;
// if sawp work7u that its check the parent of the swap data that is maintain heap algo or not (RECURSIVE)
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
        minHeapify(heap);
        heap++;
    }
}

// DELETE FUNCTION
void delete_value() {
    if (heap == 0) {
        cout << "Heap is empty" << endl;
        return;
    }
    // Swap the root with the last one data
    array[0] = array[heap - 1];
    heap--;

    int index = 0;
    while (true) {
        int left = (2 * index) + 1;
        int right = (2 * index) + 2;
        int smallest = index;

        if (left < heap && array[left] < array[smallest]) {
            smallest = left;
        }
        if (right < heap && array[right] < array[smallest]) {
            smallest = right;
        }
        if (smallest != index) {
            int temp = array[index];
            array[index]=array[smallest];
            array[smallest]=temp;
            index = smallest;
        } 
        else {
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

int main(){

    insert(5);
    insert(10);
    insert(3);
    insert(7);
    insert(1);
    insert(12);
    insert(6);
    delete_value();
    // delete_value();
    // delete_value();
    print();
    return 0;
}