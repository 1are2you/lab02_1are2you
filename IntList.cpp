// intlist.cpp
// Implements class IntList
// Xiaotian Yang, April, 10th, 2019

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
  Node *n = source.first;
  while (n){
    this->append(n->info);
    n = n -> next;
  }
    
}

// destructor deletes all nodes
IntList::~IntList() {
  Node *n = first;
  while (n){
    Node *move = n;
    n = n -> next;
    delete move;
  }
}


// return sum of values in list
int IntList::sum() const {
  int sum = 0;
  Node *n = first;
  while (n){
    sum += n->info;
    n = n->next;
  }
  return sum;
    
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
  Node *n = first;
  while (n){
    if (n->info == value)
      return true;
    else {
      n = n->next;
    }
  }
  return false;

} 

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
  Node *n = first;
  int max = 0;
  while (n){
    if (n -> info > max)
      max = n -> info;
    n = n -> next;
  }
  return max;
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
  Node *n = first;
  int x=0, y=0;
  x = IntList::count();
  y = IntList::sum();
  if (n == 0 )
    return 0;
  else
    return y/x;
}

// inserts value as new node at beginning of list
void IntList::insertFirst(int value) {
  Node *n = new Node();
  n -> info = value;
  if (first == 0)
    first = n;
  else{
    
    n -> next = first;
    first = n;
  }
 
}

//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
  Node *n = source.first;
  Node *m = IntList().first;
  if(this == &source){
    return(*this);
  };
  if (this != &source){
    while (n){
      m -> info = n -> info;
      n = n -> next;
      m = m -> next;
    };
  };
  return (*this);
}

    


// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// constructor sets up empty list
IntList::IntList() : first(0) {}


// append value at end of list
void IntList::append(int value) {
    if (first == 0) { // empty list
        first = new Node;
        first->info = value;
        first->next = 0;
    }
    else {
        Node *n = first;
        while (n->next) // not last node yet
            n = n->next;
        n->next = new Node;
        n->next->info = value;
        n->next->next = 0;
    }
}

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = first;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

// return count of values
int IntList::count() const {
    int result = 0;
    Node *n = first;
    while (n) {
        ++result;
        n = n->next;
    }
    return result;
}
