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

bool getIDp(L1Item<NinjaInfo_t> *&pHead, char* id, int& pos) {
    pos = 0;
    while(pHead){
        if(strcmp(id, pHead->data.id) == 0) return true;
        pHead = pHead->pNext;
        pos++;
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
    int trash;
    cout << "5" << id << ": ";
    if(getIDp(temp5, id, trash)&& getNextMove(temp5,des5)){
        strPrintTime(ptime, des5->data.timestamp);
        cout << ptime << endl;
    } else {
        cout << "-1" << endl;
    }
}

void process_6_7(L1List<NinjaInfo_t>& nList, char code, char* id){
    L1List<NinjaInfo_t> stopList;
    L1Item<NinjaInfo_t>* temp6 = nList.getHead();
    L1Item<NinjaInfo_t>* des6 = new L1Item<NinjaInfo_t>();
    char ptime[19];
    int trash;
    cout << code << id << ": ";
    if(getIDp(temp6, id, trash)){
        if(!checkDistance(temp6, temp6->pChild)){
            stopList.push_back(temp6->data);
        }
        while(getNextMove(temp6,des6)) {
            if(getNextStop(des6, temp6)) {
                stopList.push_back(temp6->data);
            } else break;
        }
        strPrintTime(ptime, stopList.getTail()->data.timestamp);
        if(code == '6') cout << ptime << endl;
        if(code == '7') cout << stopList.getSize() << endl;
    }else {
        cout <<"-1" << endl;
    }
}
void process_89(L1List<NinjaInfo_t>& bList, char code, void*& pGData) {
    double *dArray = new double[bList.getSize()];
    int arrCount = 0;
    char* maxDistID;
    double tempMax = 0;
    L1Item<NinjaInfo_t>* tempDist = bList.getHead();
    while(tempDist){
        L1Item<NinjaInfo_t>* tempHead = tempDist;
        L1Item<NinjaInfo_t>* tempChild = tempDist->pChild;
        while(tempChild){
            dArray[arrCount] += distanceEarth(tempHead->data.latitude,tempHead->data.longitude, tempChild->data.latitude,tempChild->data.longitude);
            tempHead = tempChild;
            tempChild = tempChild->pChild;
        }
        if(dArray[arrCount] > tempMax){
            tempMax = dArray[arrCount];
            maxDistID = tempDist->data.id;
        }
        arrCount++;
        tempDist = tempDist->pNext;
    }
    if(code == '8') pGData = dArray;
    if(code == '9') pGData = maxDistID;
};
void process_8(L1List<NinjaInfo_t>& nList, char* id, void* pGData) {
    L1Item<NinjaInfo_t>* temp8 = nList.getHead();
    double* arr;
    arr = static_cast<double*>(pGData);
    int count;
    cout << "8" << id << ": " ;
    if(getIDp(temp8, id, count)){
        cout << arr[count] << endl;
    } else{
        cout << "-1" << endl;
    }
}

void process_9(void* pGData) {
    char* id;
    id = static_cast<char*>(pGData);
    cout << "9: " << id << endl;
}

void process_11(L1List<NinjaInfo_t>& nList, char* id){
    L1Item<NinjaInfo_t>* temp = nList.getHead();
    char* delID = "0000";
    int pos= 0, count = 0;
    while(temp){
        if(strcmp(delID, temp->data.id) < 0 && strcmp(id, temp->data.id) > 0){
            delID = temp->data.id;
            count = pos;
        }
        temp = temp->pNext;
        pos++;
    }
    if(delID == "0000"){
        cout << "11" << id << ": -1" << endl;
    } else{
        cout << "11" << id << ": " << delID << endl;
        nList.remove(count);
    }
}



bool processEvent(ninjaEvent_t& event, L1List<NinjaInfo_t>& nList, void* pGData) {
    // TODO: Your code comes here

    char ninjaID[4];

    //Get event code and ID
    if(strlen(event.code) == 1 || strlen(event.code) == 2) {

    }
    else if(strlen(event.code) == 5){
        strncpy(ninjaID, event.code + 1,4);

    }
    else if(strlen(event.code) == 6){
        strncpy(ninjaID, event.code + 2, 4);

    }
    else return false;

    //Process event
    switch(event.code[0]){
        case '0':
            process_0(pGData);
            break;
        case '1': {
            switch (event.code[1]) {
                case '\0':
                    cout << "1: " << nList[0].id << endl;
                    break;
                case '1':
                    process_11(nList, ninjaID);
                    break;
                default: return false;
            }
            break;
        }
        case '2':
            process_2(nList);
            break;
        case '3':
            process_3(nList);
            break;
        case '4':
            process_4(nList);
            break;
        case '5':
            process_5(nList, ninjaID);
            break;
        case '6':
            process_6_7(nList, '6', ninjaID);
            break;
        case '7':
            process_6_7(nList, '7', ninjaID);
            break;
        case '8':
            process_89(nList, '8', pGData);
            process_8(nList, ninjaID, pGData);
            break;
        case '9':
            process_89(nList, '9', pGData);
            process_9(pGData);
            break;


        default: return false;
    }
    /// NOTE: The output of the event will be printed on one line
    /// end by the endline character.
    return true;
}
