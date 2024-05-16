#include <iostream>
using namespace std;

struct Record{
    int data;
    int height;
    Record *left;
    Record *right;
};

int max(int a, int b){
    if (a > b){
        return a;
    }
    else{
        return b;
    }
}

int height(Record *root_refer){
    if (root_refer == NULL){
        return 0;
    }
    else{
        return max(height(root_refer->left), height(root_refer->right)) + 1;
    }
}

int balanceFact(Record *root_refer){
    if (root_refer == NULL){
        return 0;
    }
                 else{
        return (height(root_refer->left) - height(root_refer->right));
    }
}

Record *rightRotate(Record *root_refer){
    Record *y = root_refer;
    Record *x = y->left;
    Record *t = x->right;

    x->right = y;
    y->left = t;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Record *leftRotate(Record *root_refer){
    Record *y = root_refer;
    Record *x = y->right;
    Record *t = x->left;

    x->left = y;
    y->right = t;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Record *insert(Record *root_refer, int data){
    if (root_refer == NULL){
        Record *new_Record = (Record*)malloc(sizeof(Record));
        new_Record->data = data;
        new_Record->left = NULL;
        new_Record->right = NULL;
        new_Record->height = 1;
        return new_Record;
    }
    else{
        if (data > root_refer->data){
            root_refer->right = insert(root_refer->right, data);
        }
        else{
            root_refer->left = insert(root_refer->left, data);
        }
    }

    root_refer->height =max(height(root_refer->left), height(root_refer->right)) + 1;
    int balance = balanceFact(root_refer);
    

    if (balance > 1 && data < root_refer->left->data){
        return rightRotate(root_refer);
    }

    if (balance < -1 && data > root_refer->right->data){
        return leftRotate(root_refer);
    }

    if (balance > 1 && data > root_refer->left->data){
        root_refer->left = leftRotate(root_refer->left);
        return rightRotate(root_refer);
    }

    if (balance < -1 && data < root_refer->right->data){
        root_refer->right = rightRotate(root_refer->right);
        return leftRotate(root_refer);
    }
    return root_refer;
}

void search(Record *root_refer, int data){
    if (root_refer == NULL){
        cout << "not found";
        return;
    }
    if (root_refer->data == data){
        cout << "found";
        return;
    }
    else{
        if (data > root_refer->data){
            search(root_refer->right, data);
        }
        else{
            search(root_refer->left, data);
        }
    }
}

Record *min(Record *root_refer){
    while (root_refer->left != NULL){
        root_refer = root_refer->left;
    }
    return root_refer;
}

void inorder(Record *root_refer){
    if (root_refer != NULL){
        inorder(root_refer->left);
        cout << root_refer->data << " ";
        inorder(root_refer->right);
    }
}

Record *deleted(Record *root_refer, int data){
    if (root_refer == NULL){
        cout << "not found";
        return root_refer;
    }
    if (data > root_refer->data){
        root_refer->right = deleted(root_refer->right, data);
    }
    else if (data < root_refer->data){
        root_refer->left = deleted(root_refer->left, data);
    }
    else{
        if (root_refer->left == NULL && root_refer->right == NULL){
            delete root_refer;
            root_refer = NULL;
            return root_refer;
        }
        else if (root_refer->right != NULL && root_refer->left == NULL){
            Record *temp = root_refer;
            root_refer = root_refer->right;
            delete temp;
            return root_refer;
        }
        else if (root_refer->right == NULL && root_refer->left != NULL){
            Record *temp = root_refer;
            root_refer = root_refer->left;
            delete temp;
            return root_refer;
        }
        else{
            Record *temp = min(root_refer->right);
            root_refer->data = temp->data;
            root_refer->right = deleted(root_refer->right, temp->data);
        }
    }
    //   NOW
    root_refer->height =max(height(root_refer->left), height(root_refer->right)) + 1;
    int balance = balanceFact(root_refer);
    

    if (balance > 1 && data < root_refer->left->data){
        return rightRotate(root_refer);
    }

    if (balance < -1 && data > root_refer->right->data){
        return leftRotate(root_refer);
    }

    if (balance > 1 && data > root_refer->left->data){
        root_refer->left = leftRotate(root_refer->left);
        return rightRotate(root_refer);
    }

    if (balance < -1 && data < root_refer->right->data){
        root_refer->right = rightRotate(root_refer->right);
        return leftRotate(root_refer);
    }
    return root_refer;
}


int main(){
    Record *root = NULL;
    root = insert(root, 88);
    root = insert(root, 23);
    root = insert(root, 77);
    root = insert(root, 119);
    root = insert(root, 250);
    root = insert(root, 211);
    root = insert(root, 189);
    root = insert(root, 76);
    root = insert(root, 29);
    root = insert(root, 72);
    root = insert(root, 84);
    root = insert(root, 100);
    root = insert(root, 98);

    search(root, 98);
    cout << endl;

    root = deleted(root, 88);

    inorder(root);
    cout << endl;

    return 0;
}
