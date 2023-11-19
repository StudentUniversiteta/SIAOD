#include "HashFile.h"
void createHashTable(HashTable& table, ifstream& file) {
    vuz record;
    element elem;
    int position = 0;
    file.read((char*)&record, sizeof(vuz));
    while (!file.eof()) {
        elem.position = position;
        elem.key = record.name;
        addElement(table, elem);
        position++;
        file.read((char*)&record, sizeof(vuz));
    }
}
vuz findRecord(HashTable& table, ifstream& file, string key) {
    int n = findElement(table, key);
    return getRecord(file, n);
}
void deleteRecord(HashTable& table, fstream& file, string key, string filename) {
    int n = deleteElement(table, key);
    vuz record = delRecord(file, n, filename);
    if (record.code != "" && record.name != key) {
        element elem(record.name, n);
        deleteElement(table, elem.key);
        addElement(table, elem);
    }
}
