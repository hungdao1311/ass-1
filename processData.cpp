/*
 * =========================================================================================
 * Name        : processData.cpp
 * Description : student code for Assignment 1 - Data structures and Algorithms - Fall 2017
 * =========================================================================================
 */
#include "eventLib.h"
#include "dbLib.h"

void printEvent(ninjaEvent_t &b){
    cout << b.code << " ";
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

    if(strlen(event.code) == 1 || strlen(event.code) == 2) {
        eCode = atoi(event.code);

    }
    else if(strlen(event.code) == 5){
        strncpy(str, event.code, 1);
        eCode = atoi(str);
    }
    else if(strlen(event.code) == 6){
        strncpy(str, event.code, 1);
        eCode = atoi(str);
    }
    else return false;
    switch(eCode){
        case 0:
            process_0(pGData);
            break;
        default: return false;
    }
    /// NOTE: The output of the event will be printed on one line
    /// end by the endline character.
    return true;
}
