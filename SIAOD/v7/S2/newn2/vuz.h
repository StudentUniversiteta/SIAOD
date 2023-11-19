#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "string.h"
#include <filesystem>
using namespace std;
struct vuz
{
    char code[30];
    char name[30];
    char faculty[100];
    vuz() {}
    /*
     В структуре vuz есть три строки:
     code, name и faculty,
     каждая из которых может содержать разное
     максимальное количество символов. (т.е. name - строка длиной 30 символов или меньше.
     Каждый символ весит байт, это нужно в отчете).
     */
};
void createBinFile(ifstream &textFile, ofstream &binFile);
void readTextFromBin(ifstream &binfile, ofstream &textFile);
void printBinFile(ifstream &file);
vuz getRecord(ifstream &file, int n);
void deleteRecord(fstream &file, string key, string filename);
void getAllRecords(ifstream &binFile, ofstream &textFile, string key);
void changeRecords(fstream &file, string key, string change);