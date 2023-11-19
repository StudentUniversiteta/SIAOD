#include "HashTable.h"



// TODO разобраться в том как работают хеш-таблицы, по сути весь код снизу

int hashFunc(string key, int size) {
    long long numericKey = 0;
    long long p = 1;
    for (char symbol : key) {
        numericKey += abs(symbol) * p;
        p *= 31;
    }
    return abs(numericKey % size);
}
void addNode(node*& start, element newElement) {
    if (start != nullptr) {
        node* q = start;
        while (q->next != nullptr) {
            q = q->next;
        }
        node* newNode = new node(newElement, nullptr);
        q->next = newNode;
    }
    else {
        start = new node(newElement, nullptr);
    }
}
int deleteNode(node*& start, string key) {
    node* q = start;
    if (q->value.key == key) {
        int pos = q->value.position;
        start = q->next;
        delete q;
        return pos;
    }
    while (q->next != nullptr && q->next->value.key != key) {
        q = q->next;
    }
    if (q->next != nullptr && q->next->value.key == key) {
        node* nextNode = q->next;
        int pos = nextNode->value.position;
        q->next = q->next->next;
        delete nextNode;
        return pos;
    }
    return -1;
}
node* findNode(node*& start, string key) {
    node* q = start;
    while (q != nullptr && q->value.key != key) {
        q = q->next;
    }
    return q;
}
void addElement(HashTable& table, element elem) {
    int hash = hashFunc(elem.key, table.size);
    if (table.array[hash] == nullptr) {
        table.filled++;
    }
    addNode(table.array[hash], elem);
    if (table.filled > 0.75 * table.size) {
        reHash(table);
    }
}
void printList(node* start) {
    node* q = start;
    while (q != nullptr) {
        cout << q->value.key << " ";
        q = q->next;
    }
}
void printTable(const HashTable& table) {
    for (int i = 0; i < table.size; i++) {
        cout << i << ": ";
        printList(table.array[i]);
        cout << "\n";
    }
}
int deleteElement(HashTable& table, string key) {
    int hash = hashFunc(key, table.size);
    return deleteNode(table.array[hash], key);
}
void reHash(HashTable& table) {
    cout << "Rehash from " << table.size << " elements to " << table.size * 2 <<
         "\n";
    node** newArray = new node*[(table.size * 2)];
    for (int i = 0; i < table.size * 2; i++) {
        newArray[i] = nullptr;
    }
    table.filled = 0;
    for (int i = 0; i < table.size; i++) {
        node* q = table.array[i];
        node* temp = q;
        while (q != nullptr) {
            int hash = hashFunc(q->value.key, table.size * 2);
            if (newArray[hash] == nullptr) {
                table.filled++;
            }
            addNode(newArray[hash], q->value);

            temp = q->next;
            delete q;
            q = temp;
        }
        if (q != nullptr) {
            delete temp;
        }
    }
    table.size *= 2;
    delete[] table.array;
    table.array = newArray;
}
int findElement(const HashTable& table, string key) {
    int hash = hashFunc(key, table.size);
    node* x = findNode(table.array[hash], key);
    if (x != nullptr)
        return findNode(table.array[hash], key)->value.position;
    return -1;
}
