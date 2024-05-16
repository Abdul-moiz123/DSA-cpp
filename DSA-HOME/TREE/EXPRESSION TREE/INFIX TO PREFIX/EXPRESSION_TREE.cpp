#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;

struct Record {
    char data;
    Record *next;
};

// PUSH FUNCTION
void push(Record** top_ref, char value) {
    Record* ptr = (Record*)malloc(sizeof(Record));
    ptr->data = value;
    ptr->next=NULL;
    if(*top_ref==NULL){
        *top_ref=ptr;
    }
    else{
        ptr->next = *top_ref;
        *top_ref = ptr;
    }
}

// POP FUNCTION
void pop(Record** top_ref) {
    if (*top_ref == NULL) {
        cout << "the tree is empty" << endl;
    }
    else{
        Record* temp = *top_ref;
        *top_ref = (*top_ref)->next;
        free(temp);
    }
}

// OPERATOR PRECEDENCE FUNCTION
int precedence(char op) {
    if (op == '*' || op == '/' || op == '%')
        return 6;
    else if (op == '+' || op == '-')
        return 5;
    else if (op == '<' || op == '>' || op == '>=' || op == '<=')
        return 4;
    else if (op == '==' || op == '!=')
        return 3;
    else if (op == '&&')
        return 2;
    else if (op == '||')
        return 1;                    
    else
        return 0;
}

string rev_str(string eq){
    string rev_string = "";
    for (int i = 0; i < eq.length(); i++){
        if(eq[i]=='('){
            rev_string = ")" + rev_string;
        }
        else if (eq[i] ==')'){
            rev_string = '(' + rev_string;
        }
        else{
            rev_string = eq[i] + rev_string;
        }
    }
    return rev_string;
}


// INFIX TO PREFIX FUNCTION
string infix_To_Prefix(Record**top , string infix) {
    string prefix = "";
    string rev_prefix_eq = "";
    string rev_infix_eq = rev_str(infix);

    for (int i = 0; i < rev_infix_eq.length(); i++) {
        char ch = rev_infix_eq[i];
        if (ch>='a' && ch<='z' || ch>='A' && ch<='Z' || ch>='0' && ch<='9' ) {
            rev_prefix_eq += ch;
        }
        else if (ch == '(') {
            push(top, ch); 
        }
        else if (ch == ')') {
            while (*top != NULL && (*top)->data != '(') {
                rev_prefix_eq += (*top)->data;
                pop(top);
            }
            if (*top != NULL && (*top)->data == '(')
                pop(top); 
        }    
        else {
            while (*top != NULL && precedence(ch) < precedence((*top)->data)) { // if precedence is equal we can still store in stack no need to pop
                rev_prefix_eq += (*top)->data;
                pop(top);
            }
            push(top, ch);
        }
    }
    while (*top != NULL) {
        rev_prefix_eq += (*top)->data;
        pop(top);
    }

    prefix = rev_str(rev_prefix_eq);

    return prefix;
}

// MAIN FUNCTION
int main() {
    Record *top = NULL;
    string infix;
    cout << "enter the expression in infix: ";
    cin >> infix;
    cout << "Infix Expression: " << infix << endl;
    cout << "Prefix Expression: " << infix_To_Prefix(&top , infix) << endl;
    return 0;
}
