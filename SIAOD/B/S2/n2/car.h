#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "string.h"
#include <filesystem>
using namespace std;
struct car
{
    char licensePlate[30]; //номер машины + КЛЮЧ
    char brand[30]; //марка
    char owner[100]; //сведения о владельце
    char stolen[1]; //сведения об угоне (логического типа)
    car() {}
};
void createBinFile(ifstream &textFile, ofstream &binFile); //создать двоичный файл из текстового
void readTextFromBin(ifstream &binfile, ofstream &textFile); //Вывод записей из двоичного файла в текстовый
void printBinFile(ifstream &file); //вывести двоичный файл в консось
car getRecord(ifstream &file, int n); //Получение n-й записи из двоичного файла
void deleteRecord(fstream &file, string key, string filename); //удалить запись по ключу
void getAllRecords(ifstream &binFile, ofstream &textFile, string key); //список угнанных авто
void changeRecords(fstream &file, string key, string change); //изменить статус угнанности авто по заданному номеру