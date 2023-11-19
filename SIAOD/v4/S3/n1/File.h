#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "string.h"
#include <io.h>
#include <fcntl.h>
using namespace std;

//
// УПРАВЛЕНИЕ ДВОИЧНЫМ ФАЙЛОМ
//
struct car
{
    char licensePlate[30]; //{""}
    char brand[30];
    char owner[100];
    char stolen[1];
    car() {}
};
void createBinFile(ifstream &textFile, ofstream &binFile);
void readTextFromBin(ifstream &binfile, ofstream &textFile);
void printBinFile(ifstream &file);
car getRecord(ifstream &file, int n);
car delRecord(fstream &file, int n, string filename);
void getAllRecords(ifstream &binFile, ofstream &textFile, string key);
void changeRecords(fstream &file, string key, string change);
