#ifndef ROOM_H
#define ROOM_H

/*
Author: Bryce Truong
Date Created: 12/9/21
Last Modified: 12/15/21


*/
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <vector>
#include <iterator>
#include <map>
#include "item.h"

using namespace std;

const int NORTH = 0;
const int EAST = 1;
const int SOUTH = 2;
const int WEST = 3;

class room {
	public:
	room();
	~room();
	room(char*, char*);
	char* getDesc();
	char* getName();
	void printInfo();
	void setExit(int, room*);
	room* getExit(int);
	void addItem(item*);
	item* remItem(char*, bool);
	void printItems();
	
	char* desc;
	char* roomname;
	vector<item*> roomInv;
	
	map<int, room*> exits; //direction
	map<int, room*>::iterator itr;

};

#endif
