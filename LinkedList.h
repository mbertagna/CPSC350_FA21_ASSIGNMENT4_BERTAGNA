// a. Michael Bertagna
// b. 2353491
// c. bertagna@chapman.edu
// d. CPSC 350-01
// e. Assignment 4

/* LinkedList.h is a template class which implements a Doubly Linked Linked consisting of List Nodes with data of arbitrary type. */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <exception>
using namespace std;

template <class T>
class ListNode{
  public:
    ListNode();
    ListNode(T d);
    ~ListNode();
    ListNode<T> *next;
    ListNode<T> *prev;
    T data;
};

// implementation
template <class T>
ListNode<T>::ListNode(){}

template <class T>
ListNode<T>::~ListNode(){
  // data = NULL;//FIXME DO I NEED THIS
  next = NULL;
  prev = NULL;
}

template <class T>
ListNode<T>::ListNode(T d){
  data = d;
  next = NULL; // 0 nullptr
  prev = NULL;
}

//doublylinkedlist class
template <class T>
class DoublyLinkedList{
  private:
    ListNode<T> *front;
    ListNode<T> *back;
    unsigned int size;

  public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void insertFront(T d);
    void insertBack(T d);
    T removeFront();
    T removeBack();
    T removeNode(T value);
    int findValue(T value);
    bool isEmpty();
    unsigned int getSize();
    void printList(bool isPrintLink);
    T getFrontValue();
};

template <class T>
void DoublyLinkedList<T>::printList(bool printLink)
{
    ListNode<T> *curr = front;
    while(curr != 0){
       if(curr == front){
         cout << "{FRONT}: ";
       }
       else if(curr == back){
         cout << "{REAR}: ";
       }
       if(printLink)
        cout << "[ PREV: "<< curr->prev << " || " << curr->data << " || NEXT: "<< curr->next << " ] ";
      else
        cout << "[ " << curr->data << " ] ";
       curr = curr->next;
       if(curr != 0){
         cout << " ==> ";
       }
    }
    cout << endl;
}

template <class T>
DoublyLinkedList<T>::DoublyLinkedList(){
  front = NULL;
  back = NULL;
  size = 0;
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList(){
  //build some character
  if(!(front == NULL)){
    ListNode<T> *curr = front;
    ListNode<T> *next = curr->next;
    while(next != NULL){ 
      delete curr;
      curr = next;
      next = curr->next;
    }
    delete curr;
  }
}

template <class T>
void DoublyLinkedList<T>::insertFront(T d){
  ListNode<T> *node = new ListNode<T>(d);

   if(isEmpty()){
     back = node;
   }
   else{
     //not an empty list
     node->next = front;
     front->prev = node;
   }
   front = node;
   ++size;
}

template <class T>
T DoublyLinkedList<T>::removeFront(){
  if(isEmpty()){
    throw runtime_error("Linked List is empty.");
  }

  ListNode<T> *temp = front;
  
  if(front->next == NULL){
    back = NULL;
  }
  else{
    //we have more than 1 ListNode, list size > 1
    front->next->prev = NULL;
  }
  front = front->next;
  T data = temp->data;
  temp->next = NULL;
  --size;
  delete temp;

  return data;
}

template <class T>
T DoublyLinkedList<T>::removeBack(){
  if(isEmpty()){
    throw runtime_error("Linked List is empty.");
  }

  ListNode<T> *temp = back;
  
  if(back->prev == NULL){
    front = NULL;
  }
  else{
    //we have more than 1 ListNode, list size > 1
    back->prev->next = NULL;
  }
  back = back->prev;
  T data = temp->data;
  temp->prev = NULL;
  --size;
  delete temp;

  return data;
}

template <class T>
T DoublyLinkedList<T>::removeNode(T value){
  if(isEmpty()){
    throw runtime_error("Linked List is empty.");
  }

  //we can leverage find method

  ListNode<T> *curr = front;

  while(curr->data != value){
    curr = curr -> next;

    if(curr == NULL)
      return -1;
  }

  //we found the node and current in the correct position
  if(curr != front && curr != back){
    //listnode is b/w front and back
    curr->next->prev = curr->prev;
    curr->prev->next = curr->next;
  }
  
  if(curr == front){
    front = curr->next;
    front->prev = NULL;
  }
  if(curr == back){
    back = curr->prev;
    back->next = NULL;
  }
  
  curr->next = NULL;
  curr->prev = NULL;

  T temp = curr->data;
  --size;
  delete curr;

  return temp;
}

template <class T>
unsigned int DoublyLinkedList<T>::getSize(){
  return size;
}

template <class T>
int DoublyLinkedList<T>::findValue(T value){
  int pos = -1;
  ListNode<T> *curr = front;

  while(curr != NULL){
    ++pos;
    if(curr->data == value){
      break;
    }
    curr = curr->next;
  }

  if(curr == NULL)
    pos = -1;

  return pos;
}

template <class T>
bool DoublyLinkedList<T>::isEmpty(){
  return (size == 0);
}

template <class T>
void DoublyLinkedList<T>::insertBack(T d){
  ListNode<T> *node = new ListNode<T>(d);

   if(isEmpty()){
     front = node;
   }
   else{
     //not an empty list
     node->prev = back;
     back->next = node;
   }
   back = node;
   ++size;
}

template <class T>
T DoublyLinkedList<T>::getFrontValue(){
  if(isEmpty()){
    throw runtime_error("Linked List is empty.");
  }
  return front->data;
}

#endif
