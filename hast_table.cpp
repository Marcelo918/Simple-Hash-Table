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
}