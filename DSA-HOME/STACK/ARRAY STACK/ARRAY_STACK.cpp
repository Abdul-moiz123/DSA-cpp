#include <iostream>
#include <iomanip>
using namespace std;

const int size = 10;
int arr[size];
int top = 0;

void push(int data){
    if(top == size-1){
        cout << "The stack is full " << endl;
        return;
    }
    arr[top] = data;
    top++;
}

void pop(){
    if(top == 0){
        cout << "The stack is empty. Cannot pop." << endl;
        return;
    }
    top--;
}

void print() {
    if (top == 0) {
        cout << "The stack is empty." << endl;
        return;
    }
    for (int i = 0; i < top; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){

    push(34);
    push(44);
    push(54);
    push(64);
    push(74);
    push(84);

    pop();
    pop();

    print();
   return 0;
}
