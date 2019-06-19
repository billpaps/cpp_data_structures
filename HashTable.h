#include <vector>
#include <string>

#include <iostream>

/*
    Κλαση για το HashTable οπου εχει μια μεταβλητη
    hashEntriesCount για το ποσο στοιχεια υπαρχουν στον Πινακα
    μια hashConstant οπου χρησιμοποιειτε για την συναρτηση κατακερματισμου,
    το struct hashEntry το οποιο το χρησιμοποιω για να αναπαραστησω τον πινακα Κατακερματισμου

    Επισης συναρτησεις
    int getHashEntriesCount που επιστρεφει το πληθος των τιμων
    void addEntry για να εισαγω ΜΙΑ τιμη στον πινακα
    και string searchHashTable για να ελεγξω αν υπαρχει μια τιμη στο πινακα η οχι

    Επισης για τον πινακα Κατακερματισμου εχω χρησιμοποιησει ανοικτη διευθυνση καθως δεν υπαρχει διευκρινηση
    στην ασκηση, και εφοσον θελετε να εισαγουμε και αλλα στοιχεια εκτος τα αρχικα στον πινακα τοτε υπεθεσα οτι με
    την ανοικτη διευθυνση θα ηταν πιο ευκολο καθως θα αποφευγα το overflow σε περιπτωση οπου υπηρχε
*/

class HashTable{
protected:
    int hashEntriesCount;
    int hashConstant;
    struct HashEntry{
        int *entryValues;
        int entryCount;
    };
    HashEntry *hashMap;

public:
    HashTable();
    HashTable(unsigned int tableSize);
    ~HashTable();
    int getHashEntriesCount();
    void addEntry(int entry);
    std::string searchHashTable(int entry);

private:

};
