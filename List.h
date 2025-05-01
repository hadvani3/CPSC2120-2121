/*
 * Name: Hritik Advani
 * Date Submitted: 1/31/2025
 * Lab Section: 2 
 * Assignment Name: Lab 1 Linked List
 */

#pragma once

#include <iostream>
#include <string>
#include "Node.h"
using namespace std;

//This class represents a linked list of node objects
//Do not modify anything in the class interface
template <class T>
class List{

 private:
  Node<T> * start; //pointer to the first node in this list
  int mySize;  //size (or length) of this list

 public:
  List();
  ~List();
  int size();
  bool empty();
  void insertStart(T);
  void insertEnd(T);
  void insertAt(T, int);
  void removeStart();
  void removeEnd();
  void removeAt(int);
  T getFirst();
  T getLast();
  T getAt(int);
  int find(T);

  //Print the name and this list's size and values to stdout
  //This function is already implemented (no need to change it)
  void print(string name){
    cout << name << ": ";
    cout << "size = " << size();
    cout << ", values = ";
    Node<T> * iterator = start;
    while(iterator != nullptr){
      cout << iterator->value << ' ';
      iterator = iterator->next;
    }
    cout << endl;
  }

}; //end of class interface (you may modify the code below)

//Implement all of the functions below
//Construct an empty list by initializig this list's instance variables
template <class T>
List<T>::List(){
  start = nullptr;
  mySize = 0;
}

//Destroy all nodes in this list to prevent memory leaks
template <class T>
List<T>::~List(){
  Node<T> *temp = start;
  while(temp != nullptr) {
    Node<T> *remove = temp;
    temp = temp->next;
    delete remove;
  }
}

//Return the size of this list
template <class T>
int List<T>::size(){
  return mySize;
}

//Return true if this list is empty
//Otherwise, return false
template <class T>
bool List<T>::empty(){

  if (size() == 0) {
    return true;
  }
  else {
    return false;
  }


}

//Create a new node with value, and insert that new node
//into this list at start
template <class T>
void List<T>::insertStart(T value){
  Node<T> *addNode = new Node<T>(value);

  // if statement if list is empty
  if (start == nullptr) {
    start = addNode;
  }

  else {
    addNode->next = start;
    start = addNode;
  }
  mySize++;

}

//Create a new node with value, and insert that new node
//into this list at end
template <class T>
void List<T>::insertEnd(T value){

  // create node
  Node<T> *addNode = new Node<T>(value);

  // check if list is empty
  if (start == nullptr) {
    start = addNode;
  }

  else {
    Node<T> *temp = start;

  // traverse through list
  while(temp->next != nullptr) {
    temp = temp->next;
  }

  // advance pointer to the next node
  temp->next = addNode;

}

mySize++;
}

//Create a new node with value <value>, and insert that new node at position j
template <class T>
void List<T>::insertAt(T value, int j){
  Node<T> *iter = start;

  // check if first node in list
  if (j == 0) {
    insertStart(value);

  }

  // check if last node
  else if (j == mySize) {
    insertEnd(value);

  }

  // check for other positions
  else {
  for (int i = 0 ; i < j - 1; i++) {
    iter = iter->next;
  }
    Node<T> *temp = new Node<T>(value);
    temp->next = iter->next;
    iter->next = temp;
   
  }
  mySize++;
}

//Remove node at start
//Make no other changes to list
template <class T>
void List<T>::removeStart(){

  // change head pointer to the next node
  Node<T> *temp = start;
  start = start->next;
  delete temp;

  mySize--;
}

//Remove node at end
//Make no other changes to list
template <class T>
void List<T>::removeEnd(){

  // change head pointer to the previous 
  Node<T> *previous = start;

  while (previous->next->next != nullptr) {
    previous = previous->next;
  }

  // delete last node
  delete previous->next;

  // change the next pointer to null
  previous->next = nullptr;

  mySize--;

}

//Remove node at position j
//Make no other changes to list
template <class T>
void List<T>::removeAt(int j){
  Node<T> *current = start;

  // check if node is the first node in the list
  if (j == 0) {
    removeStart();
  }

  // check if the node is last in the list
  else if (j == size() - 1) {
    removeEnd();
  }

  else {
    for (int i = 0 ; i < j - 1; i++) {
      current = current->next;
    }
      Node<T> *temp = current->next;
      current->next = temp->next;
    
      // delete the node
      delete temp;
    
  }
    // decrement the size
    mySize--;

}

//Return the value of the first node in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getFirst(){

  // check if list is empty
  if (start == nullptr) {
    return T();
  }

  return start->value;
}

//Return the value of the last node in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getLast() {

  // check if list is empty
  if (start == nullptr) {
    return T();
  }
  Node<T> *current = start;

// check if next pointer equals null and traverse through
  while(current->next != nullptr) {
    current = current->next;
  }

  return current->value;

  
}

//Return the value of the node at position j in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getAt(int j){
  Node<T> *current = start;

  // check if list is empty
  if (start == nullptr) {
    return T();
  }

  // iterate thorugh each position in the list 
  for (int i = 0 ; i < j ; i++) {
    current = current->next;
  }

  return current->value;
}

//Return the position of the (first) node whose value is equal to the key
//Otherwise, return -1
template <class T>
int List<T>::find(T key){

  Node<T> *current = start;

  // iterate through the list
  for(int i = 0 ; i < size(); i++){
    
    if(current->value == key) {
      return i;
    }
      // advance pointer
      current = current->next;
    
  }
  return -1;
}
