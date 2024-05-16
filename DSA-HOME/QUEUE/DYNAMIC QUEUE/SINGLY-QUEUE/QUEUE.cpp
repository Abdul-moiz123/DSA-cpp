#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

struct Record{
    int data;
    Record* next;
};

// INSERT DUNCTION
void insert(Record**front_end , Record**rear_end){
    Record* ptr = (Record*)malloc(sizeof(Record));
    cout << "enter the data that you want to insert: ";
    cin >> ptr->data;
    ptr->next=NULL;
    if(*front_end==NULL && *rear_end==NULL){
        *front_end=ptr;
        *rear_end=ptr;
        cout << "The Record has been inserted" << endl;
        return;
    }
    else{
        (*rear_end)->next=ptr;
        *rear_end=ptr;
        cout << "The Record has been inserted" << endl;
        return;
    }
}

// SEARCH DUNCTION
void search(Record**front_end , Record**rear_end){
    if(*front_end==NULL && *rear_end==NULL){
        cout << "The list is empty" << endl;
        return;   
    }
    Record* curr = *front_end;
    int tosearch;
    cout << "enter the data that ypu want to search: ";
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
        cout << "The data not found in the list" << endl;
        return;
    }
}

// PRINT DUNCTION
void print(Record**front_end , Record**rear_end){
    if(*front_end==NULL && *rear_end==NULL){
        cout << "The list is empty" << endl;
        return;   
    }
    Record* curr = *front_end;
    while (curr!=NULL){
        cout << "The data is found to be: " << curr->data << endl;
        cout << endl;
        curr=curr->next;
    }
}

// DELETE VALUE DUNCTION
void delete_value(Record**front_end , Record**rear_end){
    Record* curr = *front_end;
    if(*front_end==NULL && *rear_end==NULL){
        cout << "The list is empty" << endl;
        return;   
    }
    if(*front_end==*rear_end){
        *front_end=NULL;
        *rear_end=NULL;
    }
    else{
        *front_end=curr->next;
    }
    free(curr);
    cout << "The data has been deleted" << endl;
}

// DELETE LIST DUNCTION
void delete_list(Record**front_end , Record**rear_end){
    if(*front_end==NULL && *rear_end==NULL){
        cout << "The list is empty" << endl;
        return;   
    }
    Record* curr = *front_end;
    Record* all;
    while (curr!=NULL){
        all=curr->next;
        free(curr);
        curr=all;
    }
    *front_end=NULL;
    *rear_end=NULL;
    cout << "The list has been deleted" << endl;
}

// MAIN FUNCTION
int main(){
    Record* front = NULL;
    Record* rear = NULL;
    
    int select;
    cout << "enter 0 to exit" << endl; 
    cout << "enter 1 to insert" << endl; 
    cout << "enter 2 to search" << endl; 
    cout << "enter 3 to print" << endl; 
    cout << "enter 4 to delete value" << endl; 
    cout << "enter 5 to delete list" << endl; 
    cout << "enter your choice: ";
    cin >> select;

    while (select!=0){
        if(select==1){insert(&front,&rear);}
        if(select==2){search(&front,&rear);}
        if(select==3){print(&front,&rear);}
        if(select==4){delete_value(&front,&rear);}
        if(select==5){delete_list(&front,&rear);}
        cout << "enter your choice again: ";
        cin >> select;
    }
     
   return 0;
}