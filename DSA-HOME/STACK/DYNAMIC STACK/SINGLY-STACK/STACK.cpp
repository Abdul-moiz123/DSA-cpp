#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

struct Record{
    int data;
    Record* next;
};

// INSERT FUNCTION
void insert(Record**top){
    Record* ptr = (Record*)malloc(sizeof(Record));
    cout << "enter the data that you want to insert: ";
    cin >> ptr->data;
    ptr->next=NULL;
    if(*top==NULL){
        *top=ptr;
        cout << "The data has been inserted" << endl;
        return;
    }
    else{
        ptr->next=*top;
        *top=ptr;
        cout << "The data has been inserted" << endl;
        return;
    }
}

// SEARCH FUNCTION
void search(Record**top){
    if(*top==NULL){
        cout << "The list has been empty" << endl;
        return;
    }
    Record* curr = *top;
    int tosearch;
    cout << "enter the data that you want to search: ";
    cin >> tosearch;
    while (curr!=NULL){
        if(curr->data==tosearch){
            cout << "The data is found to be: " << curr->data << endl;
            cout << endl;
            break;
        }
        else{
            curr=curr->next;
        }
    }
    if(curr==NULL || curr->data!=tosearch){
        cout << "The data has not been found in the list" << endl;
        return;
    }
}

// PRINT FUNCTION
void print(Record**top){
    if(*top==NULL){
        cout << "The list has been empty" << endl;
        return;
    }
    Record* curr = *top;
    while (curr!=NULL){
        cout << "The data is found to be: " << curr->data << endl;
        cout << endl;
        curr=curr->next;
    }
}

// DELETE VALUE FUNCTION
void delete_value(Record**top){
    if(*top==NULL){
        cout << "The list has been empty" << endl;
        return;
    }
    Record* curr = *top;
    *top=curr->next;
    free(curr);
    cout << "The data has been deleted" << endl;
}

// DELETE LIST FUNCTION
void delete_list(Record**top){
    if(*top==NULL){
        cout << "The list has been empty" << endl;
        return;
    }
    Record* curr = *top;
    Record* all;
    while (curr!=NULL){
        all=curr->next;
        free(curr);
        curr=all;
    }
    *top=NULL;
    cout << "the list has been deleted" << endl;
}

// MAIN FUNCTION
int main(){
    Record* top = NULL;
    
    int select;
    cout << "enter 0 to exit" << endl;
    cout << "enter 1 to insert" << endl;
    cout << "enter 2 to search" << endl;
    cout << "enter 3 to print" << endl;
    cout << "enter 4 to delete_value" << endl;
    cout << "enter 5 to delete_list" << endl;
    cout << "enter your choice: ";
    cin >> select;
    cout << endl;

    while (select!=0){
        if(select==1){insert(&top);}
        if(select==2){search(&top);}
        if(select==3){print(&top);}
        if(select==4){delete_value(&top);}
        if(select==5){delete_list(&top);}
        cout << "enter your choice again: ";
        cin >> select;
        cout << endl;
    }
    
   return 0;
}