#include "HashFile.h"
/*
 * тут немножко пришлось изменять, потому что
 * у меня ключ изменился, а у тебя остался тем же номером автомобиля
 * будь внимательна
 */
void createHashTable(HashTable& table, ifstream& file) {
    car record;
    element elem;
    int position = 0;
    file.read((char*)&record, sizeof(car));
    while (!file.eof()) {
        elem.position = position;
        //elem.key = record.brand;
        elem.key = record.licensePlate;
        addElement(table, elem);
        position++;
        file.read((char*)&record, sizeof(car));
    }
}
car findRecord(HashTable& table, ifstream& file, string key) {
    int n = findElement(table, key);
    return getRecord(file, n);
}
/*
 * здесь та же небольшая головоёбка с ключами, твой ключ - licensePlate, по нему удаляем
 */
void deleteRecord(HashTable& table, fstream& file, string key, string filebrand) {
    int n = deleteElement(table, key);
    car record = delRecord(file, n, filebrand);
    //if (record.licensePlate != "" && record.brand != key) {
    if (record.licensePlate == key){
        element elem(record.brand, n);
        deleteElement(table, elem.key);
        addElement(table, elem);
    }
}
