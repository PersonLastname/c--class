/*
Author: Bryce Truong
Date Created: 12/13/21
Last Modified: 12/13/21

*/
#include <iostream>
#include <cstring>
#include <stdio.h>
#include "item.h"

using namespace std;

item::item(){
  
  name = new char[20];

}
item::~item(){
  delete[] name;
}

item::item(char* newName){
  name = new char[80];
  strcpy(name, newName);
}

char* item::getName(){
  return name;
}
