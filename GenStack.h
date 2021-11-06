// a. Michael Bertagna
// b. 2353491
// c. bertagna@chapman.edu
// d. CPSC 350-01
// e. Assignment 4

/* GenStack.h is a template class which implements a Linked List based Stack with data type left arbitrary. */

#ifndef GENSTACK_H
#define GENSTACK_H

#include <iostream>
#include <exception>
#include "LinkedList.h"

using namespace std;

template <class T>
class GenStack{
    public:
        GenStack();//default constructor
        ~GenStack();//destructor

        //core functions
        void push(T data);
        T pop();

        //aux/helper functions
        T peek();//aka top()
        bool isEmpty();
        int getSize();
        void printStack();

    private:  
        DoublyLinkedList<T> *m_dll;
};

template <class T>
GenStack<T>::GenStack(){
    m_dll = new DoublyLinkedList<T>();
}

template <class T>
GenStack<T>::~GenStack(){
    delete m_dll;
}

template <class T>
void GenStack<T>::push(T data){
    m_dll->insertFront(data);
}

template <class T>
T GenStack<T>::pop(){
    //check if empty
    if(isEmpty()){
        throw runtime_error("Stack empty: cannot pop!");
    }

    return m_dll->removeFront();
}

template <class T>
T GenStack<T>::peek(){
    //check if empty
    if(isEmpty()){
        throw runtime_error("Stack empty: cannot peek!");
    }

    return m_dll->getFrontValue();
}

template <class T>
bool GenStack<T>::isEmpty(){
    return (m_dll->getSize() == 0);
}

template <class T>
int GenStack<T>::getSize(){
    return (m_dll->getSize());
}

template <class T>
void GenStack<T>::printStack(){
    m_dll->printList(1);
}

#endif