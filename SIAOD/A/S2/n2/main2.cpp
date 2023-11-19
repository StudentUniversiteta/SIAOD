#include "vuz.h"
#include <locale>
int main()
{
    // Устанавливаем русскую локаль
    std::locale::global(std::locale("ru_RU.utf8"));

    // Устанавливаем правильную кодировку для std::cout
    std::cout.imbue(std::locale());

    int choice;
    ifstream textFile;
    ofstream binaryFile;
    fstream file;
    string firstFile, secondFile;
    while (true)
    {
        wcout << "Меню.\n";
        wcout << "1. Преобразование текстового файла в двоичный\n";
        wcout << "2. Вывод записей из двоичного файла в текстовый\n";
        wcout << "3. Вывод записей из двоичного файла в консоль\n";
        wcout << "4. Получение n-й записи из двоичного файла\n";
        wcout << "5. Удаление записи из двоичного файла по ключу\n";
        wcout << "6. Сформировать список вузов, обучающих по конкретной специальности\n";
        wcout << "7. Изменить код специальности по её названию\n";
        wcout << "8. Завершить выполнение программы\n";
        cin >> choice;
        switch (choice)
        {
            case 1:
            {
                createBinaryFile(textFile, binaryFile);
                break;
            }
            case 2:
            {
                wcout << "Введите название текстового файла: ";
                cin >> firstFile;
                wcout << "Введите название двоичного файла: ";
                cin >> secondFile;
                textFile.open(secondFile, ios::binary);
                if (textFile.is_open())
                {
                    binaryFile.open(firstFile);
                    readTextFromBin(textFile, binaryFile);
                    if (textFile.bad() || binaryFile.bad())
                    {
                        wcout << "Возникла ошибка записи\n";
                        return 1;
                    }
                    else
                    {
                        wcout << "Запись из двоичного файла в текстовый произошла успешно\n";
                        textFile.close();
                        binaryFile.close();
                    }
                }
                else
                {
                    wcout << "Двоичный файл не существует\n";
                }
                break;
            }
            case 3:
            {
                wcout << "Введите название двоичного файла: ";
                cin >> firstFile;
                textFile.open(firstFile, ios::binary);
                if (textFile.is_open())
                {
                    printBinFile(textFile);
                    if (textFile.bad())
                    {
                        wcout << "Возникла ошибка чтения\n";
                        return 1;
                    }
                    else
                    {
                        textFile.close();
                    }
                }
                else
                {
                    wcout << "Двоичный файл не существует\n";
                }
                break;
            }
            case 4:
            {
                wcout << "Введите название двоичного файла: ";
                cin >> firstFile;
                int n;
                wcout << "Введите номер записи: ";
                cin >> n;
                textFile.open(firstFile, ios::binary);
                if (textFile.is_open())
                {
                    vuz x = getRecord(textFile, n);
                    wcout << x.code << " | " << x.name << " | " << x.faculty <<
                         "\n";
                    if (textFile.bad())
                    {
                        wcout << "Возникла ошибка чтения\n";
                        return 1;
                    }
                    else
                    {
                        textFile.close();
                    }
                }
                else
                {
                    wcout << "Двоичный файл не существует\n";
                }
                break;
            }
            case 5:
            {
                wcout << "Введите название двоичного файла: ";
                cin >> firstFile;
                string key;
                wcout << "Введите ключ (номер специальности): ";
                cin >> key;
                file.open(firstFile, ios::binary | ios::in | ios::out);
                if (file.is_open())
                {
                    deleteRecord(file, key, firstFile);
                    if (file.bad())
                    {
                        wcout << "Возникла ошибка чтения\n";
                        return 1;
                    }
                    else
                    {
                        file.close();
                        textFile.open(firstFile, ios::binary);
                        printBinFile(textFile);
                        textFile.close();
                    }
                }
                else
                {
                    wcout << "Двоичный файл не существует\n";
                }
                break;
            }
            case 6:
            {
                wcout << "Введите название текстового файла: ";
                cin >> firstFile;
                wcout << "Введите название двоичного файла: ";
                cin >> secondFile;
                string key;
                wcout << "Введите номер специальности: \n";
                cin >> key;
                textFile.open(secondFile, ios::binary);
                if (textFile.is_open())
                {
                    binaryFile.open(firstFile);
                    getAllRecords(textFile, binaryFile, key);
                    if (textFile.bad() || binaryFile.bad())
                    {
                        wcout << "Возникла ошибка записи\n";
                        return 1;
                    }
                    else
                    {
                        wcout << "Запись из двоичного файла в текстовый произошла успешно\n";
                        textFile.close();
                        binaryFile.close();
                    }
                }
                else
                {
                    wcout << "Двоичный файл не существует\n";
                }
                break;
            }
            case 7:
            {
                wcout << "Введите название двоичного файла: ";
                cin >> firstFile;
                string key, change;
                wcout << "Введите название специальности: ";
                cin.get();
                getline(cin, key);
                wcout << "Введите номер для замены: ";
                cin >> change;
                file.open(firstFile, ios::binary | ios::in | ios::out);
                if (file.is_open())
                {
                    changeRecords(file, key, change);
                    if (file.bad())
                    {
                        wcout << "Возникла ошибка чтения\n";
                        return 1;
                    }
                    else
                    {
                        file.close();
                        textFile.open(firstFile, ios::binary);
                        printBinFile(textFile);
                        textFile.close();
                    }
                }
                else
                {
                    wcout << "Двоичный файл не существует\n";
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
