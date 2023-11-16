#include "vuz.h"
int main()
{
    system("chcp 65001");
    int choice;
    ifstream readFile;
    ofstream writeFile;
    string firstFile, secondFile;
    fstream file;
    while (true)
    {
        cout << "Меню.\n";
        cout << "1. Преобразование текстового файла в двоичный\n";
        cout << "2. Вывод записей из двоичного файла в текстовый\n";
        cout << "3. Вывод записей из двоичного файла в консоль\n";
        cout << "4. Получение n-й записи из двоичного файла\n";
        cout << "5. Удаление записи из двоичного файла по ключу\n";
        cout << "6. Сформировать список вузов, обучающих по конкретной специальности\n";
        cout << "7. Изменить код специальности по её названию\n";
        cout << "8. Завершить выполнение программы\n";
        cin >> choice;
        switch (choice)
        {
            case 1:
            {
                cout << "Введите название текстового файла: ";
                cin >> firstFile;
                cout << "Введите название двоичного файла: ";
                cin >> secondFile;
                readFile.open(firstFile);
                if (readFile.is_open())
                {
                    writeFile.open(secondFile, ios::binary);
                    createBinFile(readFile, writeFile);
                    if (!writeFile)
                    {
                        cout << "Возникла ошибка записи\n";
                        return 1;
                    }
                    else
                    {
                        cout << "Создание двоичного файла произошло успешно\n";
                        readFile.close();
                        writeFile.close();
                    }
                }
                else
                {
                    cout << "Текстовый файл не существует\n";
                }
                break;
            }
            case 2:
            {
                cout << "Введите название текстового файла: ";
                cin >> firstFile;
                cout << "Введите название двоичного файла: ";
                cin >> secondFile;
                readFile.open(secondFile, ios::binary);
                if (readFile.is_open())
                {
                    writeFile.open(firstFile);
                    readTextFromBin(readFile, writeFile);
                    if (readFile.bad() || writeFile.bad())
                    {
                        cout << "Возникла ошибка записи\n";
                        return 1;
                    }
                    else
                    {
                        cout << "Запись из двоичного файла в текстовый произошла успешно\n";
                        readFile.close();
                        writeFile.close();
                    }
                }
                else
                {
                    cout << "Двоичный файл не существует\n";
                }
                break;
            }
            case 3:
            {
                cout << "Введите название двоичного файла: ";
                cin >> firstFile;
                readFile.open(firstFile, ios::binary);
                if (readFile.is_open())
                {
                    printBinFile(readFile);
                    if (readFile.bad())
                    {
                        cout << "Возникла ошибка чтения\n";
                        return 1;
                    }
                    else
                    {
                        readFile.close();
                    }
                }
                else
                {
                    cout << "Двоичный файл не существует\n";
                }
                break;
            }
            case 4:
            {
                cout << "Введите название двоичного файла: ";
                cin >> firstFile;
                int n;
                cout << "Введите номер записи: ";
                cin >> n;
                readFile.open(firstFile, ios::binary);
                if (readFile.is_open())
                {
                    vuz x = getRecord(readFile, n);
                    cout << x.code << " | " << x.name << " | " << x.faculty <<
                         "\n";
                    if (readFile.bad())
                    {
                        cout << "Возникла ошибка чтения\n";
                        return 1;
                    }
                    else
                    {
                        readFile.close();
                    }
                }
                else
                {
                    cout << "Двоичный файл не существует\n";
                }
                break;
            }
            case 5:
            {
                cout << "Введите название двоичного файла: ";
                cin >> firstFile;
                string key;
                cout << "Введите ключ (номер специальности): ";
                cin >> key;
                file.open(firstFile, ios::binary | ios::in | ios::out);
                if (file.is_open())
                {
                    deleteRecord(file, key, firstFile);
                    if (file.bad())
                    {
                        cout << "Возникла ошибка чтения\n";
                        return 1;
                    }
                    else
                    {
                        file.close();
                        readFile.open(firstFile, ios::binary);
                        printBinFile(readFile);
                        readFile.close();
                    }
                }
                else
                {
                    cout << "Двоичный файл не существует\n";
                }
                break;
            }
            case 6:
            {
                cout << "Введите название текстового файла: ";
                cin >> firstFile;
                cout << "Введите название двоичного файла: ";
                cin >> secondFile;
                string key;
                cout << "Введите номер специальности: \n";
                cin >> key;
                readFile.open(secondFile, ios::binary);
                if (readFile.is_open())
                {
                    writeFile.open(firstFile);
                    getAllRecords(readFile, writeFile, key);
                    if (readFile.bad() || writeFile.bad())
                    {
                        cout << "Возникла ошибка записи\n";
                        return 1;
                    }
                    else
                    {
                        cout << "Запись из двоичного файла в текстовый произошла успешно\n";
                        readFile.close();
                        writeFile.close();
                    }
                }
                else
                {
                    cout << "Двоичный файл не существует\n";
                }
                break;
            }
            case 7:
            {
                cout << "Введите название двоичного файла: ";
                cin >> firstFile;
                string key, change;
                cout << "Введите название специальности: ";
                cin.get();
                getline(cin, key);
                cout << "Введите номер для замены: ";
                cin >> change;
                file.open(firstFile, ios::binary | ios::in | ios::out);
                if (file.is_open())
                {
                    changeRecords(file, key, change);
                    if (file.bad())
                    {
                        cout << "Возникла ошибка чтения\n";
                        return 1;
                    }
                    else
                    {
                        file.close();
                        readFile.open(firstFile, ios::binary);
                        printBinFile(readFile);
                        readFile.close();
                    }
                }
                else
                {
                    cout << "Двоичный файл не существует\n";
                }
                break;
            }
            default:
            {
                return 0;
            }
        }
    }
}
