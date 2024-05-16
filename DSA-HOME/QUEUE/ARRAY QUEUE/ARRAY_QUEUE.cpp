#include <iostream>
#include <iomanip>
using namespace std;

const int size = 10;
int arr[size];
int front = -1;
int rear = -1;

void enqueue(int data) {
    if (rear == size - 1) {
        cout << "The queue is full " << endl;
        return;
    } 
    else if (front == -1 && rear == -1) {
        front = rear = 0;
        arr[rear] = data;
    } 
    else {
        rear++;
        arr[rear] = data;
    }
}

void dequeue() {
    if (front == -1 && rear == -1) {
        cout << "The queue is empty. Cannot dequeue." << endl;
        return;
    } else if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
}

void print() {
    if (front == -1 && rear == -1) {
        cout << "The queue is empty." << endl;
        return;
    }
    for (int i = front; i <= rear; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    enqueue(34);
    enqueue(44);
    enqueue(54);
    enqueue(64);
    enqueue(74);
    enqueue(84);
    enqueue(94);
    
    dequeue();
    dequeue();

    print();

    return 0;
}
