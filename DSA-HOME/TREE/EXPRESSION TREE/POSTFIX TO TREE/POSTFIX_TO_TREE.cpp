#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

// STRUCT FOR THE MAIN TREE
struct Main_Tree{
    char value;
    Main_Tree* left;
    Main_Tree* right;
};

// STRUCT FOR THE SUB TREE THAT ADDED TO THE STACK AND THAN ADD TO THE MAIN TREE
struct Sub_Tree{
    Main_Tree* node; // subtree node of maintree 
    Sub_Tree* next;
};

Sub_Tree* top = NULL;

// PUSH FUNCTION --> PUSH THE POINTER OF THE NODE TO THE STACK --> STORE IN POINTER THAN STORE INTO STACK
void push(Main_Tree* node){
    Sub_Tree* ptr = (Sub_Tree*)malloc(sizeof(Sub_Tree));
    ptr->node=node; // subtree node 
    //  STEP TO MOVE THE PTR ON THE TOP OF THE STACK
    ptr->next=top;
    top=ptr;
}

// RETURE TYPE POINTER --> MAIN_TREE* -->  POP FUNCTION -->
Main_Tree* pop(){
    if(top==NULL){
        return NULL;
    }
    // POP VALUE WILL RETURN INTO NODE POINTER
    Main_Tree* node = top->node;  //( store the pop value)
    // NOW POP OUT THE VALUE
    Sub_Tree* temp = top;
    top=temp->next;
    free(temp);
    // RETURN THE POP VALUE
    return node;
}  

Main_Tree* postfix_to_tree(string postfix){
    for (int i = 0; i < postfix.length(); i++){
        char ch = postfix[i];
        // FOR OPERAND WE SIMPLY PUSH THE POINTER OF THAT OPERAND INTO THE STACK
        if(ch>='a' && ch<='z' || ch>='A' && ch<='Z'){
            Main_Tree* node = (Main_Tree*)malloc(sizeof(Main_Tree));
            node->value=ch;
            node->left=NULL;
            node->right=NULL;
            push(node);
        }
        // FOR OPERATOR --> WE PASS THE POINTER OF THAT WITH POP ( RIGHT TO LEFT) FOR THE STACK AND THAN PUSH THE SUBTREE TO THE STACK 
        else{
            Main_Tree* node = (Main_Tree*)malloc(sizeof(Main_Tree));
            node->value=ch;
            node->right=pop();
            node->left=pop();
            push(node);
        }
    }
    Main_Tree* root = pop();
    return root;
}

// POSTORDER FUNCTION
void print(Main_Tree* root){
    if(root!=NULL){
        print(root->left);
        print(root->right);
        cout << root->value << " ";
    }
}

// MAIN FUNCTION
int main(){
// INPUT:-
//   "abc*d/x*+fd*-";
    string postfix;
    cout << "enter the expression in postfix: ";
    cin >> postfix;
    Main_Tree* root = postfix_to_tree(postfix);
    print(root);
   return 0;
}
