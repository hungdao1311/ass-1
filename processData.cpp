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

void process_2(void* pGData) {
    L1List<NinjaInfo_t>* tail;
    tail = static_cast<L1List<NinjaInfo_t>*>(pGData);
    L1Item<NinjaInfo_t>* temp = tail->getHead();
    while(temp->pNext){
        temp = temp ->pNext;
    }
    cout << "2: " << temp->data.id << endl;
}

void process_3(void* pGData) {
    L1List<NinjaInfo_t> *list;
    list = static_cast<L1List<NinjaInfo_t> *>(pGData);
    cout << "3: " << list->getSize() << endl;
}

void process_4(void* pGData) {
    L1List<NinjaInfo_t>* list;
    list = static_cast<L1List<NinjaInfo_t>*>(pGData);
    L1Item<NinjaInfo_t>* node = list->getHead();
    const char* temp = node->data.id;
    while(node){
        if(strcmp(temp, node->data.id) < 0){
            temp = node->data.id;
        }
        node = node->pNext;
    }
    cout << "3: " << temp << endl;
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
            process_2(pGData);
            break;
        case 3:
            process_3(pGData);
            break;
        case 4:
            process_4(pGData);
            break;
        default: return false;
    }
    /// NOTE: The output of the event will be printed on one line
    /// end by the endline character.
    return true;
}
