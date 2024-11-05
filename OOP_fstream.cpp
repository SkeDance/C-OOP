#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;




int main()
{
    setlocale(LC_ALL, "ru");

    // Путь к файлу
    string path = "C:\\Users\\SkyDance\\Desktop\\myfile.txt";

    // Создаем объект класса
    fstream fs;
    // Открываем файл, который находится по данному пути
    // Параметры:
    //      1) Путь к фалу
    //      2) Режим открытия файла; | - битовое или 
    //          2.1) Чтение
    //          2.2) Запись
    //          2.3) Добавление новой информации в документ без удаления предыдущей
    fs.open(path, fstream::in | fstream::out | fstream::app);
    if (!fs.is_open())
    {
        cout << "error" << endl;
    }
    else
    {
        int value; // Переменная ввода команды 
        string msg; // Перемменная, хранящая сообщение при вводе или сохранении
        cout << "done" << endl;
        cout << "press 1 to write information to file" << endl;
        cout << "press 2 to read all infromation from file" << endl;
        cin >> value;

        // Проверка на правильность введенной команды
        if (value != 1 and value != 2){
            cout << "command does not exist" << endl;
        }
        else if (value == 1)
        {
            cout << "enter data" << endl;
            // Переключение кодировки консоли для записи кириллицы
            SetConsoleCP(1251);
            // Передаем введенные данные в переменную
            cin >> msg;
            // Через объект класса fs обращаемся к переменной и записываем данные из переменной в файл
            fs << msg << "\n";
            // Возврат кодировки консоли в исходное состояние 
            SetConsoleCP(866);
        }
        else if (value == 2)
        {
            cout << "reading information" <<endl;
            // Считываем информацию из файла
            while(!fs.eof())            
            {
                // Чтобы не получить запись одной переменной дважды, необходимо "занулить" предыдущую
                msg = "";
                // Передаем данные из файла в переменную
                fs >> msg;
                // Выводим значения переменной в консоль
                cout << msg << endl;

            }
        }
    }

    fs.close();

    return 0;
}