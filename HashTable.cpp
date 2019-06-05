#include "HashTable.h"
#include <cstddef>


HashTable::HashTable(){
    hashEntriesCount=0;
}

HashTable::HashTable(unsigned int tableSize){
    hashEntriesCount=0;
    hashConstant=tableSize;
    hashMap = new HashEntry[tableSize];
}

HashTable::~HashTable(){
    delete[] hashMap;
}

int HashTable::getHashEntriesCount() { return hashEntriesCount; }

void HashTable::addEntry(int entry)
{
    int adress = entry % hashConstant;
    hashMap[adress].entryValues.push_back(entry);
    hashEntriesCount++;
}

string HashTable::searchHashTable(int entry){
    bool exists=false;
    int tempAdress = entry % hashConstant;
    for(unsigned int i=0; i<hashMap[tempAdress].entryValues.size(); i++)
        if(entry == hashMap[tempAdress].entryValues[i]){
            exists=true;
            break;
        }
    if(exists)
        return "SUCCESS";
    else
        return "FAILURE";
}
