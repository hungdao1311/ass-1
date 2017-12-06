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
    while(getline(file,str,'\n')){
        istringstream ss(str);
        while(ss >> str1) {
            if(str1[str1.length()-1] == ';'){
                str1[str1.length()-1] = '\0';
            }
            ninjaEvent_t temp(str1);
            eList.push_back(temp);
        }
        ss.clear();
    }
    file.close();
}
