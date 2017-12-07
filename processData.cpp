/*
 * =========================================================================================
 * Name        : processData.cpp
 * Description : student code for Assignment 1 - Data structures and Algorithms - Fall 2017
 * =========================================================================================
 */
#include "eventLib.h"
#include "dbLib.h"

void printEvent(ninjaEvent_t &b) {
    cout << " " << b.code;
}

bool getIDp(L1Item<NinjaInfo_t> *&pHead, char *id, int &pos) {
    pos = 0;
    while (pHead) {
        if (strcmp(id, pHead->data.id) == 0) return true;
        pHead = pHead->pNext;
        pos++;
    }
    return false;
}

double getDistance(L1Item<NinjaInfo_t> *pHead, L1Item<NinjaInfo_t> *pDes) {
    return distanceEarth(pHead->data.latitude, pHead->data.longitude, pDes->data.latitude, pDes->data.longitude);
}

bool checkDistance(L1Item<NinjaInfo_t> *pHead, L1Item<NinjaInfo_t> *pDes) {
    if (!pDes) return false;
    return (getDistance(pHead, pDes) > 0.005);

}

bool getPreNextMove(L1Item<NinjaInfo_t> *pHead, L1Item<NinjaInfo_t> *&pDes) {
    if (!pHead) return false;
    pDes = pHead->pChild;
    if (!pDes) return false;
    if (checkDistance(pHead, pDes)) {
        pDes = pHead;
        return true;
    }
    while (pDes->pChild) {
        if (checkDistance(pHead, pDes->pChild)) return true;
        if (!(pDes->pChild)) return true;
        pDes = pDes->pChild;
    }
    return true;
}

bool getNextMove(L1Item<NinjaInfo_t> *pHead, L1Item<NinjaInfo_t> *&pDes) {
    if (!pHead) return false;
    pDes = pHead->pChild;
    if (checkDistance(pHead, pDes)) {
        pDes = pHead;
        return true;
    }
    while (pDes) {
        if (checkDistance(pHead, pDes)) return true;
        pDes = pDes->pChild;
    }
    return false;
}

bool getNextStop(L1Item<NinjaInfo_t> *pHead, L1Item<NinjaInfo_t> *&pDes) {
    if (!pHead) return false;
    pDes = pHead->pChild;
    while (pDes) {
        if (checkDistance(pHead, pDes)) {
            pHead = pDes;
            pDes = pDes->pChild;
        } else {
            pDes = pHead;
            return true;
        }
    }
    return false;
}

void process_0(void *pGData) {
    L1List<ninjaEvent_t> *event;
    event = static_cast<L1List<ninjaEvent_t> *>(pGData);
    cout << "0:";
    event->traverse(printEvent);
    cout << endl;
}

void process_2(void* pGData) {
    char *id;
    id = static_cast<char*>(pGData);
    cout << "2: " << id << endl;
}

void process_3(L1List<NinjaInfo_t> &nList) {
    cout << "3: " << nList.getSize() << endl;
}

void process_4(L1List<NinjaInfo_t> &nList) {
    L1Item<NinjaInfo_t> *node = nList.getHead();
    if(!node) {
        cout << "4: empty" << endl;
        return;
    }
    const char *temp = node->data.id;
    while (node) {
        if (strcmp(temp, node->data.id) < 0) {
            temp = node->data.id;
        }
        node = node->pNext;
    }
    cout << "4: " << temp << endl;
}

void process_5(L1List<NinjaInfo_t> &nList, char *code) {
    L1Item<NinjaInfo_t> *temp5 = nList.getHead();
    if(!temp5) {
        cout << code << ": -1" << endl;
        return;
    }
    L1Item<NinjaInfo_t> *des5 = new L1Item<NinjaInfo_t>();
    char ptime[19];
    int trash;
    cout << code << ": ";
    if (getIDp(temp5, code + 1, trash) && getNextMove(temp5, des5)) {
        strPrintTime(ptime, des5->data.timestamp);
        cout << ptime << endl;
    } else {
        cout << "-1" << endl;
    }
}

