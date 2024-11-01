#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Сохранение данных в файл
// Работа с чтением и записью данных осуществляется при помощи библиотеки ofstream
// В библиотеки, кторая позволяет нам работать с файлами, есть три основых класса
// 1)fstream - универсальный класс, который хранит в себе функционал по записи файла, так и по чтению данных из файла
// 2)ifstream - отвечает только за чтение данных из файла - input file stream
// 3)ofstream - отвечает только за запись данных в файл - output file stream 

int main()
{
    setlocale(LC_ALL, "ru");

    // Создаем объект класса
    ofstream fout;

    string path = "C:\\Users\\alejn\\Desktop\\myFile.txt";
    // Используем метод для экземпляра класса
    // Открываем файл
    // fout.open(path, ofstream::app); - если мы хотим добавить новую информацию в файл и сохранить старую

    fout.open(path);

    if (!fout.is_open())
    {
        cout << "Error" << endl;
    }
    else
    {   cout << "Enter number" << endl;
        int number;
        cin >> number;
        // Вывод в терминал
        cout << "Done" << endl;

        // Запись в документ
        fout << "Text to myFile.txt";
        // Запись в документ от пользователя
        fout << endl << number;
    }

    // Закрываем файл для предотвращения ошибок 
    fout.close();

    return 0;
}