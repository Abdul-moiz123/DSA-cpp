#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

struct Student{
    int std_id;
    Student* std_next;
};

struct Course{
    int cou_id;
    Course* cou_next;
    Student* std_start;
};

Course* head = NULL;

// SEARCH COURSE
bool search_course(int id){
    if(head==NULL){
        return false;
    }
    Course* curr = head;
    while (curr!=NULL){
        if(curr->cou_id==id){
            return true;
        }
        else{
            curr=curr->cou_next;
        }
    }
    return false;
}

// INSERT COURSE
void insert_course(int id){
    if(search_course(id)){
        cout << "The Course is already present in the list" << endl;
        return;
    }
    Course* ptr = (Course*)malloc(sizeof(Course));
    ptr->cou_id=id;
    ptr->cou_next=NULL;
    ptr->std_start=NULL;
    if(head==NULL){
        head=ptr;
    }
    else{
        Course* curr = head;
        while (curr->cou_next!=NULL){
            curr=curr->cou_next;
        }
        curr->cou_next=ptr;
    }
}

// PRINT COURSE LIST
void print_course_list(){
    if(head==NULL){
        cout << "The Course list is empty" << endl;
        return;
    }
    Course* curr = head;
    while (curr!=NULL){
        cout << endl;
        cout << "the Course id is: " << curr->cou_id << endl;
        cout << endl;
        curr=curr->cou_next;
    }   
}

// DELETE COURSE FROM A LIST
void delete_course(int id){
    if(head==NULL){
        cout << "The Course list is empty" << endl;
        return;
    }    
    if(search_course(id)){
        Course* curr = head;
        Course* prev = NULL;

        if(curr->cou_id==id){
            head=curr->cou_next;
            free(curr);
            cout << "The Course has been deleted" << endl;
            return;
        }
        while (curr!=NULL && curr->cou_id!=id){
            prev=curr;
            curr=curr->cou_next;
        }
        if(curr->cou_next==NULL){
            prev->cou_next=NULL;
            free(curr);
            cout << "The Course has been deleted" << endl;
            return;    
        }
        prev->cou_next=curr->cou_next;
        free(curr);
        cout << "The Course has been deleted" << endl;        
    }
}

// DELETE COURSE LIST
void delete_course_list(){
    if(head==NULL){
        cout << "The Course list is already empty" << endl;
        return;
    }
    Course* curr = head;
    Course* all;
    while (curr!=NULL){
        all=curr->cou_next;
        free(curr);
        curr=all;
    }
    head=NULL;
    cout << "The Course list has been deleted" << endl;
}

// SEARCH STUDENT
bool search_student(int cu_id , int st_id){
    if(head==NULL){
        return false;
    }
    if(search_course(cu_id)){
        Course* curr = head;
        while(curr!=NULL){
            if(curr->cou_id==cu_id){
                Student* curr1 = curr->std_start;
                while(curr1!=NULL){
                    if(curr1->std_id==st_id){
                        return true;
                    }
                    else{
                        curr1=curr1->std_next;
                    }
                }
                return false;
            }
            else{
                curr=curr->cou_next;
            }
        }
        return false;
    }
    return false;
}

// INSERT STUDENT TO A COURSE
void insert_student(int cu_id , int st_id){
    if(search_course(cu_id)){

        if(search_student(cu_id , st_id)){
            cout << "The Student is already present in the course" << endl;
            return;
        }
        Course* curr = head;
        while (curr!=NULL){
            if(curr->cou_id==cu_id){
                break;
            }
            else{
                curr=curr->cou_next;
            }
        }

        if(curr!=NULL){
            Student* ptr1 = (Student*)malloc(sizeof(Student));
            ptr1->std_id=st_id;
            ptr1->std_next=NULL;
            if(curr->std_start==NULL){
                curr->std_start=ptr1;
            }
            else{
                Student* curr1 = curr->std_start;
                while (curr1->std_next!=NULL){
                    curr1=curr1->std_next;
                }
                curr1->std_next=ptr1;
            }
        }
        else{
            cout << "COurse not found" << endl;
            return;
        }
    }
    else{
        cout << "COurse not found" << endl;
        return;
    }
}

// PRINT STUDENT LIST OF A COURSE
void print_student_list_of_a_course(int cu_id){
    if(search_course(cu_id)){
        Course* curr = head;
        while (curr!=NULL){
            if(curr->cou_id==cu_id){
                break;
            }
            else{
                curr=curr->cou_next;
            }
        }
        if(curr!=NULL){
            Student* curr1 = curr->std_start;
            while (curr1!=NULL){
                cout << endl;
                cout << "the student is: " << curr1->std_id << endl;
                cout << endl;
                curr1=curr1->std_next;
            }
        }
        else{
            cout << "Course not found" << endl;
            return;
        }
    }
    else{
        cout << "Course not found" << endl;
        return;
    }
}

