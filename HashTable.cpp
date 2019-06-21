#include "HashTable.h"
#include <cstddef>


HashTable::HashTable(){
    hashEntriesCount=0; // Κατασκευαστης
}


/*
    Κατασκευαστης οπου δημιουργει τον πινακα hashMap με 101 θεσεις και στην καθε θεση
    δημιουργω ενα πινακα entryValues ο οποιος θα περιεχει τις τιμε που ανοικουν στην αντιστοιχη
    διευθυνση. Τελος, αρχικοποιω και το entryCount σε 0 (καθως στην αρχη δεν υπαρχει κανενα στοιχειο
*/
HashTable::HashTable(unsigned int tableSize){
    hashEntriesCount=0;
    hashConstant=tableSize;
    hashMap = new HashEntry[tableSize];
    for(unsigned int i=0;i<tableSize;i++){
        hashMap[i].entryValues = new int[10];
        hashMap[i].entryCount=0;
    }
}

HashTable::~HashTable(){
    for(int i=0;i<hashConstant;i++)
        delete[] hashMap[i].entryValues; //Καταστροφεας
    delete[] hashMap;
}

int HashTable::getHashEntriesCount() { return hashEntriesCount; } //Επιστρεφει το πληθος των στοιχειων

/*
    Στην εξης συναρτηση εισαγω το στοιχειο entry. Εφοσον βρω το κλειδη με την βοηθεια της συναρτησης κατακερματισμου
    ελεγχω αν υπαρχει χωρος να εισαγω το στοιχειο στην αντιστοιχη θεση
    Εφοσον υπαρχει το εισαγω και αυξηνω το entryCount κατα 1
    Αλλιως δημιουργω εναν προσωρινο πινακα με entryCount+10 θεσεις και μεταφερω ολα τα στοιχεια + τον καινουργιο στοιχειο
    , επειτα διαγραφω τον παλιο πινακα οπου υπηρχαν τα στοιχεια και τον θετω ισο με το καινουργιο πινακα που δημιουργησα
*/
void HashTable::addEntry(int entry)
{
    int adress = entry % hashConstant;
    if((hashMap[adress].entryCount & 10) ==0)
    {
        int *tempEntry = new int[hashMap[adress].entryCount+10];
        for(int i=0;i<10;i++)
            tempEntry[i]=hashMap[adress].entryValues[i];
        tempEntry[hashMap[adress].entryCount]=entry;
        hashMap[adress].entryCount++;
        delete[] hashMap[adress].entryValues;
        hashMap[adress].entryValues = tempEntry;
        delete[] tempEntry;
    }else{
        hashMap[adress].entryValues[hashMap[adress].entryCount]=entry;
        hashMap[adress].entryCount++;
    }
    hashEntriesCount++;
}

/*
Εφοσον βρω την διευθυνση πηγαινω στο κελι που υπαρχει στο struct και ελεγχω τον πινακα entryValues
αν υπαρχει επιστρεφω SUCCESS αλλιως FAILURE
*/
std::string HashTable::searchHashTable(int entry){
    bool exists=false;
    int tempAdress = entry % hashConstant;
    for(int i=0; i<hashMap[tempAdress].entryCount; i++)
        if(entry == hashMap[tempAdress].entryValues[i]){
            exists=true;
            break;
        }
    if(exists)
        return "SUCCESS";
    else
        return "FAILURE";
}

