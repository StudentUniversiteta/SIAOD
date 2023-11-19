#include "File.h"
int main() {
    system("chcp 65001");
    string filename;
    ifstream fin;
    ofstream fout;
    int choice;
    while (true) {
        cout << "\nМеню.\n";
        cout << "1. Вывести все числа из файла\n";
        cout << "2. Добавление числа в конец файла\n";
        cout << "3. Найти число в файле по его порядковому номеру\n";
        cout << "4. Определить количество чисел в файле\n";
        cout << "5. Создать новый файл из значений исходного, поделив каждое число на число, равное количеству строк в файле.\n";
        cout << "6. Завершить выполнение программы\n";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Введите название файла: ";
                cin >> filename;
                fin.open(filename);
                if (fin.is_open()) {
                    printNumbers(fin);
                    if (!fin) {
                        cout << "Возникла ошибка при работе с файлом...";
                    }
                    fin.close();
                }
                else
                    cout << "Файл не существует";
                break;
            case 2:
                cout << "Введите название файла: ";
                cin >> filename;
                fout.open(filename, ios::app);
                double x;
                cout << "Введите число для добавления в файл: ";
                cin >> x;
                appendFile(fout, x);
                if (!fout) {
                    cout << "Возникла ошибка при работе с файлом...";
                }
                else {
                    cout << "Добавление числа в файл произошло успешно";
                }
                fout.close();
                break;
            case 3:
                cout << "Введите название файла: ";
                cin >> filename;
                fin.open(filename);
                if (fin.is_open()) {
                    int n;
                    cout << "Введите порядковый номер числа: ";
                    cin >> n;
                    cout << "Надйенное число: " << readNumber(fin, n);
                    if (!fin) {
                        cout << "Возникла ошибка при работе с файлом...";
                    }
                    fin.close();
                }
                else
                    cout << "Файл не существует";
                break;
            case 4:
                cout << "Введите название файла: ";
                cin >> filename;
                fin.open(filename);
                if (fin.is_open()) {
                    cout << "Количество чисел в файле: " << countNumbers(fin);
                    if (!fin) {
                        cout << "Возникла ошибка при работе с файлом...";
                    }
                    fin.close();
                }
                else
                    cout << "Файл не существует";
                break;
            case 5: {
                cout << "Введите название файла: ";
                cin >> filename;
                string newfilename;
                cout << "Введите название нового файла: ";
                cin >> newfilename;
                fin.open(filename);
                int lines;
                if (fin.is_open()) {
                    lines = countLines(fin);
                    if (!fin) {
                        cout << "Возникла ошибка при работе с первым файлом...";
                        break;
                    }
                    fin.close();
                    fin.open(filename);
                    fout.open(newfilename);
                    makeNewFile(fin, fout, lines);
                    if (!fin || !fout) {
                        cout << "Возникла ошибка при создании второго файла...";
                    }
                    fin.close();
                    fout.close();
                    fin.open(newfilename);
                    printNumbers(fin);
                    if (!fin) {
                        cout << "Возникла ошибка при работе с новым файлом...";
                        break;
                    }
                    fin.close();
                }
                else
                    cout << "Файл не существует";
                break;
            }
            default:
                return 0;
        }
    }
}