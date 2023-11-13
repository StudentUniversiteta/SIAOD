#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <stdint.h>
using namespace std;

void makeNewFile(istream& file, ostream& newFile, int lines);
int countLines(istream& file);
void printNumbers(istream& file);
void appendFile(ostream& file, int x);
int readNumber(istream& file, int n);
int countNumbers(istream& file);