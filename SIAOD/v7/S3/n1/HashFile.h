#include "HashTable.h"
#include "File.h"
#include <chrono>
//
// управление двоичным файлом посредством хэш-таблицы
//
void createHashTable(HashTable& table, ifstream& file);
vuz findRecord(HashTable& table, ifstream& file, string key);
void deleteRecord(HashTable& table, fstream& file, string key, string filename);