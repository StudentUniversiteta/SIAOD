#include "vuz.h"
bool createBinaryFile(ifstream &textFile, ofstream &binaryFile)
{
    string firstFile, secondFile;
    wcout<<"Введите название текстового файла: "<<endl;
    cin>>firstFile;
    wcout<<"Введите название двоичного файла: "<<endl;
    cin>>secondFile;
    while (!textFile.eof())
    {

        textFile.open(firstFile);
        binaryFile.open(secondFile, ios::binary);
        if (!textFile)
        {
            wcout << "Не удалось открыть текстовый файл!" << std::endl;
            return 1;
        }
        if (!binaryFile)
        {
            std::cerr << "Не удалось открыть двоичный файл!" << std::endl;
            return 1;
        }
        char c;
        // Читаем символы из текстового файла, пока не достигнем конца файла
        while (textFile.get(c)) {
            // Записываем символ в двоичный файл
            binaryFile.write(reinterpret_cast<const char*>(&c), sizeof(c));
        }

        // Закрываем файлы
        textFile.close();
        binaryFile.close();

        std::wcout << "Конвертация завершена!" << std::endl;

        return 0;
    }

}
void printBinFile(ifstream &file)
{
    vuz x;
    //file.open("C:\\Users\\artez\\Desktop\\output.bin", ios::binary);
    file.read((char *)&x, sizeof(vuz));
    while (!file.eof())
    {

        wcout << x.code << " | " << x.name << " | " << x.faculty << endl;
        file.read((char *)&x, sizeof(vuz));
    }
}
vuz getRecord(ifstream &file, int n)
{
    vuz x;
    file.seekg(n * sizeof(vuz), ios::beg);
    file.read((char *)&x, sizeof(vuz));
    if (file.bad())
        return vuz();
    return x;
}
void deleteRecord(fstream &file, string key, string filename)
{
    vuz lastRecord, record;
    file.seekg(-sizeof(vuz), ios::end);
    file.read((char *)&lastRecord, sizeof(vuz));
    file.seekg(0, ios::beg);
    file.read((char *)&record, sizeof(vuz));
    int size = 0;
    while (!file.eof()) {
        file.read((char *)&record, sizeof(vuz));
        size++;
    }
    file.close();
    file.open(filename, ios::binary | ios::in | ios::out);
    file.read((char *)&record, sizeof(vuz));
    while (!file.eof() && record.code != key) {
        file.read((char *)&record, sizeof(vuz));
    }
    if (record.code == key) {
        record = lastRecord;
        file.seekg(-sizeof(vuz), ios::cur);
        file.write((char *)&record, sizeof(vuz));
        file.close();
        auto p = filesystem::path(filename);
        filesystem::resize_file(p, (size - 1) * sizeof(vuz));
        file.open(filename, ios::binary);
    }
}
void readTextFromBin(ifstream &binaryFile, ofstream &textFile)
{
    //string binF = "C:\\Users\\artez\\Desktop\\output.bin";
    vuz x;
    binaryFile.read((char *)&x, sizeof(vuz));
    while (!binaryFile.eof())
    {
        textFile << x.code << '\n'
                 << x.name << '\n'
                 << x.faculty;
        binaryFile.read((char *)&x, sizeof(vuz));
        if (!binaryFile.eof())
        {
            textFile << '\n';
        }
    }
}
void getAllRecords(ifstream &binFile, ofstream &textFile, string key)
{
    vuz x;
    binFile.read((char *)&x, sizeof(vuz));
    while (!binFile.eof())
    {
        if (x.code == key)
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
        else
            binFile.read((char *)&x, sizeof(vuz));
    }
}
void changeRecords(fstream &file, string key, string change)
{
    vuz x;
    file.read((char *)&x, sizeof(vuz));
    while (!file.eof())
    {
        if (x.faculty == key)
        {
            strcpy(x.code, change.c_str());
            file.seekg(-sizeof(vuz), ios::cur);
            file.write((char *)&x, sizeof(vuz));
        }
        file.read((char *)&x, sizeof(vuz));
    }
}
