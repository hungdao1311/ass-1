/*
 * =========================================================================================
 * Name        : processData.cpp
 * Description : student code for Assignment 1 - Data structures and Algorithms - Fall 2017
 * =========================================================================================
 */
#include <bits/unordered_set.h>
#include "eventLib.h"
#include "dbLib.h"

void printEvent(ninjaEvent_t &b){
    cout << b.code << " ";
}

bool checkExist(L1List<NinjaInfo_t> &list, char *id) {
    int k = 0;
    while (k < list.getSize()) {
        if (strcmp(list[k].id, id) == 0) return true;
        k++;
    }
    return false;
}

void process_0(void* pGData){
    L1List<ninjaEvent_t>* event;
    event = static_cast<L1List<ninjaEvent_t>*>(pGData);
    cout << "0: ";
    event->traverse(printEvent);
    cout << endl;
}







bool processEvent(ninjaEvent_t& event, L1List<NinjaInfo_t>& nList, void* pGData) {
    // TODO: Your code comes here
    int eCode;
    char str[2];
    //Get event code
    if(strlen(event.code) == 1 || strlen(event.code) == 2) {
        eCode = atoi(event.code);

    }
    else if(strlen(event.code) == 5){
        strncpy(str, event.code, 1);
        eCode = atoi(str);
    }
    else if(strlen(event.code) == 6){
        strncpy(str, event.code, 2);
        eCode = atoi(str);
    }
    else return false;

    //Process event
    switch(eCode){
        case 0:
            process_0(pGData);
            break;
        case 1:
            cout << "1: " << nList[0].id << endl;
            break;
        case 2:
            cout << "2: " << nList[nList.getSize() - 1].id << endl;
            break;
        case 3:

            break;
        default: return false;
    }
    /// NOTE: The output of the event will be printed on one line
    /// end by the endline character.
    return true;
}
