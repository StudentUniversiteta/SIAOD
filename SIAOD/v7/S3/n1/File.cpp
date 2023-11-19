#include "File.h"
void createBinFile(ifstream &textFile, ofstream &binFile)
{
    while (!textFile.eof())
    {
        vuz x;
        char symbol;
        textFile.getline(x.code, 10);
        textFile.getline(x.name, 30);
        textFile.getline(x.faculty, 20);
        binFile.write((char *)&x, sizeof(vuz));
    }
}
void printBinFile(ifstream &file)
{
    vuz x;
    file.read((char *)&x, sizeof(vuz));
    while (!file.eof())
    {
        cout << x.code << " | " << x.name << " | " << x.faculty << "\n";
        file.read((char *)&x, sizeof(vuz));
    }
}
vuz getRecord(ifstream &file, int n)
{
    vuz x;
    file.seekg(0, ios::end);
    int size = file.tellg();
    if (n * sizeof(vuz) >= size || n < 0) {
        return vuz();
    }
    file.seekg(n * sizeof(vuz), ios::beg);
    file.read((char *)&x, sizeof(vuz));
    return x;
}
vuz delRecord(fstream &file, int n, string filename)
{
    file.seekg(0, ios::end);
    int size = file.tellg();
    if (n * sizeof(vuz) >= size && n >= 0) {
        return vuz();
    }
    vuz lastRecord, record;
    file.seekg((-1) * sizeof(vuz), ios::end);
    file.read((char *)&lastRecord, sizeof(vuz));
    file.seekg(n * sizeof(vuz), ios::beg);
    file.read((char *)&record, sizeof(vuz));
    record = lastRecord;
    file.seekg((-1) * sizeof(vuz), ios::cur);
    file.write((char *)&record, sizeof(vuz));
    file.close();
    int desc = _open(filename.c_str(), O_RDWR);
    _chsize_s(desc, size - sizeof(vuz));
    _close(desc);
    file.open(filename, ios::binary);
    return lastRecord;
}
void readTextFromBin(ifstream &binFile, ofstream &textFile)
{
    vuz x;
    binFile.read((char *)&x, sizeof(vuz));
    while (!binFile.eof())
    {
        textFile << x.code << '\n'
                 << x.name << '\n'
                 << x.faculty;
        binFile.read((char *)&x, sizeof(vuz));
        if (!binFile.eof())
        {
            textFile << '\n';
        }
    }
}
