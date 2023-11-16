#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

const string FILE_NAME = "NumbersB.txt";

void displayMenu() {
    cout << "1. Вывести содержимое файла" << endl;
    cout << "2. Добавить новую запись" << endl;
    cout << "3. Получить число по порядковому номеру" << endl;
    cout << "4. Получить количество чисел в файле" << endl;
    cout << "5. Выход" << endl;
    cout << "6. Сделать нужную хуйню" << endl;
}

void readFile(const string& filename, vector<int>& numbers) {
    ifstream file(filename);
    int number;

    if (file.is_open()) {
        while (file >> number) {
            numbers.push_back(number);
        }

        file.close();
    } else {
        cout << "Не удалось открыть файл" << endl;
    }
}

void writeFile(const string& filename, const vector<int>& numbers) {
    ofstream file(filename);

    if (file.is_open()) {
        for (int number : numbers) {
            file << number << " ";
        }

        file.close();
    } else {
        cout << "Не удалось открыть файл" << endl;
    }
}

void appendToFile(const string& filename, int number) {
    ofstream file(filename, ios::app);

    if (file.is_open()) {
        file << number << " ";
        file.close();
    } else {
        cout << "Не удалось открыть файл" << endl;
    }
}

int getNumberByIndex(const vector<int>& numbers, int index, int& result) {
    if (index >= 0 && index < numbers.size()) {
        result = numbers[index];
        return 0; // Код успешного выполнения
    } else {
        return 1; // Код завершения, указанный номер превышает количество чисел в файле
    }
}

int getNumberOfNumbers(const vector<int>& numbers) {
    return numbers.size();
}
void createNewFile(const string& FILE_NAME, const string& destinationFilename) {
    vector<int> numbers;
    readFile(FILE_NAME, numbers);

    if (numbers.empty()) {
        cout << "Файл пуст" << endl;
        return;
    }

    int minNumber = *min_element(numbers.begin(), numbers.end()); // Находим минимальное число

    ofstream file(destinationFilename);
    if (file.is_open()) {
        for (int number : numbers) {
            file << number / minNumber << " "; // Записываем результаты деления в новый файл
        }
        file.close();
        cout << "Новый файл успешно создан" << endl;
    } else {
        cout << "Не удалось открыть файл" << endl;
    }
}

int main() {
    system("chcp 65001");
    string FILE_NAME = "C:\\Users\\artez\\Desktop\\NumbersB.txt";
    vector<int> numbers;
    readFile(FILE_NAME, numbers);

    int choice;
    int number;
    int index;
    int result;

    while (true) {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Содержимое файла: ";
                for (int number : numbers) {
                    cout << number << " ";
                }
                cout << endl;
                break;
            case 2:
                cout << "Введите новое число: ";
                cin >> number;
                numbers.push_back(number);
                writeFile(FILE_NAME, numbers);
                cout << "Запись успешно добавлена в файл" << endl;
                break;
            case 3:
                cout << "Введите порядковый номер числа: ";
                cin >> index;
                if (getNumberByIndex(numbers, index, result) == 0) {
                    cout << "Число с порядковым номером " << index << ": " << result << endl;
                } else {
                    cout << "Указанный номер превышает количество чисел в файле" << endl;
                }
                break;
            case 4:
                cout << "Количество чисел в файле: " << getNumberOfNumbers(numbers) << endl;
                break;
            case 5:
                cout << "Программа завершена" << endl;
                return 0;
            case 6:
                cout<<"Измененный файл создан"<<endl;
                createNewFile(FILE_NAME, "C:\\Users\\artez\\Desktop\\newNumbersB.txt");
                break;
            default:
                cout << "Некорректный ввод, попробуйте снова" << endl;
                break;

        }
    }

    return 0;
}