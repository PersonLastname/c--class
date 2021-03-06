#include "Node.h"
#include <cstring>
Node::Node(){
  fname = new char[50];
  lname = new char[50];
  next = NULL;
}
Node::Node(char * newfname, char * newlname){
  fname = newfname;
  lname = newlname;
  next = NULL;
}
Node::~Node(){
  delete fname;
  delete lname;
  next = NULL;
}

void Node::setNext(Node* newNext){
  next = newNext;
}
Node * Node::getNext(){
  return next;
}

void Node::setfname(char * newfname){
  strcpy(fname, newfname);
}
void Node::setlname(char * newlname){
  strcpy(lname, newlname);
}
char * Node::getfname(){
  return fname;
}
char * Node::getlname(){
  return lname;
}

void Node::setID(int newID){
  ID = newID;
}
int Node::getID(){
  return ID;
}
void Node::setGPA(float newGPA){
  GPA = newGPA;
}
float Node::getGPA() {
  return GPA;
}
