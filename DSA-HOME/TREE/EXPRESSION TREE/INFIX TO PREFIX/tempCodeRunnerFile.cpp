#include <iostream>
// #include <stdlib.h>
// #include <algorithm>
// using namespace std;

// struct Record {
//     char data;
//     Record *next;
// };

// void push(Record** top_ref, char value) {
//     Record* ptr = (Record*)malloc(sizeof(Record));
//     ptr->data = value;
//     ptr->next=NULL;
//     if(*top_ref==NULL){
//         *top_ref=ptr;
//     }
//     else{
//         ptr->next = *top_ref;
//         *top_ref = ptr;
//     }
// }

// void pop(Record** top_ref) {
//     if (*top_ref == NULL) {
//         cout << "the tree is empty" << endl;
//     }
//     else{
//         Record* temp = *top_ref;
//         *top_ref = (*top_ref)->next;
//         free(temp);
//     }
// }

// int precedence(char op) {
//     if (op == '*' || op == '/' || op == '%')
//         return 6;
//     else if (op == '+' || op == '-')
//         return 5;
//     else if (op == '<' || op == '>' || op == '>=' || op == '<=')
//         return 4;
//     else if (op == '==' || op == '!=')
//         return 3;
//     else if (op == '&&')
//         return 2;
//     else if (op == '||')
//         return 1;                    
//     else
//         return 0;
// }

// string infix_To_Prefix(Record**top , string infix) {
//     string prefix = "";

//     reverse(infix.begin(), infix.end()); 

//     for(int i = 0 ; i < infix.length() ; i++){
//         if (infix[i] == '(') {
//             infix[i] = ')';
//         }
//         else if (infix[i] == ')') {
//             infix[i] = '(';
//         }
//     }

//     for (int i = 0; i < infix.length(); i++) {
//         char ch = infix[i];
//         if (ch>='a' && ch<='z' || ch>='A' && ch<='Z' || ch>='0' && ch<='9' ) {
//             prefix += ch;
//         }
//         else if (ch == '(') {
//             push(top, ch); 
//         }
//         else if (ch == ')') {
//             while (*top != NULL && (*top)->data != '(') {
//                 prefix += (*top)->data;
//                 pop(top);
//             }
//             if (*top != NULL && (*top)->data == '(')
//                 pop(top); 
//         } 
        
//         else {
//             while (*top != NULL && precedence(ch) <= precedence((*top)->data)) {
//                 prefix += (*top)->data;
//                 pop(top); // Change to use the pop function
//             }
//             push(top, ch);
//         }
//     }

//     while (*top != NULL) {
//         prefix += (*top)->data;
//         pop(top);
//     }

//     reverse(prefix.begin(), prefix.end());
//     return prefix;
// }

// int main() {
//     Record *top = NULL;
//     string infix;
//     cout << "enter the expression in infix: ";
//     cin >> infix;
//     cout << "Infix Expression: " << infix << endl;
//     cout << "Prefix Expression: " << infix_To_Prefix(&top , infix) << endl;
//     return 0;
// }
