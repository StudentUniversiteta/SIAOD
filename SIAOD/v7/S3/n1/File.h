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
struct vuz
{
    char code[10] {""};
    char name[30] {""};
    char faculty[20] {""};
    vuz() {}
};
void createBinFile(ifstream &textFile, ofstream &binFile);
void readTextFromBin(ifstream &binfile, ofstream &textFile);
void printBinFile(ifstream &file);
vuz getRecord(ifstream &file, int n);
vuz delRecord(fstream &file, int n, string filename);
void getAllRecords(ifstream &binFile, ofstream &textFile, string key);
void changeRecords(fstream &file, string key, string change);
