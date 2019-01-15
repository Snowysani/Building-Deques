#ifndef DEQUE_H
#define DEQUE_H

#include <exception>
#include "node.h"

class EmptyStackException: public std::runtime_error{
    // Create a class for empty stack exception for later
public:
    EmptyStackException() : runtime_error("Empty Stack Exception"){}
};

template <class Type> // Make the Deque class
class Deque
{
private:
    node<Type>* head; // Head, tail, and a count for the size
    node<Type>* tail;
    int sizeCount;
    
public:
    Deque(void);
    
    ~Deque(void);
    
    bool isEmpty(void);
    
    int size(void);
    
    Type first(void);
    
    Type last(void);
    
    void insertFirst(Type o);
    
    void insertLast(Type o);
    
    Type removeFirst(void);
    
    Type removeLast(void);
};
template<class Type>
Deque<Type>::Deque(){ // constructor
    head = nullptr;
    tail = nullptr;
    sizeCount = 0; // Set the size count equal to 0 to start
}

template<class Type>
Deque<Type>::~Deque(){ // destructor
    cout << "Destructor for deque called" << endl;;
}

template <class Type>
bool Deque<Type>::isEmpty(){ // check if it's empty
    if (head == nullptr && tail == nullptr)
        return 1; // Return "Yeah, it's empty."
    else
        return 0; // Not empty
}
template <class Type>
int Deque<Type>::size(){
        return sizeCount; // Return the size, how many elements
}
template <class Type>
Type Deque<Type>::first(){ // Get the first element
//    try {
//        if (isEmpty()){
//            throw EmptyStackException();
//        }
//    }
//    catch (EmptyStackException e) {
//        cout << "Empty Deque, cannot first.";
//        return Type();
//    }
    // Throw/catch is not needed, just spit out the error
    if (isEmpty()){
        throw EmptyStackException();
    }
    return head->data;
}

template <class Type>
Type Deque<Type>::last(){ // Get the last element
    if (isEmpty()){
        throw EmptyStackException();
    }
    return tail->data; // Return what's at the end of the deque
}
template <class Type>
void Deque<Type>::insertFirst(Type o){ // Insert an element at the front
    node<Type> *temp = new node<Type>();
    temp-> data = o; // Temp's data is the input
    temp-> next = head; // Temp's next is set to the head
    if (head != NULL)
        head-> previous = temp; // Head's previous is set to the temp
    head = temp;
    if(tail == NULL){
        tail = temp;
    }// The head of the deque is what's inputted
    ++sizeCount; // Add one to the overall size
}

template <class Type>
void Deque<Type>::insertLast(Type o){
    node<Type> *temp = new node<Type>();
    temp->data = o;
    temp->previous = tail;
    if (tail != NULL)
        tail->next = temp;
    tail = temp;
    if(head == NULL){
        head = temp;
    }// The tail is what's inserted at the end
    ++sizeCount; // Add one to overall size
}

template <class Type>
Type Deque<Type>::removeFirst(){
    node<Type> *temp; // setup the temp
    if (isEmpty()){   // throw out an exception if it's empty, check if empty
        throw EmptyStackException();
    }
    Type out = head->data; // make a nice temp to have something to return so the compiler doesn't yell at me
    if (size() == 1){ // if there's only one element, special case
        temp = head;
        head = NULL;
        tail = NULL;
    }
    else{
        // Now you want to get rid of the first overall element
        struct node<Type> *temp;
        temp=head;
        head = head->next;
        // set the head equal to what's next
        delete temp; // get rid of it
    }
    --sizeCount; // Since it's removing an element, subtract one from the size count
    return out;
}

template <class Type>
Type Deque<Type>::removeLast(){
    node<Type> *temp;
    if (isEmpty()){
        throw EmptyStackException();
    }
    Type out = tail->data; // have something to return
    if (size() == 1){ // special case, check if there's only one single element
        temp = tail;
        head = NULL;
        tail = NULL;
    }
    else{
        // Now you want to get rid of the LAST overall element
        struct node<Type> *temp;
        temp=tail; // set the temp equal to what the tail is at
        tail = tail->previous; // the new tail is what the old tail was previous pointing to
        delete temp; // delete the temp
    }
    --sizeCount; // throw one out of the size
    return out; // return something for the compiler 
}

#endif
