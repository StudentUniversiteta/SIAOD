#include "File.h"
void createBinFile(ifstream &textFile, ofstream &binFile)
{
//    while (!textFile.eof())
//    {
//        car x;
//        char symbol;
//        textFile.getline(x.licensePlate, 30);
//        textFile.getline(x.brand, 30);
//        textFile.getline(x.owner, 100);
//        textFile.getline(x.stolen, 1);
//        binFile.write((char *)&x, sizeof(car));
//    }



/*
 * Создание двоичного файла из текстового
 * Скопировал из предыдущей твоей работы, вроде лучше работает, но выглядит как говно конечно
 * Сверху закоменчен оригинальный код, можно его попробовать если понравился
 */
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
    file.seekg(0, ios::end);
    int size = file.tellg();
    if (n * sizeof(car) >= size || n < 0) {
        return car();
    }
    file.seekg(n * sizeof(car), ios::beg);
    file.read((char *)&x, sizeof(car));
    return x;
}
car delRecord(fstream &file, int n, string filebrand)
{
    file.seekg(0, ios::end);
    int size = file.tellg();
    if (n * sizeof(car) >= size && n >= 0) {
        return car();
    }
    car lastRecord, record;
    file.seekg((-1) * sizeof(car), ios::end);
    file.read((char *)&lastRecord, sizeof(car));
    file.seekg(n * sizeof(car), ios::beg);
    file.read((char *)&record, sizeof(car));
    record = lastRecord;
    file.seekg((-1) * sizeof(car), ios::cur);
    file.write((char *)&record, sizeof(car));
    file.close();
    int desc = _open(filebrand.c_str(), O_RDWR);
    _chsize_s(desc, size - sizeof(car));
    _close(desc);
    file.open(filebrand, ios::binary);
    return lastRecord;
}
/*
 * ПОЯСНЕНИЕ ОТ ЧАТГПТ *
car delRecord(fstream &file, int n, string filebrand) - Это объявление функции с названием delRecord, принимающей файловый поток file, целочисленную переменную n и строку filebrand в качестве аргументов и возвращающей объект типа car.
file.seekg(0, ios::end) - Эта строка устанавливает указатель чтения/записи в конец файла.
int size = file.tellg() - Здесь мы записываем текущую позицию указателя в переменную size, чтобы узнать размер файла.
if (n * sizeof(car) >= size && n >= 0) - Это условие проверяет, если запись с номером n находится за пределами файла (больше или равна размеру файла) или n меньше нуля, то создается новый объект типа car и возвращается.
car lastRecord, record; - Объявляем две переменные типа car с именами lastRecord и record.
file.seekg((-1) * sizeof(car), ios::end) - Устанавливаем указатель чтения/записи на последнюю запись в файле.
file.read((char *)&lastRecord, sizeof(car)) - Читаем последнюю запись размером sizeof(car) из файла и сохраняем ее в lastRecord.
file.seekg(n * sizeof(car), ios::beg) - Перемещаем указатель чтения/записи на позицию n * sizeof(car) от начала файла.
file.read((char *)&record, sizeof(car)) - Читаем запись размером sizeof(car) из файла и сохраняем ее в record.
record = lastRecord; - Записываем содержимое lastRecord в record.
file.seekg((-1) * sizeof(car), ios::cur) - Перемещаем указатель чтения/записи на позицию, предшествующую текущей позиции на размер sizeof(car).
file.write((char *)&record, sizeof(car)) - Записываем содержимое record обратно в файл.
file.close() - Закрываем файл.
int desc = _open(filebrand.c_str(), O_RDWR) - Открываем файл с именем filebrand в режиме чтения и записи и сохраняем возвращенный файловый дескриптор в переменную desc.
_chsize_s(desc, size - sizeof(car)) - Изменяем размер файла, сокращая его на размер одной записи sizeof(car).
_close(desc) - Закрываем файловый дескриптор desc.
file.open(filebrand, ios::binary) - Открываем файл с именем filebrand в двоичном режиме.
return lastRecord - Возвращаем последнюю запись из файла.
 */


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
