#include <iostream>
#include <stdlib.h>
using namespace std;

struct Record{
  int value;
  Record *next;
};

void push(Record**top , int value){
  Record *ptr = (Record*)malloc(sizeof(Record));
  ptr->value = value;
  ptr->next = *top;
  *top = ptr;
}

int pop(Record**top){
  if (*top == NULL){
    return -1;
  }
  int value = (*top)->value;
  Record *temp = *top;
  *top = temp->next;
  free(temp);
  return value;
}

int postfix_evaluate(Record**top , string postfixEq){
  int result;
  for (int i = 0; i < postfixEq.length(); i++){
    char ch = postfixEq[i];
    if (ch >= 'a' && ch <='z')
      push(top , ch - '0');   // string to integral ( also write (- 48)
      )
    else{
      int tmp;
      int rop = pop(top);
      int lop = pop(top);
      
      switch (ch){
      case '*':
        tmp = lop * rop;
        break;
      case '/':
        tmp = lop / rop;
        break;
      case '%':
        tmp = lop % rop;
        break;
      case '+':
        tmp = lop + rop;
        break;
      case '-':
        tmp = lop - rop;
        break;
      case '<':
        tmp = lop < rop;
        break;
      case '>':
        tmp = lop > rop;
        break;
      case '=':
        tmp = lop == rop;
        break;
      case '!':
        tmp = lop != rop;
        break;
      case '&':
        tmp = lop && rop;
        break;
      case '|':
        tmp = lop || rop;
        break;
      default:
        break;
      }
      push(top , tmp);
    }
  }
  result = pop(top);
  return result;
}
int main(){
  Record *top = NULL;
  string infix = "a+b*c/d*x-f*d";
  string postfix = "abc*d/x*+fd*-";
//let values a = 3, b = 2, c = 4, d =2, f = 3, x = 3
   int result = postfix_evaluate(&top , "324*2/3*+33*-");
  cout << "Answer is " << result << endl;
}