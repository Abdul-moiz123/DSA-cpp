#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

struct Record{
    int data;
    Record* left;
    Record* right;
};

// INSERT FUNCTION
Record* insert(Record*root , int data){
    if(root==NULL){
        Record* ptr = (Record*)malloc(sizeof(Record));
        ptr->data=data;
        ptr->left=NULL;
        ptr->right=NULL;
        return ptr;
    }
    else{
        if(root->data > data){
            root->left = insert(root->left , data);
        }
        else{
            root->right = insert(root->right , data);
        }
    }
    return root;
}

// SEARCH FUNCTION
bool search(Record*root , int data){
    if(root==NULL){
        return false;
    }
    else if(root->data == data){
        return true;
    }
    else{
        if(root->data > data){
            search(root->left,data);
        }
        else{
            search(root->right,data);
        }
    }
    return false;
}

// INORDER FUNCTION
void inOrder(Record*root){
    if(root!=NULL){
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

// PREORDER FUNCTION
void preOrder(Record*root){
    if(root!=NULL){
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

// POSTORDER FUNCTION
void postOrder(Record*root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

// FINDMIN FUNCTION
Record* findmin(Record*root){
    while (root->left!=NULL){
        root=root->left;
    }
    return root;
}


// FINDMAX FUNCTION
Record* findmax(Record*root){
    while (root->right!=NULL){
        root=root->right;
    }
    return root;
}

// DELETE VALUE FUNCTION
Record* delete_value(Record*root , int data){
    if(root==NULL){
        cout << "the tree is empty" << endl;
    }
    else if (root->data > data){
        root->left = delete_value(root->left , data);
    }
    else if (root->data < data){
        root->right = delete_value(root->right , data);
    }
    else{
        if(root->left==NULL && root->right==NULL){
            free(root);
            root=NULL;
        }
        else if (root->left==NULL){
            Record* temp = root;
            root=root->right;
            free(temp);
            return root;
        }
        else if (root->right==NULL){
            Record* temp = root;
            root=root->left;
            free(temp);
            return root;
        }
        else if(root->left!=NULL && root->right!=NULL){
            Record* temp = findmin(root->right);
            root->data=temp->data;
            root->right = delete_value(root->right , temp->data);
        }   
    }
    return root;
}

// MAIN FUNCTION
int main(){
    Record* root = NULL;
    int select;
    cout << "enter 0 to exit" << endl;
    cout << "enter 1 to insert" << endl;
    cout << "enter 2 to search" << endl;
    cout << "enter 3 to inOrder" << endl;
    cout << "enter 4 to preOrder" << endl;
    cout << "enter 5 to postOrder" << endl;
    cout << "enter 6 to delete value" << endl;
    cout << "enter your choice: ";
    cin >> select;

    while (select!=0){
        if(select==1){
            int data;
            cout << "enter the data that you want to insert: ";
            cin >> data;
            root=insert(root,data);
        }
        if(select==2){
            int data;
            cout << "enter the data that you want to search: ";
            cin >> data;
            search(root,data);
            if(search(root,data)){
                cout << "found the data" << endl;
            }
            else{
                cout << "not found the data" << endl;
            }
        }
        if(select==3){
            inOrder(root);
            cout << endl;
        }
        if(select==4){
            preOrder(root);
            cout << endl;
        }
        if(select==5){
            postOrder(root);
            cout << endl;
        }
        if(select==6){
            int data;
            cout << "enter the data that you want to delete: ";
            cin >> data;
            delete_value(root,data);
        }
        cout << "enter your choice again: ";
        cin >> select;        
    }
    
   return 0;
}

