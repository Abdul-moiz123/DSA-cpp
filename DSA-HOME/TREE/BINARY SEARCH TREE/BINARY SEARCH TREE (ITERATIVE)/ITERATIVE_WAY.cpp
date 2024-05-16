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
    Record* ptr = (Record*)malloc(sizeof(Record));
    ptr->data=data;
    ptr->left=NULL;
    ptr->right=NULL;
    if(root==NULL){
        root=ptr;
        return root;
    }
    else{
        Record* curr = root;
        while (true){
            if(curr->data > data){
                if(curr->left==NULL){
                    curr->left = ptr;
                    return root;
                }
                else{
                    curr=curr->left;
                }
            }
            else if(curr->data < data){
                if(curr->right==NULL){
                    curr->right = ptr;
                    return root;
                }
                else{
                    curr=curr->right;
                }
            }
            else{
                free(ptr);
                return root;
            }
        }
    }
    return root;
}

// SEARCH FUNCTION
bool search(Record*root , int data){
    if(root==NULL){
        return false;
    }
    else{
        Record* curr = root;
        while(curr!=NULL){
            if(curr->data==data){
                return true;
            }
            else if (curr->data > data){
                curr=curr->left;
            }
            else if (curr->data < data){
                curr=curr->right;
            }
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

// DELETE FUNCTION
Record* delete_value(Record*root , int data){
    if(root==NULL){
        cout << "the tree is empty" << endl;
    }
    Record* curr = root;
    Record* prev = NULL;

    while(curr!=NULL){

        // search the value to delete
        if (root->data > data){
            prev=curr;
            curr=curr->left;    
        }
        else if (root->data < data){
            prev=curr;
            curr=curr->right;
        }
    
        // now we delete the value that we found above code
        else{
            
            // both are null
            if(root->left==NULL && root->right==NULL){
                if(prev==NULL){
                    free(root);
                    return root;
                }
                else if (prev->left==curr){
                    free(curr);
                    prev->left=NULL;
                    return root;
                }
                else if (prev->right==curr){
                    free(curr);
                    prev->right=NULL;
                    return root;
                }
            }

            // left is null
            else if (root->left==NULL && root->right!=NULL){
                if(prev==NULL){
                    root=root->right;
                    free(curr);
                    return root;
                }
                else if (prev->left==curr){
                    prev->left=curr->right;
                    free(curr);
                    return root;
                }
                else if (prev->right==curr){
                    prev->right=curr->right;
                    free(curr);
                    return root;
                }                
            }

            // right is null
            else if (root->left!=NULL && root->right==NULL){
                if(prev==NULL){
                    root=root->left;
                    free(curr);
                    return root;
                }
                else if (prev->left==curr){
                    prev->left=curr->left;
                    free(curr);
                    return root;
                }
                else if (prev->right==curr){
                    prev->right=curr->left;
                    free(curr);
                    return root;
                }                
            }

            // both are not NULL 
            else if (root->left!=NULL && root->right!=NULL){
                Record* curr = findmin(root->right);
                root->data=curr->data;
                // left is null again same code ( for findmin)
                if(prev==NULL){
                    root=root->right;
                    free(curr);
                    return root;
                }
                else if (prev->left==curr){
                    prev->left=curr->right;
                    free(curr);
                    return root;
                }
                else if (prev->right==curr){
                    prev->right=curr->right;
                    free(curr);
                    return root;
                }                
            }
        }
    }
}

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