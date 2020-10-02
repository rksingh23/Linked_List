#ifndef TEMPLATE_SOLUTION_H
#define TEMPLATE_SOLUTION_H

#include <string>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) { }
    //Another way to write the above statement is by the statement below -->
    // Node(int data) 
    // { 
    //     this->data = data; 
    //     next = NULL; 
    // } 
};

class SinglyLinkedList {
public:
  // default constructor
  SinglyLinkedList();

  //constructor creates a cyclic or acyclic linked list based on the value of i
  SinglyLinkedList(vector<int> &input, int i);
  
  //destructor, cleans up
  ~SinglyLinkedList();

  bool empty();//checks if empty

  int size(); //returns size

  void push_back(int i);//inserts at the back

  void push_front(int i);//inserts at the front

  void insert_after(ListNode *p, int i);//inserts value i after p

  void erase(ListNode *p);//erases node p

  void pop_front();//remove the first item

  void pop_back();//remove the last item

  int back();//returns the value of last item

  int front();//returns the value of first item

  ListNode* GetBackPointer();//returns the pointer to the last item

  ListNode* GetIthPointer(int i);//returns pointer to ith element
  
  void reverse(); // reverse the linked list in-place
  
  void print();//prints the list: ex. Empty list: { }. List with Items: {1, 2, 3}

  ListNode *head_;//Pointer to the first element
  ListNode *tail_;//Pointer to the last element

};

#endif