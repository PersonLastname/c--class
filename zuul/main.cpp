/*
Author: Bryce Truong
Date Created: 12/9/21
Last Modified: 1/5/22

Sources:
https://www.quantstart.com/articles/C-Virtual-Destructors-How-to-Avoid-Memory-Leaks/
https://www.geeksforgeeks.org/destructors-c/
https://www.learncpp.com/cpp-tutorial/header-guards/
https://www.geeksforgeeks.org/stack-vs-heap-memory-allocation/
https://www.cplusplus.com/reference/vector/vector/erase/
https://www.tutorialspoint.com/how-do-i-find-the-length-of-an-array-in-c-cplusplus
https://www.cplusplus.com/reference/vector/vector/crbegin/
https://www.udacity.com/blog/2020/03/c-maps-explained.html
*/

#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <array>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iterator>
#include <map>
#include "room.h"
#include "item.h"

using namespace std;

int main() {
  char input[20];
  bool running = true;
  room* roomList[20];
  vector<item*> inventory;
  room* currentRoom;
  
  char* roomDesc = new char[80];
  char* roomName = new char[80];
  char* itemName = new char[80];

  
  /* CREATE ROOMS */
  
  char* TR1Desc = new char[80];
  strcpy(TR1Desc, "testRoom1 desc?");
  char* TR1Name = new char[80];
  strcpy(TR1Name, "testRoom1");
  room* testRoom1 = new room(TR1Desc, TR1Name);
  room* testRoom2 = new room(TR1Desc, TR1Name);
  
  testRoom1->setExit(NORTH, testRoom2);
    
  currentRoom = testRoom1;
  
  /* ADD ITEMS TO ROOMS */
  
  char* testingRoomItem = new char[20];
  strcpy(testingRoomItem, "test_room_item");
  testRoom1->addItem(new item(testingRoomItem));
  
  /* ADD ITEMS TO INV*/
  
  char* item1 = new char[20];
  strcpy(item1, "Flashlight");
  inventory.push_back(new item(item1));
  
  while (running) {
    
    currentRoom->printInfo();
    
    /* COMMAND PARSER */
    /* Availible commands:
       north/east/south/waffles
       get
          "item_name"
       drop
          "item_name"
       w,a,s,d (same as go)
       inv
       quit
    */
    cin.getline(input, 20, '\n');
    if (strcmp(input, "w") == 0 || strcmp(input, "north") == 0) {
      if (currentRoom->getExit(NORTH) != NULL) {
        currentRoom = currentRoom->getExit(NORTH);
      } else {
       cout << "Sorry, there isn't an exit in that direction" << endl; 
      }
    } else if (strcmp(input, "a") == 0 || strcmp(input, "east") == 0) {
      if (currentRoom->getExit(EAST) != NULL) {
        currentRoom = currentRoom->getExit(EAST);
      } else {
       cout << "Sorry, there isn't an exit in that direction" << endl; 
      }
    } else if (strcmp(input, "s") == 0 || strcmp(input, "south") == 0) {
      if (currentRoom->getExit(SOUTH) != NULL) {
        currentRoom = currentRoom->getExit(SOUTH);
      } else {
       cout << "Sorry, there isn't an exit in that direction" << endl; 
      }
    } else if (strcmp(input, "d") == 0 || strcmp(input, "west") == 0) {
      if (currentRoom->getExit(WEST) != NULL) {
        currentRoom = currentRoom->getExit(WEST);
      } else {
       cout << "Sorry, there isn't an exit in that direction" << endl; 
      }
    } else if (strcmp(input, "quit") == 0) {
      cout << "Byee!" << endl;
      running = false;
    } else if (strcmp(input, "drop") == 0) {
      
      cout << "Enter Item Name: " << endl;
      cin.getline(input, 20, '\n');
      
      for (int i = 0; i < inventory.size(); i++) {
        if (strcmp(input, inventory.at(i)->getName()) == 0) {
          currentRoom->addItem(inventory.at(i));
          inventory.erase(inventory.begin() + i);
          break;
        }
      }
      
      currentRoom->printItems();
      cout << "Items in Inventory:" << endl;
      for (int i = 0; i < inventory.size(); i++) {
        cout << inventory.at(i)->getName() << endl;
      }
      
    } else if (strcmp(input, "get") == 0) {
      
      cout << "Enter Item Name: " << endl;
      cin.getline(input, 20, '\n');
      if (currentRoom->remItem(input, false) != NULL) {
        inventory.push_back(currentRoom->remItem(input));
        currentRoom->printItems();
        cout << "Items in Inventory:" << endl;
        for (int i = 0; i < inventory.size(); i++) {
          cout << inventory.at(i)->getName() << endl;
        }
      } else {
       cout << "No item found!" << endl;
      }
      
    } else if (strcmp(input, "inv") == 0 || strcmp(input, "inventory") == 0) {
      
      cout << "Items in Inventory:" << endl;
      for (int i = 0; i < inventory.size(); i++) {
        cout << inventory.at(i)->getName() << endl;
      }
      
    } else {
     cout << "command not recognized..." << endl;
    }
    
  }
  
  cout << "Thanks for playing, have a nice day!" << endl; 
  
  
}
