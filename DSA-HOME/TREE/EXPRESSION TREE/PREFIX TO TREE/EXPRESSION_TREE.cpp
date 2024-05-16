#include <iostream>
#include <stdlib.h>
using namespace std;

struct Main_Tree{
  char value;
  Main_Tree *left;
  Main_Tree *right;
};

struct Sub_Tree{
  Main_Tree *node;
  Sub_Tree *next;
};

Sub_Tree *top = NULL;

void push(Main_Tree *node){
  Sub_Tree *ptr = (Sub_Tree *)malloc(sizeof(Sub_Tree));
  ptr->node = node;
  ptr->next = top;
  top = ptr;
}

Main_Tree *pop(){
  if (top == NULL){
    return NULL;
  }
  Main_Tree *node = top->node;
  Sub_Tree *temp = top;
  top = top->next;
  free(temp);
  return node;
}

string reverse_Str(string str){
  string revStr;
  for (int i = 0; i < str.length(); i++){
    if(str[i]=='('){
      revStr = ')' + revStr;
    }
    else if(str[i]==')'){
      revStr = '(' + revStr;
    }
    else{
      revStr = str[i] + revStr;
    }
  }
  return revStr;
}

Main_Tree* ExpressionTree(string prefix){
  string prefix_org = ""; 
  string rev_Prefix = reverse_Str(prefix);
  
  for (int i = 0; i < rev_Prefix.length(); i++){
    char ch = rev_Prefix[i];
    if ((ch >+'a' && ch <='z') || (ch >='A' && ch <='Z')){
      Main_Tree *node = (Main_Tree *)malloc(sizeof(Main_Tree));
      node->value = ch;
      node->left =NULL; 
      node->right = NULL;
      push(node);
    }
    else{
      Main_Tree *node = (Main_Tree *)malloc(sizeof(Main_Tree));
      node->value = ch;
      node->right = pop();
      node->left = pop();
      push(node);
    }
  }
  prefix_org = reverse_Str(rev_Prefix);
  Main_Tree *root = pop();
  return root;
}

void preOrder(Main_Tree *root){
  if (root == NULL){
    return;
  }
  cout << root->value << " ";
  preOrder(root->left);
  preOrder(root->right);
}

int main(){
  string prefix = "&<+a*b-cdx|!cy<+xy5";
  Main_Tree *root = ExpressionTree(prefix);
  preOrder(root);
}