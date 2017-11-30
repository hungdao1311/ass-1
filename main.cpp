#include <iostream>

#include "listLib.h"
#include "eventLib.h"
#include "dbLib.h"
# include <chrono>
using namespace std;
using  ns = chrono::seconds;
using get_time = chrono::steady_clock;

/// This function displays the content of database
void display(L1List<NinjaInfo_t>& nList) {
    cout.flush();
    nList.traverse(printNinjaInfo);
}

int main(int narg, char** argv) {
    auto start = get_time::now(); //use auto keyword to minimize typing strokes :)
    L1List<ninjaEvent_t>  eventList;
    L1List<NinjaInfo_t>   db;// database of NinjaInfo
    loadEvents(argv[1], eventList);
    loadNinjaDB(argv[2], db);


    cout << fixed << setprecision(12);// preset for floating point numbers
    /// Process events

    process(eventList, db);
    cout << db.getSize() << endl;
    cout << resetiosflags(ios::showbase) << setprecision(-1);

    auto end = get_time::now();
    auto diff = end - start;
    cout << "Elapsed time is :  " << chrono::duration_cast<ns>(diff).count() << " s " << endl;
    return 0;
}