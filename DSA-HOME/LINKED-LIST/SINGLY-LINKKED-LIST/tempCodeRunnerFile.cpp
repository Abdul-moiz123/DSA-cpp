void delete_value(Record** head_ref){
    Record* curr = *head_ref;
    Record* prev;
    int todel;
    cout << "enter the roll no that you want to delete: ";
    cin >> todel;

    if(*head_ref==NULL){
        cout << "the list is empty" << endl;
    }

    if(curr!=NULL && curr->roll_no==todel){
        *head_ref=curr->next;
        free(curr);
    }

    while(curr!=NULL && curr->roll_no!=todel){
        prev=curr;
        curr=curr->next;
    }

    if(curr->next==NULL){
        prev->next=NULL;
        free(curr);
    }

    if(curr==NULL){
        cout << "not found" << endl;
    }

    prev->next=curr->next;
    free(curr);
}
