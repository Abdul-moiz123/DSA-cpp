#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

struct Record{
    int data;
    Record* next;
};

// PUSH FUNCTION
void push(Record**top , char data){
    Record* ptr = (Record*)malloc(sizeof(Record));
    ptr->data=data;
    ptr->next=NULL;
    if(*top==NULL){
        *top=ptr;
    }
    else{
        ptr->next=*top;
        *top=ptr;
    }
}

// POP FUNCTION
void pop(Record**top){
    if(*top==NULL){
        cout << "the stack is empty" << endl;
        return;
    }
    else{
        Record* curr = *top;
        *top=curr->next;
        free(curr);
    }
}

// OPERATOR PRECEDENCE
int precedence(char op){
    if(op=='*' || op=='/' || op=='%')return 6;
    if(op=='+' || op=='-')return 5;
    if(op=='<' || op=='>' || op=='<=' || op=='>=')return 4;
    if(op=='==' || op=='!=')return 3;
    if(op=='&&')return 2;
    if(op=='||')return 1;
    return 0;
}

// INFIX TO POSTFIX FUNCTION
string infix_to_postfix(Record**top , string infix){
    string postfix = "";

    for (int i = 0; i < infix.length(); i++){
        char ch = infix[i];

        if(ch>='a' && ch<='z' || ch>='A' && ch<='Z' || ch>='0' && ch<='9'){
            postfix+=ch;
        }
        else if (ch=='('){
            push(top,ch);
        }
        else if (ch==')'){
            while (*top!=NULL && (*top)->data!='('){
                postfix+=(*top)->data;
                pop(top);
            }
            if(*top!=NULL){ // "(" pop this 
                pop(top);
            }
        }
        else{
            if(*top!=NULL && precedence(ch)<=precedence((*top)->data)){
                postfix+=(*top)->data;
                pop(top);
            }
            push(top,ch);
        }
    }
    
    // remaining will add in postfix till null
    while(*top!=NULL){
        postfix+=(*top)->data;
        pop(top);       
    }

    return postfix;
}

// MAIN FUNCTION
int main(){

    Record* top = NULL;
    string infix;
    cout << "enter the expression in infix: ";
    cin >> infix;
    cout << "INFIX: " << infix << endl;
    cout << "POSTFIX: " << infix_to_postfix(&top , infix) << endl;

   return 0;
}