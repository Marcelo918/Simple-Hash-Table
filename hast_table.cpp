#include <iostream>  //need this for COUT and CIN
using namespace std; // need this for COUT and CIN
#include <iomanip>
#include <stack>
#include <vector>
#include <cstdlib> // for random numbers
#include <ctime>   // for random numbers

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

class HashTable
{
private:
    vector<DataItem *> hashArray; // vector holds hash table
    int arraySize;
    DataItem *pNonItem; // for deleted items

public:
    HashTable(int size) // constructor
    {
        arraySize = size;
        hashArray.resize(arraySize);        // size the vector
        for (int j = 0; j < arraySize; j++) // initialize elements
        {
            hashArray[j] = NULL;
        }
        pNonItem = new DataItem(-1); // deleted item key is -1
    }

    void displayTable()
    {
        cout << "Table: ";
        for (int j = 0; j < arraySize; j++)
        {
            if (hashArray[j] != NULL)
            {
                cout << hashArray[j]->data << " ";
            }
            else
            {
                cout << "** ";
            }
        }
        cout << endl;
    }
};