// DELETE STUDENT FROM A COURSE
void delete_student(int cu_id , int st_id){
    if(search_course(cu_id)){
        Course* curr = head;
        while (curr!=NULL){
            if(curr->cou_id==cu_id){
                break;
            }
            else{
                curr=curr->cou_next;
            }
        }
        if(curr!=NULL){
            Student* curr1 = curr->std_start;
            Student* prev1 = NULL;
            if(curr1->std_id==st_id){
                curr->std_start=curr1->std_next;
                free(curr1);
                cout << "The Student has been deleted" << endl;
                return;
            }
            while (curr1!=NULL && curr1->std_id!=st_id){
                prev1=curr1;
                curr1=curr1->std_next;
            }
            if(curr1==NULL){
                cout << "student not found" << endl;
                return;
            }
            if(curr1->std_next==NULL){
                prev1->std_next=NULL;
                free(curr1);
                cout << "The Student has been deleted" << endl;
                return;
            }
            prev1->std_next=curr1->std_next;
            free(curr1);
            cout << "The Student has been deleted" << endl;
        }
        else{
            cout << "course not found" << endl;
            return;     
        }
    }
    else{
        cout << "course not found" << endl;
        return;
    }
}

// DELETE STUDENT FROM ALL COURSE
void delete_student_all_course(int st_id){
    Course* curr = head;

    while(curr!=NULL){       
        Student* curr1 = curr->std_start;
        Student* prev1 = NULL;

        while(curr1!=NULL){

            if (curr1->std_id == st_id) {
                if (prev1 == NULL) { 
                    curr->std_start = curr1->std_next;
                    free(curr1);
                    curr1= curr->std_start;
                } else {
                    prev1->std_next = curr1->std_next;
                    free(curr1);
                    curr1 = prev1->std_next;
                }
            } else {
                prev1 = curr1;
                curr1 = curr1->std_next;
            }
        }
        curr=curr->cou_next;
    }
}

// MAIN FUNCTION
int main(){
    int select;
    cout << "enter 0 to exit the program" << endl;
    cout << "enter 1 to insert the course" << endl;
    cout << "enter 2 to search the course" << endl;
    cout << "enter 3 to print the course list" << endl;
    cout << "enter 4 to delete the course" << endl;
    cout << "enter 5 to deleted the course list" << endl;
    cout << "enter 6 to insert the student" << endl;
    cout << "enter 7 to search the student" << endl;
    cout << "enter 8 to print the student list" << endl;
    cout << "enter 9 to delete the student from a course" << endl;
    cout << "enter 10 to delete the student from all course" << endl;
    cout << "enter your choice: ";
    cin >> select;
    while (select!=0){
        if(select==1){
            int course_id;
            cout << "enter the course id that you want to insert: ";
            cin >> course_id;
            insert_course(course_id);
        }
        if(select==2){
            int course_id;
            cout << "enter the course id that you want to insert: ";
            cin >> course_id;
            if(search_course(course_id)){
                cout << "The Course has been found in the list " << endl;
            }else{
                cout << "The Course has not been found in the list " << endl;
            }
        }
        if(select==3){
            print_course_list();
        }
        if(select==4){
            int course_id;
            cout << "enter the course id that you want to insert: ";
            cin >> course_id;
            delete_course(course_id);
        }
        if(select==5){
            delete_course_list();
        }
        if(select==6){
            int course_id;
            cout << "enter the course id that you want to insert: ";
            cin >> course_id;
            int student_id;
            cout << "enter the student id that you want to insert: ";
            cin >> student_id;
            insert_student(course_id,student_id);
        }
        if(select==7){
            int course_id;
            cout << "enter the course id in which you want to search: ";
            cin >> course_id;
            int student_id;
            cout << "enter the student id that you want to search: ";
            cin >> student_id;
            if(search_student(course_id , student_id)){
                cout << "The Student has been found in the list " << endl;
            }else{
                cout << "The Student has not been found in the list " << endl;
            }
        }
        if(select==8){
            int course_id;
            cout << "enter the course id in which you want to print the list of student: ";
            cin >> course_id;
            print_student_list_of_a_course(course_id);
        }
        if(select==9){
            int course_id;
            cout << "enter the course id from which you want to delete the student: ";
            cin >> course_id;
            int student_id;
            cout << "enter the student id that you want to delete: ";
            cin >> student_id;
            delete_student(course_id , student_id);
        }
        if(select==10){
            int student_id;
            cout << "enter the student id that you want to delete from all courses: ";
            cin >> student_id;
            delete_student_all_course(student_id);
        }
        cout << "enter your choice agian: ";
        cin >> select;
    }
    
   return 0;
}