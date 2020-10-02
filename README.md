# Linked_List

> Implement the following class for a Linked List of integer values

```c++
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) { }
};

class SinglyLinkedList {
public:
  // default constructor
  SinglyLinkedList();

  //constructor creates a cyclic or acyclic linked list based on the value of i
  //if i is negative or greater than input size, the last item's next is nullptr
  //else creates a linked list out of vector "input" and connects the last item's next to i(th) item in the list
  SinglyLinkedList(vector<int> &input, int i);
  
  ~SinglyLinkedList(); //destructor, cleans up

  bool empty();//checks if empty

  int size(); //returns size

           OPTIONAL --> void push_back(int i);//inserts at the back

           OPTIONAL --> void push_front(int i);//inserts at the front

  void insert_after(ListNode* p, int i);//inserts value i after p

  void erase(ListNode* p);//erases node p

  void pop_front();//remove the first item

  void pop_back();//remove the last item

  ListNode* GetBackPointer();//returns the pointer to the last item

  ListNode* GetIthPointer(int i);//returns pointer to ith element

  void reverse(); // reverse the linked list in-place

  void print();//prints the list: ex. Empty list: { }. List with Items: {1, 2, 3}

  ListNode *head_;//Pointer to the first element

};
```

You can assume that the Linked List is **acyclic** except for the constructor ```SinglyLinkedList(vector<int> &input, int i);```.


## Installation

You can copy this using this command:

```bash
git clone https://github.com/rksingh23/Linked_List.git
```

### Run main:

You can run this using `blaze`:

```bash
bazel run src/main:main
```

### Run Tests:
You can run unit tests using [`blaze`](#installing-bazel):

```bash
bazel test tests:tests
```

## Installing Bazel
This repo uses `Bazel` for building C++ files.
You can install Bazel using this [link](https://docs.bazel.build/versions/master/install.html).
