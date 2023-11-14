/*
# ******************************************************************************
# *                               COPYRIGHT NOTICE                             *
# ******************************************************************************
# *                                                                            *
# *  This code is authored by Marcelo Villalobos Diaz                          *
# *  You are free to use, modify, and distribute this code, provided           *
# *  you give appropriate credit by including the author's name.               *
# *                                                                            *
# *  Copyright (c) 2023 Marcelo Villalobos Diaz                                *
# *                                                                            *
# ******************************************************************************
*/

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

    int hashFunc(int key)
    {
        return key % arraySize; // hash function
    }

    void insert(DataItem *pItem) // insert a DataItem. Assumes table is not full
    {
        int key = pItem->data;       // extract key
        int hashVal = hashFunc(key); // hash the key until empty cell or -1

        while (hashArray[hashVal] != NULL && hashArray[hashVal]->data != -1)
        {
            ++hashVal;            // go to next cell
            hashVal %= arraySize; // wraparound if necessary
        }

        hashArray[hashVal] = pItem; // insert item
    }

    DataItem *remove(int key) // remove a DataItem
    {
        int hashVal = hashFunc(key); // hash the key

        while (hashArray[hashVal] != NULL)
        {
            if (hashArray[hashVal]->data == key) // found key?
            {
                DataItem *pTemp = hashArray[hashVal]; // save item
                hashArray[hashVal] = pNonItem;        // delete item
                return pTemp;                         // return item
            }

            ++hashVal;            // go to next cell
            hashVal %= arraySize; // wraparound if necessary
        }
        return NULL; // can't find item
    }

    DataItem *find(int key) // find item with key
    {
        int hashVal = hashFunc(key); // hash the key

        while (hashArray[hashVal] != NULL) // until empty cell
        {
            if (hashArray[hashVal]->data == key) // found the key?
            {
                return hashArray[hashVal]; // yes, return item
            }

            ++hashVal;            // go to next cell
            hashVal %= arraySize; // wraparound if necessary
        }
        return NULL; // can't find item
    }
};

int main()
{
    DataItem *pDataItem;
    int aKey, size, n, keysPerCell;
    time_t aTime;
    char choice;
    // get sizes
    cout << "Enter size of hash table: ";
    cin >> size;
    cout << "Enter initial number of items: ";
    cin >> n;
    keysPerCell = 10;

    HashTable theHashTable(size);               // make table
    srand(static_cast<unsigned>(time(&aTime))); // make random list of numbers
    for (int j = 0; j < n; j++)                 // insert data
    {
        aKey = rand() % (keysPerCell * size); // r
        pDataItem = new DataItem(aKey);
        theHashTable.insert(pDataItem);
    }

    while (choice != 'q')
    {
        cout << "Enter first letter of show, insert, delete, or find: ";
        cin >> choice;
        switch (choice)
        {
        case 's':
            theHashTable.displayTable();
            break;
        case 'i':
            cout << "Enter key value to insert: ";
            cin >> aKey;
            pDataItem = new DataItem(aKey);
            theHashTable.insert(pDataItem);
            break;
        case 'd':
            cout << "Enter key value to delete: ";
            cin >> aKey;
            theHashTable.remove(aKey);
            break;
        case 'f':
            cout << "Enter key value to find: ";
            cin >> aKey;
            pDataItem = theHashTable.find(aKey);
            if (pDataItem != NULL)
            {
                cout << "Found " << aKey << endl;
            }
            else
            {
                cout << "Could not find " << aKey << endl;
            }
            break;
        case 'q':
            cout << "Goodbye! See you soon." << endl;
            break;
        default:
            cout << "Invalid entry\n";
            break;
        }
    }
}