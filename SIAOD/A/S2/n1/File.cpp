#include "File.h"
void printNumbers(istream& file) {
    double n;
    while (!file.eof()) {
        file >> n;
        cout << n << " ";
    }
}
void appendFile(ostream& file, int x) {
    file << "\n" << x;
}
int readNumber(istream& file, int n) {
    double a = INT32_MAX, i = 0;
    while (i <= n && !file.eof()) {
        file >> a;
        i++;
    }
    return a;
}
int countNumbers(istream& file) {
    double a, i = 0;
    while (!file.eof()) {
        file >> a;
        i++;
    }
    return i;
}
void makeNewFile(istream& file, ostream& newFile, int lines) {
    double a;
    file >> a;
    newFile << a / lines;
    while (!file.eof()) {
        file >> a;
        newFile << " " << a / lines;
    }
}
int countLines(istream& file) {
    string a;
    int i = 0;
    while (!file.eof()) {
        getline(file, a);
        i++;
    }
    return i;
}
