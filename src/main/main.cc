#include "src/lib/solution.h"
#include <iostream>
#include<vector>

int main() 
{
   std::vector<int> vec={1,2,3,4,5};
   int n=10;

   SinglyLinkedList s(vec,n);

   std::cout<<"Is the list empty "<<((s.empty())?"true":"false")<<std::endl;
   std::cout<<"Size of list "<<s.size()<<std::endl;

   s.push_back(6);
   std::cout<<"List after pushing 6 into back :    ";
   s.print();
   std::cout<<std::endl;

   s.push_front(0);
   std::cout<<"List after pushing 0 into front : ";
   s.print();
   std::cout<<std::endl;

   s.pop_back();
   std::cout<<"List after pop from back :        ";
   s.print();
   std::cout<<std::endl;

   s.pop_front(); 
   std::cout<<"List after pop from front :         ";
   s.print();
   std::cout<<std::endl;

   s.erase(s.GetIthPointer(5));
   std::cout<<"Removed 5 by passing reference :    ";
   s.print();
   std::cout<<std::endl;

   s.insert_after(s.GetIthPointer(4),5);
   std::cout<<"Inserting 5 by passing reference :  ";
   s.print();
   std::cout<<std::endl;

   s.reverse();
   std::cout<<"Reversed List :                     ";
   s.print();
   std::cout<<std::endl;


   ListNode* a=s.GetBackPointer();
   ListNode* b=s.GetIthPointer(5);
   std::cout<<a->val<<" is the value, at the address using get back pointer "<<&a<<std::endl;
   std::cout<<b->val<<" is the value, at the address using get ith pointer  "<<&b<<std::endl;


  return 0;
}