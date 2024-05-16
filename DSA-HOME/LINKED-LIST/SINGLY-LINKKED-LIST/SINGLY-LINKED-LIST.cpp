#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

struct Record{
    int roll_no;
    float GPA;
    int index;
    Record* next;
};

// SORTED INSERT FUNCTION
void sorted_insert(Record** head_ref) {
    Record* ptr = (Record*)malloc(sizeof(Record));
    cout << "enter the roll no that you want to insert: ";
    cin >> ptr->roll_no;
    cout << "enter the GPA that you want to insert: ";
    cin >> ptr->GPA;
    ptr->next = NULL;
    ptr->index = 0;

    if (*head_ref == NULL) {
        *head_ref = ptr;
    } 
    else if (ptr->roll_no < (*head_ref)->roll_no) {
        ptr->next = *head_ref;
        *head_ref = ptr;

        Record* ind = ptr->next;
        while (ind != NULL) {
            ind->index++;
            ind = ind->next;
        }
    }
    else {
        Record* curr = *head_ref;
        while (curr->next != NULL && ptr->roll_no > curr->next->roll_no) {
            curr = curr->next;
        }
        ptr->next = curr->next;
        curr->next = ptr;

        ptr->index=curr->index+1;
        Record* ind1 = ptr->next;
        while (ind1 != NULL) {
            ind1->index++;
            ind1 = ind1->next;
        }
    }
}


// INSERT FUNCTION
void insert(Record**head_ref){
    Record* ptr = (Record*)malloc(sizeof(Record));
    cout << "enter the roll no that you want to insert: ";
    cin >> ptr->roll_no;
    cout << "enter the GPA that you want to insert: ";
    cin >> ptr->GPA;
    ptr->next=NULL;
    if(*head_ref==NULL){
        *head_ref=ptr;
        cout << "The Record has been inserted" << endl;
    }
    else{
        Record* curr = *head_ref;
        while (curr->next!=NULL){
            curr=curr->next;
        }
        curr->next=ptr;
        cout << "The Record has been inserted" << endl;
    }
}

// SEARCH FUNCTION
void search(Record**head_ref){
    if(*head_ref==NULL){
        cout << "the list is empty" << endl;
        return;
    }
    Record* curr = *head_ref;
    int tosearch;
    cout << "enter the roll no that you want to search: ";
    cin >> tosearch;
    while (curr!=NULL){
        if(curr->roll_no==tosearch){
            cout << "the roll no is found to be: " << curr->roll_no << endl;
            cout << "the GPA is found to be: " << curr->GPA << endl;
            cout << endl;
            break;
        }
        else{
            curr=curr->next;
        }
    }
    if(curr==NULL || curr->roll_no!=tosearch){
        cout << "the Record has not been found in the list" << endl;
        return;
    }
}

// PRINT FUNCTION
void print(Record**head_ref){
    if(*head_ref==NULL){
        cout << "the list is empty" << endl;
        return;
    }
    Record* curr = *head_ref;
    while (curr!=NULL){
        cout << "index: " << curr->index << endl;
        cout << "the roll no is found to be: " << curr->roll_no << endl;
        cout << "the GPA is found to be: " << curr->GPA << endl;
        cout << endl;
        curr=curr->next;
    }
}

// DELETE VALUE FUNCTION
void delete_value(Record**head_ref){
    if(*head_ref==NULL){
        cout << "the list is empty" << endl;
        return;
    }
    Record* curr = *head_ref;
    Record* prev = NULL;
    int todel;
    cout << "enter the roll no that you want to delete: ";
    cin >> todel;
    if(curr->roll_no==todel){
        *head_ref=curr->next;
        free(curr);

        Record* ind = *head_ref;
        while (ind!=NULL){
            ind->index--;
            ind=ind->next;
        }
        
        cout << "The Record has been deleted" << endl;
        return;
    }
    while(curr!=NULL && curr->roll_no!=todel){
        prev=curr;
        curr=curr->next;
    }
    if(curr==NULL){
        cout << "The Record has not been found in the list" << endl;
        return;
    }
    if(curr->next==NULL){
        prev->next=NULL;
        cout << "The Record has been deleted" << endl;
        return;
    }
    else{
        prev->next=curr->next;
    }
    free(curr);

    Record* ind1 = prev->next;
    while (ind1!=NULL){
        ind1->index--;
        ind1=ind1->next;
    }
    
    cout << "The Record has been deleted" << endl;
}

// DELETE LIST FUNCTION
void delete_list(Record**head_ref){
    if(*head_ref==NULL){
        cout << "the list is already empty" << endl;
        return;
    }
    Record* curr = *head_ref;
    Record* all;
    while(curr!=NULL){
        all=curr->next;
        free(curr);
        curr=all;
    }
    *head_ref=NULL;
    cout << "The list has been deleted" << endl;
}

// COUNT NODE FUNCTION
int count_node(Record * head_ref){
    if(head_ref==NULL){
        return 0;
    }
    int count = 1;
    Record* curr = head_ref;
    while (curr!=NULL){
        count++;
        curr=curr->next;
    }
    return count;
}

// MAIN FUNCTION
int main(){
    Record* head = NULL;
    int select;
    cout << " enter 0 to exit" << endl;
    cout << " enter 1 to insert" << endl;
    cout << " enter 2 to search" << endl;
    cout << " enter 3 to print" << endl;
    cout << " enter 4 to delete_value" << endl;
    cout << " enter 5 to delete_list" << endl;
    cout << " enter 6 to get total no of nodes" << endl;
    cout << " enter your choice: ";
    cin >> select;
    while (select!=0){
        if(select==1){sorted_insert(&head);}
        if(select==2){search(&head);}
        if(select==3){print(&head);}
        if(select==4){delete_value(&head);}
        if(select==5){delete_list(&head);}
        if(select==6){int toatl = count_node(head) - 1; cout << toatl << endl;}
        cout << " enter your choice again: ";
        cin >> select;
    }
   return 0;
}