#include <vector>
#include <string>

using namespace std;

class HashTable{
protected:
    int hashEntriesCount;
    int hashConstant;
    struct HashEntry{
        vector<int> entryValues;
    };
    HashEntry *hashMap;

public:
    HashTable();
    HashTable(unsigned int tableSize);
    ~HashTable();
    int getHashEntriesCount();
    void addEntry(int entry);
    string searchHashTable(int entry);

private:

};
