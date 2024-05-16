#include <iostream>
#include <iomanip>
// #include <vector>
using namespace std;

int Binary(int ary[], int target){

    int left = 0;
    int right = 9;

    while (left <= right)
    {
        int mid = left + (right-left) / 2;
        if (ary[mid] == target)
        {
            return mid;
        }
        else if (ary[mid] < target)
        {
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return -1;
}

int main()
{

    int ary[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int target = 70;

    int search = Binary( ary , target);

    if(search!=-1){
        cout << "found it at: " <<  search <<endl;
    }
    else{
        cout << " not found" << endl;
    }


    return 0;
}