/*
Author: Bryce Truong
Date Created: 11/5/21
Last Modified: 11/5/21



*/
#include <iostream>
#include <cstring>
#include <stdio.h>
#include "media.h"

const int MEDIA = 0;
const int VG = 1; //videogame
const int MS = 2; //music
const int MV = 3; //movie

using namespace std;

media::media(){
  //strcpy(title, newTitle);
  title = new char[20];
  year = 2000;
  type = MEDIA;
}

media::~media(){
  delete[] title;
}

media::media(char* newTitle, int newYear){
  title = new char[20];
  strcpy(title, newTitle);
  year = newYear;
  type = MEDIA;
}

char* media::getTitle(){
  return title;
}

int media::getYear(){
  return year;
}

int media::getType(){
 return type; 
}
