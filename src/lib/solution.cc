#include "solution.h"
#include <iostream>
#include <bits/stdc++.h>

//Default Constructor
SinglyLinkedList::SinglyLinkedList() {                                                         // O(1)
    SinglyLinkedList::head_=nullptr;
    SinglyLinkedList::tail_=nullptr;
    std::cout<<head_<<' '<<tail_;
}



//Parameterized Constructor
SinglyLinkedList::SinglyLinkedList(vector<int> &input, int i)
{
   // ListNode *newnode;
    SinglyLinkedList::head_=nullptr;
    SinglyLinkedList::tail_=nullptr;
    for (auto it=input.begin();it!=input.end();it++)                                                   // O(n)
    {
        ListNode *newnode=new ListNode(*it);
        if(SinglyLinkedList::head_==nullptr)                                                           // O(1)
        {
            SinglyLinkedList::head_=newnode;
            SinglyLinkedList::tail_=newnode;

        }
        else
        {
            SinglyLinkedList::tail_->next=newnode;
            SinglyLinkedList::tail_=SinglyLinkedList::tail_->next;
        }
    }
    // std::cout<<std::endl;
    // std::cout<<"List before linking last to i"<<std::endl;
    // SinglyLinkedList::print();                                           
    // std::cout<<std::endl;                       

    if ((i>=0) && (i<input.size()))                                                      //O(1)
    {
        ListNode *list_traverse= head_;
        while(list_traverse->val!=i)                                                      //O(n)
            list_traverse= list_traverse->next;                                           //O(1)
        SinglyLinkedList::tail_->next= list_traverse;
    }
    //std::cout<<std::endl;
    // std::cout<<"List after linking last to i"<<std::endl;
    // SinglyLinkedList::print();
    // std::cout<<std::endl;
}

//Destructor --> Delete all Nodes of Linklist
SinglyLinkedList::~SinglyLinkedList() {
    ListNode *list_traverse;
    while (head_!=nullptr) //Deletes all the nodes --> until head pointer points to null      O(n)
    {
        list_traverse = head_->next;
        delete head_;                                                                        // O(1)
        head_=list_traverse;
    }
    std::cout<<"Destructor activated"<<std::endl; 
}

//Check if the list is empty or not
bool SinglyLinkedList::empty() {
    if ((head_ ==nullptr)&&(tail_==nullptr))                                                  // O(1)
        return true;
    else 
        return false;
    
} 

//Return the size of the list
int SinglyLinkedList::size() {
    int size=0;
    ListNode *list_traverse= head_;
    while(list_traverse!=nullptr)                                                               //O(n)
    {
        list_traverse= list_traverse->next;                                                     //O(1)
        size++;
    }
    return size;
} 

void SinglyLinkedList::push_back(int i) {
    ListNode *newnode= new ListNode(i);
    //newnode->next=tail_->next;
    tail_->next=newnode;                                                                         //O(1)  as we have saved the tail pointer, Worst case O(n) if tail pointer is not maintained and we have to traverse everytime
    tail_=tail_->next;
} 

void SinglyLinkedList::push_front(int i) {
    ListNode *newnode= new ListNode(i);
    newnode->next=head_;                                                                         //O(1)
    head_=newnode;
} 

void SinglyLinkedList::insert_after(ListNode* p, int i) {
    ListNode *newnode= new ListNode(i);                                                      
    newnode->next=p->next;                                                                        //O(1) as we have the node details, if we were only given the data in place of the node object, then it would have the complexity same as that of GetIthPointer, having Worst case :O(n)
    p->next=newnode;
} 

void SinglyLinkedList::erase(ListNode* p) {

    ListNode *p_prev=head_;
     while ((p_prev->next !=nullptr)&&((p_prev->next)!=p))                                          // Depends on the items traveres, Worst case scenario: O(n)
        p_prev=p_prev->next;
    
    //Now we have p and p_prev
    p_prev->next=p->next;
    delete p;
} 

void SinglyLinkedList::pop_front() {
    ListNode *old_head=head_;
    head_=head_->next;                                                                                // O(1)
    delete old_head;
} 

void SinglyLinkedList::pop_back() {

    ListNode *tail_prev=head_;
     while ((tail_prev->next !=nullptr)&&((tail_prev->next)!=tail_))                                   // O(n)
        tail_prev=tail_prev->next;
    
    //Now we have p and p_prev
    tail_prev->next=tail_->next;
    delete tail_;
    tail_=tail_prev;
} 

ListNode* SinglyLinkedList::GetBackPointer() {
    return tail_;                                                                                       //O(1) as we have saved the tail pointer, Worst case O(n) if tail pointer is not maintained and we have to traverse everytime 
} 

ListNode* SinglyLinkedList::GetIthPointer(int i) {
    ListNode *list_traverse= head_;
    while(list_traverse->val!=i)                                                                         // Depends on the elements traveresed. Worst Case Senario : O(n)
        list_traverse= list_traverse->next;

    return list_traverse;
} 

void SinglyLinkedList::reverse() {
    ListNode *prev=nullptr;
    ListNode *next=nullptr;
    ListNode *curr=SinglyLinkedList::head_;

    tail_=curr;
    while (curr!=nullptr)                                                                                  // O(n)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    SinglyLinkedList::head_=prev;
} 

void SinglyLinkedList::print() {
    ListNode *list_traverse=SinglyLinkedList::head_;
    

    while (list_traverse!=nullptr)                                                                          // O(n)
    {
        std::cout<<list_traverse->val<<" ";
        list_traverse=list_traverse->next;
    }
} 
