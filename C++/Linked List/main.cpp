#include "./src/LinkedList.cpp"
#include <iostream>
using namespace std;

int main()
{
     Linkedlist LinkedList1;
     cout << endl;

     LinkedList1.add_First(5);
     LinkedList1.add_First(4);
     LinkedList1.add_First(3);
     LinkedList1.add_First(2);
     LinkedList1.add_First(1);

     LinkedList1.add_Last(6);
     LinkedList1.add_Last(7);
     LinkedList1.add_Last(8);
     LinkedList1.add_Last(9);
     LinkedList1.add_Last(10);

     // LinkedList1.delete_First();
     // LinkedList1.add_First(3);
     // LinkedList1.add_Last(11);
     // LinkedList1.delete_Last();
     // LinkedList1.delete_Last();
     // LinkedList1.add_First(2);
     // LinkedList1.add_Last(8);

     // cout << boolalpha << endl
     //      << LinkedList1.contains(4) << endl
     //      << LinkedList1.contains(40);

     // cout << endl
     //      << "Index of (4): " << LinkedList1.indexOf(4) << endl
     //      << "Index of (13): " << LinkedList1.indexOf(13);

     // LinkedList1.inverse();
     // LinkedList1.inverse();

     // cout << LinkedList1.KthNodeFromEnd(-1) << endl;
     // cout << LinkedList1.KthNodeFromEnd(90) << endl;
     // cout << LinkedList1.KthNodeFromEnd(1) << endl;
     // LinkedList1.inverse();
     // cout << LinkedList1.KthNodeFromEnd(1) << endl;
     // cout << LinkedList1.KthNodeFromEnd(3) << endl;
     // cout << LinkedList1.KthNodeFromEnd(7) << endl;
     // LinkedList1.inverse();
     // cout << LinkedList1.KthNodeFromEnd(3) << endl;
     // cout << LinkedList1.KthNodeFromEnd(7) << endl;
     // cout << LinkedList1.KthNodeFromEnd(10) << endl;

     // cout << LinkedList1.middleNode();

     if (LinkedList1.isHaveLoop())
          cout << endl
               << "It have loop..." << endl;
     else
          cout << endl
               << "Don't have any loop!" << endl;
     

     cout << endl
          << "Run Successfully...!" << endl;

     return 0;
}
