#include <iostream>
#include <stdlib.h>
using namespace std;

struct Record{
  int value;
  Record *next;
};


void push(Record**top , int value){
  Record *ptr = (Record *)malloc(sizeof(Record));
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

string rev_Str(string str){
  string rev_Str;
  for (int i = 0; i < str.length(); i++){
    if(str[i]=='('){
      str = ')' + str;
    }
    else if (str[i]==')'){
      str='(' + str;
    }
    else{
      rev_Str = str[i] + rev_Str;
    }
  }
  return rev_Str;
}

int prefix_Expression(Record**top , string prefix){
  int result;
  string revPrefix = rev_Str(prefix);
  for (int i = 0; i < revPrefix.length(); i++){
    char ch = revPrefix[i];
    if (ch >= 'a' && ch <= 'z'){
      int value = (ch - '0');
      push(top,value);
    }
    else{
      int tmp;
      int lop = pop(top);
      int rop = pop(top);
      switch (ch)
      {
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
      push(top,tmp);
    }
  }
  result = pop(top);
  return result;
}

int main(){
  Record *top = NULL;
  string prefixEq2 = "&<+a*b-cdx|!cy<+xy5";
  // values a = 2, b= 1, c = 3, d = 1, x = 2, y = 4
  int result = prefix_Expression(&top , "&<+2*1-312|!34<+245");
  cout << "Result is " << result << endl;
}