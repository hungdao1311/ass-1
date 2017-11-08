/*
 * =========================================================================================
 * Name        : dbLib.cpp
 * Author      : Duc Dung Nguyen, Nguyen Hoang Minh
 * Email       : nddung@hcmut.edu.vn
 * Copyright   : Faculty of Computer Science and Engineering - Bach Khoa University
 * Description : library for Assignment 1 - Data structures and Algorithms - Fall 2017
 *               This file implements functions used for database management
 * =========================================================================================
 */

#include "dbLib.h"

#include <time.h>
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <cmath>

#define pi 3.14159265358979323846
#define earthRadiusKm 6371.0

using namespace std;

void strPrintTime(char *des, time_t &t) {
    tm *pTime = localtime(&t);
    strftime(des, 26, "%Y-%m-%d %H:%M:%S", pTime);
}


void loadNinjaDB(char *fName, L1List<NinjaInfo_t> &db) {
    ifstream file;
    file.open(fName);
    string str1;
    L1Item<NinjaInfo_t> *tail = new L1Item<NinjaInfo_t>();
    getline(file, str1); //skip 1st line
    while (!file.eof()) {

        getline(file, str1,',');
        getline(file, str1,',');
        istringstream data(str1);
        struct tm tm;
        char empty;
        NinjaInfo_t temp;
        data >> tm.tm_mday >> empty >> tm.tm_mon >> empty >> tm.tm_year >> tm.tm_hour >> empty >> tm.tm_min >> empty >> tm.tm_sec;
        tm.tm_year -= 1900;
        tm.tm_mon -= 1;
        temp.timestamp = mktime(&tm);
        data.clear();

        getline(file, str1,',');
        data.str(str1);
        data >> temp.id;
        data.clear();


        getline(file, str1,',');
        data.str(str1);
        data >> temp.longitude;
        data.clear();


        getline(file, str1,',');
        data.str(str1);
        data >> temp.latitude;


        getline(file,str1,'\n');

        tail=db.push_back(temp,tail);

    }


}

bool parseNinjaInfo(char *pBuf, NinjaInfo_t &nInfo) {
    // TODO: write code to parse information from a string buffer, ignore if you don't use it
    return true;
}


void process(L1List<ninjaEvent_t> &eventList, L1List<NinjaInfo_t> &bList) {
    void *pGData = NULL;
    initNinjaGlobalData(&pGData);
    // loop counter
    int i,j = 0;

    // copied eventList
    L1List<ninjaEvent_t> eventHolder;
    L1Item<ninjaEvent_t> *tailEvent = new L1Item<ninjaEvent_t>();

    // ID list

    L1List<NinjaInfo_t> aggNinja;
    L1Item<NinjaInfo_t> *tailID = new L1Item<NinjaInfo_t>();
    NinjaInfo_t pHold = bList[0];

    bool checkExist(L1List<NinjaInfo_t> &list, char* id){
        int k = 0;
        while(k < list.getSize()){
            if(strcmp(list[k].id, id) == 0) return true;
            k++;
        }
        return false;
    }

    // store ID
    while(j < bList.getSize()){
        NinjaInfo_t temp(bList[j]);
        if(!checkExist(aggNinja, temp.id)){
            tailID=aggNinja.push_back(temp, tailID);
        }
        j++;
    }

    // store event
    while(i < eventList.getSize()){
        ninjaEvent_t temp(eventList[i].code);
        tailEvent=eventHolder.push_back(temp, tailEvent);
        i++;
    }

    while (!eventList.isEmpty()) {
        if (!processEvent(eventList[0], bList, pGData))
            cout << eventList[0].code << " is an invalid event\n";
        eventList.removeHead();
    }

    releaseNinjaGlobalData(pGData);
}


bool initNinjaGlobalData(void **pGData) {
    /// TODO: You should define this function if you would like to use some extra data
    /// the data should be allocated and pass the address into pGData
    return true;
}

void releaseNinjaGlobalData(void *pGData) {
    /// TODO: You should define this function if you allocated extra data at initialization stage
    /// The data pointed by pGData should be released
}


void printNinjaInfo(NinjaInfo_t &b) {
    printf("%s: (%0.5f, %0.5f), %s\n", b.id, b.longitude, b.latitude, ctime(&b.timestamp));
}

/// This function converts decimal degrees to radians
double deg2rad(double deg) {
    return (deg * pi / 180);
}

///  This function converts radians to decimal degrees
double rad2deg(double rad) {
    return (rad * 180 / pi);
}

/**
 * Returns the distance between two points on the Earth.
 * Direct translation from http://en.wikipedia.org/wiki/Haversine_formula
 * @param lat1d Latitude of the first point in degrees
 * @param lon1d Longitude of the first point in degrees
 * @param lat2d Latitude of the second point in degrees
 * @param lon2d Longitude of the second point in degrees
 * @return The distance between the two points in kilometers
 */
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d) {
    double lat1r, lon1r, lat2r, lon2r, u, v;
    lat1r = deg2rad(lat1d);
    lon1r = deg2rad(lon1d);
    lat2r = deg2rad(lat2d);
    lon2r = deg2rad(lon2d);
    u = sin((lat2r - lat1r) / 2);
    v = sin((lon2r - lon1r) / 2);
    return 2.0 * earthRadiusKm * asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
}
