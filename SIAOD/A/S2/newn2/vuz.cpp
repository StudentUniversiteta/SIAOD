#include "vuz.h"
void createBinFile(ifstream &textFile, ofstream &binFile)
{
    while (!textFile.eof())
    {
        vuz x;
        char symbol;
        int i = 0;
        textFile.get(x.code[i]);
        while (x.code[i] != '\n')
        {
            i++;
            textFile.get(x.code[i]);
        }
        x.code[i] = '\0';
        i = 0;
        textFile.get(x.name[i]);
        while (x.name[i] != '\n')
        {
            i++;
            textFile.get(x.name[i]);
        }
        x.name[i] = '\0';
        i = 0;
        textFile.get(x.faculty[i]);
        while (x.faculty[i] != '\n' && !textFile.eof())
        {
            i++;
            textFile.get(x.faculty[i]);
        }
        x.faculty[i] = '\0';
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
    /*
     key - название
     change - номер
     */
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
    // Объясняшка от китайца:
    /*
     *
     * void changeRecords(fstream &file, string key, string change)
        Это объявление функции changeRecords. Она принимает ссылку на объект fstream для работы с файлом, а также две строки: key (ключ) и change (изменение).
        vuz x;

        Создается объект x типа vuz. Вероятно, тип vuz является пользовательским типом данных, который определен где-то в коде.
        file.read((char *)&x, sizeof(vuz));

        Эта строка читает данные из файла, на который ссылается fstream объект file, и сохраняет их в объекте x типа vuz. Она читает размер sizeof(vuz) байтов из файла.
        while (!file.eof())

        Этот цикл будет выполняться, пока не будет достигнут конец файла.
        if (x.faculty == key)

        Это условное выражение проверяет, равно ли значение атрибута faculty объекта x значению ключа key.
        strcpy(x.code, change.c_str());

        Это строка копирует содержимое строки change в атрибут code объекта x. Вероятно, code является массивом символов в объекте vuz.
        file.seekg(-sizeof(vuz), ios::cur);

        Это строка изменяет текущую позицию чтения файла. Она смещает позицию чтения на sizeof(vuz) байтов назад от текущей позиции. ios::cur указывает, что смещение выполняется относительно текущей позиции.
        file.write((char *)&x, sizeof(vuz));

        Эта строка записывает содержимое объекта x обратно в файл, перезаписывая старые данные размером sizeof(vuz) байтов.
        file.read((char *)&x, sizeof(vuz));

        Эта строка снова читает следующую порцию данных из файла в объект x. Это необходимо, чтобы продолжить цикл и проверить следующую запись.
     */
}
