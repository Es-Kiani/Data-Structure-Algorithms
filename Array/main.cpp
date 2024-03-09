#include <iostream>
#include "Array.cpp"
using namespace std;

int main()
{
    // Array arr = new Array(4);
    Array arr1 = Array(4);

    arr1.insert(10);
    arr1.insert(20);
    arr1.insert(30);
    arr1.insert(40);
    arr1.insert(50);

    // arr.removeAt(1);
    // arr.removeAt(10);

    // cout << arr.indexOf(20)<<endl;
    // cout << arr.indexOf(50)<<endl;

    Array arr2(3);

    arr2.insert(10);
    arr2.insert(20);
    arr2.insert(30);
    arr2.insert(40);
    arr2.insert(50);
    arr2.insert(69);
    arr2.insert(85);

    // arr1.print();
    arr2.print();

    // cout << arr2.max()<<endl;

    Array intersectedArr = arr1.intersect(arr2);
    // intersectedArr.print();

    // arr1.reverse();

    arr2.insertAt(100, 7);
    arr2.print();

    return 0;
}