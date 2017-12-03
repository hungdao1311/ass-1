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

bool getIDp(L1Item<NinjaInfo_t> *&pHead, char* id) {
    while(pHead){
        if(strcmp(id, pHead->data.id) == 0) return true;
        pHead = pHead->pNext;
    }
    return false;
}

double getDistance(L1Item<NinjaInfo_t> *pHead, L1Item<NinjaInfo_t> *pDes){
    return distanceEarth(pHead->data.latitude,pHead->data.longitude,pDes->data.latitude,pDes->data.longitude);
}

bool checkDistance(L1Item<NinjaInfo_t> *pHead, L1Item<NinjaInfo_t> *pDes){
    if (!pDes) return false;
    return (getDistance(pHead, pDes) > 0.005);

}

bool getNextMove(L1Item<NinjaInfo_t> *pHead, L1Item<NinjaInfo_t> *&pDes){
    pDes = pHead->pChild;
    if(checkDistance(pHead,pDes)) {
        pDes = pHead;
        return true;
    }
    while(pDes) {
        if (checkDistance(pHead, pDes)) return true;
        pDes = pDes->pChild;
    }
    return false;
}

bool getNextStop(L1Item<NinjaInfo_t> *pHead, L1Item<NinjaInfo_t> *&pDes) {
    pDes = pHead->pChild;
    while(pDes){
        if(checkDistance(pHead,pDes)){
            pHead = pDes;
            pDes = pDes->pChild;
        } else {
            pDes = pHead;
            return true;
        }
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

void process_2(L1List<NinjaInfo_t>& nList) {

    cout << "2: " << nList[nList.getSize()-1].id << endl;
}

void process_3(L1List<NinjaInfo_t>& nList) {
    cout << "3: " << nList.getSize() << endl;
}

void process_4(L1List<NinjaInfo_t>& nList) {
    L1Item<NinjaInfo_t>* node = nList.getHead();
    const char* temp = node->data.id;
    while(node){
        if(strcmp(temp, node->data.id) < 0){
            temp = node->data.id;
        }
        node = node->pNext;
    }
    cout << "4: " << temp << endl;
}

void process_5(L1List<NinjaInfo_t>& nList, char* id){
    L1Item<NinjaInfo_t>* temp5 = nList.getHead();
    L1Item<NinjaInfo_t>* des5 = new L1Item<NinjaInfo_t>();
    char ptime[19];
    cout << "5" << id << ": ";
    if(getIDp(temp5, id)&& getNextMove(temp5,des5)){
        strPrintTime(ptime, des5->data.timestamp);
        cout << ptime << endl;
    } else {
        cout << "-1" << endl;
    }
}

void process_6_7(L1List<NinjaInfo_t>& nList, int code, char* id){
    L1List<NinjaInfo_t> stopList;
    L1Item<NinjaInfo_t>* temp6 = nList.getHead();
    L1Item<NinjaInfo_t>* des6 = new L1Item<NinjaInfo_t>();
    char ptime[19];
    cout << code << id << ": ";
    if(getIDp(temp6, id)){
        if(!checkDistance(temp6, temp6->pChild)){
            stopList.push_back(temp6->data);
        }
        while(getNextMove(temp6,des6)) {
            if(getNextStop(des6, temp6)) {
                stopList.push_back(temp6->data);
            } else break;
        }
        strPrintTime(ptime, stopList.getTail()->data.timestamp);
        if(code == 6) cout << ptime << endl;
        if(code == 7) cout << stopList.getSize() << endl;
    }else {
        cout <<"-1" << endl;
    }
}


bool processEvent(ninjaEvent_t& event, L1List<NinjaInfo_t>& nList, void* pGData) {
    // TODO: Your code comes here
    int eCode;
    char str[2];
    char ninjaID[4];
    //Get event code and ID
    if(strlen(event.code) == 1 || strlen(event.code) == 2) {
        eCode = atoi(event.code);

    }
    else if(strlen(event.code) == 5){
        strncpy(str, event.code, 1);
        eCode = atoi(str);
        strncpy(ninjaID, event.code + 1,4);
    }
    else if(strlen(event.code) == 6){
        strncpy(str, event.code, 2);
        eCode = atoi(str);
        strncpy(ninjaID, event.code + 2, 4);
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
            process_2(nList);
            break;
        case 3:
            process_3(nList);
            break;
        case 4:
            process_4(nList);
            break;
        case 5:
            process_5(nList, ninjaID);
            break;
        case 6:
            process_6_7(nList, eCode, ninjaID);
            break;
        case 7:
            process_6_7(nList, eCode, ninjaID);
            break;
        default: return false;
    }
    /// NOTE: The output of the event will be printed on one line
    /// end by the endline character.
    return true;
}
