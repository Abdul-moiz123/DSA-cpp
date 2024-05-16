#include <iostream>
#include <iomanip>
using namespace std;

int main(){

    // LEANER SERACHING IN C++

    int ary[] = {44,11,55,2,999,10};
    int i = 0;
    for (; i < 6 ; i++){
        if(ary[i]==2){
            cout << "the number is found at position: " << setw(5) << i << endl;
            break;
        }
    }
    if(ary[i]!=2){
        cout << "not found! " << endl;
    }
   return 0;
}