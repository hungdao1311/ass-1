/*
 * =========================================================================================
 * Name        : eventLib.cpp
 * Author      : Duc Dung Nguyen, Nguyen Hoang Minh
 * Email       : nddung@hcmut.edu.vn
 * Copyright   : Faculty of Computer Science and Engineering - Bach Khoa University
 * Description : library for Assignment 1 - Data structures and Algorithms - Fall 2017
 *               This library contains functions used for event management
 * =========================================================================================
 */

#include "eventLib.h"


/// NOTE: each event will be separated by spaces, or endline character
void loadEvents(char* fName, L1List<ninjaEvent_t> &eList) {
	ifstream file;
    file.open(fName);
    string str, str1;
    L1Item<ninjaEvent_t> *tail = new L1Item<ninjaEvent_t>();
    while(getline(file,str)){
        istringstream ss(str);
        while(ss >> str1) {
            ninjaEvent_t temp(str1);
            tail=eList.push_back(temp,tail);
        }
    }
    file.close();
}
