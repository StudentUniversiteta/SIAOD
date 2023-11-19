#include "car.h"
void createBinFile(ifstream &textFile, ofstream &binFile)
{
    while (!textFile.eof())
    {
        car x;
        char symbol;
        int i = 0;
        textFile.get(x.licensePlate[i]);
        while (x.licensePlate[i] != '\n')
        {
            i++;
            textFile.get(x.licensePlate[i]);
        }
        x.licensePlate[i] = '\0';
        i = 0;
        textFile.get(x.brand[i]);
        while (x.brand[i] != '\n')
        {
            i++;
            textFile.get(x.brand[i]);
        }
        x.brand[i] = '\0';
        i = 0;
        textFile.get(x.owner[i]);
        while (x.owner[i] != '\n' && !textFile.eof())
        {
            i++;
            textFile.get(x.owner[i]);
        }
        x.owner[i] = '\0';
        i = 0;
        textFile.get(x.stolen[i]);
        while (x.stolen[i] != '\n' && !textFile.eof())
        {
            i++;
            textFile.get(x.stolen[i]);
        }
        x.stolen[i] = '\0';
        binFile.write((char *)&x, sizeof(car));
    }
}
void printBinFile(ifstream &file)
{
    car x;
    file.read((char *)&x, sizeof(car));
    while (!file.eof())
    {
        cout << x.licensePlate << " | " << x.brand << " | " << x.owner << " | " << x.stolen << "\n";
        file.read((char *)&x, sizeof(car));
    }
}
car getRecord(ifstream &file, int n)
{
    car x;
    file.seekg(n * sizeof(car), ios::beg);
    file.read((char *)&x, sizeof(car));
    if (file.bad())

        return car();
    return x;
}
void deleteRecord(fstream &file, string key, string filebrand)
{
    car lastRecord, record;
    file.seekg(-sizeof(car), ios::end);
    file.read((char *)&lastRecord, sizeof(car));
    file.seekg(0, ios::beg);
    file.read((char *)&record, sizeof(car));
    int size = 0;
    while (!file.eof()) {
        file.read((char *)&record, sizeof(car));
        size++;
    }
    file.close();
    file.open(filebrand, ios::binary | ios::in | ios::out);
    file.read((char *)&record, sizeof(car));
    while (!file.eof() && record.licensePlate != key) {
        file.read((char *)&record, sizeof(car));
    }
    if (record.licensePlate == key) {
        record = lastRecord;
        file.seekg(-sizeof(car), ios::cur);
        file.write((char *)&record, sizeof(car));
        file.close();
        auto p = filesystem::path(filebrand);
        filesystem::resize_file(p, (size - 1) * sizeof(car));
        file.open(filebrand, ios::binary);
    }
}
void readTextFromBin(ifstream &binFile, ofstream &textFile)
{
    car x;
    binFile.read((char *)&x, sizeof(car));
    while (!binFile.eof())
    {
        textFile << x.licensePlate << '\n'
                 << x.brand << '\n'
                 << x.owner << '\n'
                 << x.stolen;
        binFile.read((char *)&x, sizeof(car));
        if (!binFile.eof())
        {
            textFile << '\n';
        }
    }
}
void getAllRecords(ifstream &binFile, ofstream &textFile, string key)
{
    car x;
    binFile.read((char *)&x, sizeof(car));
    while (!binFile.eof())
    {
        if (x.stolen == key)
        {
            textFile << x.licensePlate << '\n'
                     << x.brand << '\n'
                     << x.owner << '\n'
                     << x.stolen << '\n';
            binFile.read((char *)&x, sizeof(car));
            if (!binFile.eof())
            {
                textFile << '\n';
            }
        }
        else
            binFile.read((char *)&x, sizeof(car));
    }
}
void changeRecords(fstream &file, string key, string change)
{
    /*
     key - номер автомобиля
     change - угнан ли он
     */
    car x;
    file.read((char *)&x, sizeof(car));
    while (!file.eof())
    {
        if (x.licensePlate == key)
        {
            strcpy(x.stolen, change.c_str()); //меняет значение x.stolen на change (прописанный нами 1/0)
            file.seekg(-sizeof(car), ios::cur); //позиция чтения файла смещается на sizeof(car) байтов назад
            file.write((char *)&x, sizeof(car)); //содержимое объекта переписывается обратно в файл
        }
        file.read((char *)&x, sizeof(car)); //файл снова считывается для продолжения цикла
    }
}