void process_6_7(L1List<NinjaInfo_t> &nList, char *code) {
    L1List<NinjaInfo_t> stopList;
    L1Item<NinjaInfo_t> *temp6 = nList.getHead();
    if(!temp6) {
        cout << code << ": -1" << endl;
        return;
    }
    L1Item<NinjaInfo_t> *des6 = new L1Item<NinjaInfo_t>();
    char ptime[19];
    int trash;
    cout << code << ": ";
    if (getIDp(temp6, code + 1, trash)) {
        if (!checkDistance(temp6, temp6->pChild)) {
            stopList.push_back(temp6->data);
        }
        while (getNextMove(temp6, des6)) {
            if (getNextStop(des6, temp6)) {
                stopList.push_back(temp6->data);
            } else break;
        }
        strPrintTime(ptime, stopList.getTail()->data.timestamp);
        if (code[0] == '6') cout << ptime << endl;
        if (code[0] == '7') cout << stopList.getSize() << endl;
    } else {
        cout << "-1" << endl;
    }
}

void process_9(L1List<NinjaInfo_t> &bList, void *&pGData) {
    if(bList.getSize() == 0){
        cout << "9: -1" << endl;
        return;
    }
    double *dArray = new double[bList.getSize()];
    int arrCount = 0;
    char *maxDistID;
    double tempMax = 0;
    L1Item<NinjaInfo_t> *tempDist = bList.getHead();
    while (tempDist) {
        L1Item<NinjaInfo_t> *tempHead = tempDist;
        L1Item<NinjaInfo_t> *tempChild = tempDist->pChild;
        while (tempChild) {
            dArray[arrCount] += getDistance(tempHead, tempChild);
            tempHead = tempChild;
            tempChild = tempChild->pChild;
        }
        if (dArray[arrCount] > tempMax) {
            tempMax = dArray[arrCount];
            maxDistID = tempDist->data.id;
        }
        arrCount++;
        tempDist = tempDist->pNext;
    }
    cout << "9: " << maxDistID << endl;
};

void process_8(L1List<NinjaInfo_t> &nList, char *code) {
    L1Item<NinjaInfo_t> *temp8 = nList.getHead();
    if(!temp8) {
        cout << code << ": -1" << endl;
        return;
    }
    double distance = 0;
    int trash;
    cout << code << ": ";
    if (getIDp(temp8, code + 1, trash)) {
        L1Item<NinjaInfo_t> *tempChild = temp8->pChild;
        while (tempChild) {
            distance += getDistance(temp8, tempChild);
            temp8 = tempChild;
            tempChild = tempChild->pChild;
        }
        cout << distance << endl;
    } else {
        cout << "-1" << endl;
    }
}



void process_10_12(L1List<NinjaInfo_t> &nList, char code) {
    L1Item<NinjaInfo_t> *temp10 = nList.getHead();
    if(!temp10) {
        cout << "1" << code << ": -1" << endl;
        return;
    }
    temp10->pTailchild = nList.getHead()->pTailchild;
    double stoptime = 0, movetime = 0;
    char *tempMaxID, *tempMinID;
    while (temp10) {
        L1Item<NinjaInfo_t> *tempHead = temp10;
        L1Item<NinjaInfo_t> *des10 = new L1Item<NinjaInfo_t>();
        double temptime = 0, temptime2 = 0;
        while (tempHead) {
            getNextStop(tempHead, des10);
            if (!des10) break;
            getPreNextMove(des10, tempHead);
            temptime += difftime(tempHead->data.timestamp, des10->data.timestamp);
            tempHead = tempHead->pChild;
        }
        temptime2 = difftime(temp10->pTailchild->data.timestamp, temp10->data.timestamp) - temptime;

        if (temptime > stoptime) {
            stoptime = temptime;
            tempMaxID = temp10->data.id;
        }

        if (temptime2 > movetime) {
            movetime = temptime2;
            tempMinID = temp10->data.id;
        }
        temp10 = temp10->pNext;
    }
    if (code == '0') {
        cout << "10: " << tempMinID << endl;
    } else {
        cout << "12: " << tempMaxID << endl;
    }
}

