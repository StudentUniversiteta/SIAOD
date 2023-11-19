#pragma once
#include <iostream>
#include <string>
using namespace std;
//
// УПРАВЛЕНИЕ ХЭШ-ТАБЛИЦЕЙ
//
class element {
public:
    string key;
    int position;
    element(): key(""), position(-1) {}
    element(string key, int position): key(key), position(position) {}
};
class node {
public:
    element value;
    node* next;
    node(): value(element()), next(nullptr) {}
    node(element value, node* next): value(value), next(next) {}
};
class HashTable {
public:
    unsigned int size = 5;
    unsigned int filled = 0;
    node** array = new node*[size];
    HashTable() {
        for (int i = 0; i < size; i++) {
            array[i] = nullptr;
        }
    }
    ~HashTable() {
        for (int i = 0; i < size; i++) {
            node* q = array[i];
            node* t = q;
            while (q != nullptr) {
                t = q->next;
                delete q;
                q = t;
            }
        }
        delete[] array;
    }
};
int hashFunc(string key, int size);
void addNode(node*& start, element newElement);
int deleteNode(node*& start, string key);
node* findNode(node*& start, string key);
int findElement(const HashTable& table, string key);
void addElement(HashTable& table, element elem);
void printTable(const HashTable& table);
void printList(node* start);
int deleteElement(HashTable& table, string key);
void reHash(HashTable& table);
