#include "HashFile.h"
// * РАБОТА С ХЕШ-ТАБЛИЦЕЙ *

//int main()
//{
//    system("chcp 65001");
//    HashTable table;
//    int choice;
//    int position = 0;
//    string key;
//    while (true)
//    {
//        cout << "Меню. \n";
//        cout << "1. Добавить элемент в таблицу\n";
//        cout << "2. Поиск элемента в таблице\n";
//        cout << "3. Удаление элемента из таблицы\n";
//        cout << "4. Вывести хэш-таблицу\n";
//        cout << "5. Завершить выполнение программы\n";
//        cin >> choice;
//        switch (choice)
//        {
//            case 1:
//            {
//                cout << "Введите ключ записи: ";
//                cin.get();
//                getline(cin, key);
//                element elem(key, position++);
//                addElement(table, elem);
//                printTable(table);
//                break;
//            }
//            case 2:
//            {
//                cout << "Введите ключ записи: ";
//                cin.get();
//                getline(cin, key);
//                int pos = findElement(table, key);
//                cout << "Позиция элемента: " << pos << "\n";
//                break;
//            }
//            case 3:
//            {
//                cout << "Введите ключ записи: ";
//                cin.get();
//                getline(cin, key);
//                deleteElement(table, key);
//                printTable(table);
//                break;
//            }
//            case 4: {
//                printTable(table);
//                break;
//            }
//            default:
//            {
//                return 0;
//            }
//        }
//    }
//}

// * РАБОТА С ДВОИЧНЫМ ФАЙЛОМ *
int main()
{
    system("chcp 65001");
    HashTable table;
    int choice;
    ifstream readFile;
    ofstream writeFile;
    string firstFile, secondFile;
    fstream file;
    while (true)
    {
        cout << "Меню. \n";
        cout << "0. Преобразование текстового файла в двоичный\n";
        cout << "1. Перевод двоичного файла в хэш-таблицу\n";
        cout << "2. Поиск записи\n";
        cout << "3. Удаление записи\n";
        cout << "4. Вывести хэш-таблицу\n";
        cout << "5. Вывести бинарный файл\n";
        cout << "6. Завершить выполнение программы\n";
        cin >> choice;
        switch (choice)
        {
            case 0:
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
                    if (readFile.bad() || writeFile.bad())
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
            case 1:
            {
                cout << "Введите название двоичного файла: ";
                cin >> firstFile;
                readFile.open(firstFile, ios::binary);
                if (readFile.is_open()) {
                    createHashTable(table, readFile);
                    if (readFile.bad()) {
                        cout << "Возникла ошибка создания хэш-таблицы\n";
                        return 1;
                    }
                    else {
                        cout << "Создание хэш-таблицы произошло успешно\n";
                        readFile.close();
                    }
                }
                else {
                    cout << "Двоичного файла не существует\n";
                }
                break;
            }
            case 2:
            {
                cout << "Введите название двоичного файла: ";
                cin >> firstFile;
                readFile.open(firstFile, ios::binary);
                if (readFile.is_open())
                {
                    string key;
                    //cout << "Введите название вуза: ";
                    cout << "Введите номер автомобиля: "<<endl;
                    cin.get();
                    getline(cin, key);
                    auto start = chrono::high_resolution_clock::now();
                    car record = findRecord(table, readFile, key);
                    auto end = chrono::high_resolution_clock::now();
                    cout << "Время поиска: " <<
                         chrono::duration_cast<chrono::nanoseconds>(end - start).count() / 1e6 << " мс\n";
                    if (readFile.bad())
                    {
                        cout << "Возникла ошибка чтения\n";
                        return 1;
                    }
                    else
                    {
                        if (record.licensePlate != "")
                            cout << record.licensePlate << " | " << record.brand << " | " <<
                                 record.owner << "\n";
                        else
                            cout << "Запись не найдена\n";
                        readFile.close();
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
                file.open(firstFile, ios::in | ios::out | ios::binary);
                if (file.is_open())
                {
                    string key;
                    cout << "Введите номер автомобиля: ";
                    cin.get();
                    getline(cin, key);
                    deleteRecord(table, file, key, firstFile);
                    if (readFile.bad())
                    {
                        cout << "Возникла ошибка удаления\n";
                        return 1;
                    }
                    else
                    {
                        cout << "Запись успешно удалена!\n";
                        file.close();
                    }
                }
                else
                {
                    cout << "Двоичный файл не существует\n";
                }
                break;
            }
            case 4: {
                printTable(table);
                break;
            }
            case 5: {
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
            default:
            {
                return 0;
            }
        }
    }
}