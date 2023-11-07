#include <iostream>     //need this for COUT and CIN
using namespace std;    //need this for COUT and CIN
#include <iomanip>
#include <stack>
#include <vector>
#include <cstdlib>      // for random numbers
#include <ctime>        // for random numbers

class DataItem
{
public:
    int data; // data item (key)

    // constructor
    DataItem(int newData)
    {
        data = newData;
    }
};