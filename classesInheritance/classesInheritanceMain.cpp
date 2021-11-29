/*
Author: Bryce Truong
Date Created: 11/5/21
Last Modified: 11/15/21
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
#include "videoGames.h"
#include "media.h"



using namespace std;


int main() {
  char input[20];
  bool stillRunning = true;
  
  media* mediaList[20];
  
  vector<media*> myVec;
  
  while (stillRunning == true) {
    cout << "Welcome to the menu. Please select one of the following:\nADD\tDELETE\tSEARCH\tQUIT" << endl;
    cin.getline(input, 20, '\n');
    if (strcmp(input, "ADD") == 0) {
      cout << "What kind of media would you like to add? \nVIDEOGAMES (VG)\tMUSIC (MS)\tMOVIES (MV)" << endl;
      cin.getline(input, 20, '\n');
      if (strcmp(input, "VIDEOGAMES") == 0 || strcmp(input, "VG") == 0) {
        cout << "VIDEOGAMES" << endl;
        double intuit = 0.0;
        cin >> intuit;
        cout << intuit << endl;
        cin.ignore(80,'\n');
      } else if (strcmp(input, "MUSIC") == 0 || strcmp(input, "MS") == 0) {
        cout << "MUSIC" << endl;
      } else if (strcmp(input, "MOVIES") == 0 || strcmp(input, "MV") == 0) {
        cout << "MOVIES" << endl;
      } else {
        cout << "Returning to menu..." << endl;
      }
    } else if (strcmp(input, "DELETE") == 0) {

    } else if (strcmp(input, "QUIT") == 0) {
      cout << "Exiting..." << endl;
      stillRunning = false;
    } else if (strcmp(input, "SEARCH") == 0) {
      cout << "What do you want to search by?\nTITLE\tYEAR" << endl;
      cin.getline(input, 20, '\n');
      
      if (strcmp(input, "TITLE") == 0){
        for (int i = 0; i < myVec.size(); i++) {
          
          cout << myVec.at(i) -> getTitle() << endl;
          
        }
      } else if (strcmp(input, "YEAR") == 0) {
        
      } else {
        cout << "Input not recognized..." << endl;
      }
      
      char* testTitle = new char[20];
      strcpy(testTitle, "myFirst");
      int newInt = 2021;
      mediaList[0] = new media(testTitle, newInt); //videogames or media
      myVec.push_back(mediaList[0]);
      strcpy(testTitle, "mySecond");
      newInt = 2022;
      mediaList[1] = new videoGames(testTitle, newInt, testTitle, 7.8);
      myVec.push_back(mediaList[1]);
      
      
      /*
      for (int i = 0; i < myVec.size(); i++) {
        cout << myVec.at(i) -> getTitle() << endl;
      }
      */
    } else {
      
      cout << myVec.at(0)->getTitle() << endl;
      cout << mediaList[0]->getYear() << endl;
      
      cout << myVec.at(1)->getYear() << endl; //also use virtual functions for when there are the same fctn (like getRate on both movies and VG)
      cout << ((videoGames*)myVec.at(1))->getRate() << endl; //I cast to a videogame ptr because it still thinks that it is a media ptr and tries to find get rate when there is no get rate
      
      cout << "Input not recognized..." << endl;
    }
  }

}