void process_11(L1List<NinjaInfo_t> &nList, char *code) {
    L1Item<NinjaInfo_t> *temp = nList.getHead();
    char *delID = "0000";
    int pos = 0, count = 0;
    while (temp) {
        if (strcmp(delID, temp->data.id) < 0 && strcmp(code + 2, temp->data.id) > 0) {
            delID = temp->data.id;
            count = pos;
        }
        temp = temp->pNext;
        pos++;
    }
    if (delID == "0000") {
        cout << code << ": -1" << endl;
    } else {
        cout << code << ": " << delID << endl;
        nList.remove(count);
    }
}



void process_14(L1List<NinjaInfo_t> &nList) {
    cout << "14:";
    L1Item<NinjaInfo_t> *temp14 = nList.getHead();
    if(!temp14) {
        cout  << " -1" << endl;
        return;
    }
    while (temp14) {
        //create checkpoint list
        L1List<NinjaInfo_t> templist;
        bool Lost = false;
        L1Item<NinjaInfo_t> *head14 = temp14;
        L1Item<NinjaInfo_t> *des14 = new L1Item<NinjaInfo_t>();
        if (!checkDistance(head14, head14->pChild)) {
            templist.push_back(head14->data);
        }
        while (getNextMove(head14, des14)) {
            getNextStop(des14, head14);
            while (head14 != des14) {
                templist.push_back(des14->data);
                des14 = des14->pChild;
            }
            if (head14) {
                templist.push_back(head14->data);
            }
        }
        if(templist.getSize() < 2) continue;
        L1Item<NinjaInfo_t>* tempdes = templist.getHead()->pNext->pNext;
        while(tempdes != templist.getTail()){
            L1Item<NinjaInfo_t>* temphead = templist.getHead();
            while(temphead != tempdes){
                if(!checkDistance(temphead,tempdes)){
                    Lost = true;
                    break;
                }
                temphead = temphead->pNext;
            }
            if(Lost) break;
            tempdes = tempdes->pNext;
        }
        if(Lost) cout <<" " << temp14->data.id ;
        temp14 = temp14->pNext;
    }
    cout << endl;
}

bool processEvent(ninjaEvent_t &event, L1List<NinjaInfo_t> &nList, void *pGData) {
    // TODO: Your code comes here

    switch (event.code[0]) {
        case '0':
            process_0(pGData);
            break;
        case '1': {
            switch (event.code[1]) {
                case '\0':
                    char *id;
                    id = static_cast<char*>(pGData);
                    cout << "1: " << id << endl;
                    break;
                case '0' :
                    if (event.code[2] != '\0') return false;
                    process_10_12(nList, '0');
                    break;
                case '1':
                    if (event.code[2] == '\0') return false;
                    process_11(nList, event.code);
                    break;
                case '2':
                    if (event.code[2] != '\0') return false;
                    process_10_12(nList, '2');
                    break;
                case '3':
                    if (event.code[2] == '\0') return false;
                    else return true;
                case '4':
                    if (event.code[2] != '\0') return false;
                    process_14(nList);
                    break;
                default:
                    return false;
            }
            break;
        }
        case '2':
            if (event.code[1] != '\0') return false;
            process_2(pGData);
            break;
        case '3':
            if (event.code[1] != '\0') return false;
            process_3(nList);
            break;
        case '4':
            if (event.code[1] != '\0') return false;
            process_4(nList);
            break;
        case '5':
            if (event.code[1] == '\0') return false;
            process_5(nList, event.code);
            break;
        case '6':
            if (event.code[1] == '\0') return false;
            process_6_7(nList, event.code);
            break;
        case '7':
            if (event.code[1] == '\0') return false;
            process_6_7(nList, event.code);
            break;
        case '8':
            if (event.code[1] == '\0') return false;
            process_8(nList, event.code);
            break;
        case '9':
            if (event.code[1] != '\0') return false;
            if(nList.getSize() == 0) {
                cout << "9: -1" << endl;
                break;
            }
            process_9(nList, pGData);
            break;


        default:
            return false;
    }
    /// NOTE: The output of the event will be printed on one line
    /// end by the endline character.
    return true;
}
