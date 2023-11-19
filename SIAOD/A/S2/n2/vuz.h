#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "string.h"
#include <filesystem>
#include <io.h>
#include <fcntl.h>
using namespace std;
struct vuz
{
    char code[30];
    char name[30];
    char faculty[100];
    vuz() {}
};
bool createBinaryFile(ifstream &textFile, ofstream &binaryFile);
void readTextFromBin(ifstream &binfile, ofstream &textFile);
void printBinFile(ifstream &file);
vuz getRecord(ifstream &file, int n);
void deleteRecord(fstream &file, string key, string filename);
void getAllRecords(ifstream &binFile, ofstream &textFile, string key);
void changeRecords(fstream &file, string key, string change);