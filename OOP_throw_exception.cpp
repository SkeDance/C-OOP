#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Обработка исключений
// Throw

// Необходимость бросить исключение возникает в случае, когда логика программы обнаруживает несоответсвие каких-либо данных тому состоянию, в котором они должны быть

// Для примера применения функции throw, рассмотрим функцию, в которую мы передаем значения с клавиатуры
// В логике данной функции описано, что мы принимаем значения больше 0, а в случае если принимаемое значение 0 или меньше, то используем throw 
void Foo(int data)
{
    if (data < 0)
    {
        // Throw позволяет передать значение в блок catch
        throw data;
    }
    cout << "Переменная = " << data << endl;
}

int main()
{
    setlocale(LC_ALL, "ru");
    // Ввод данных с клавиатуры
    int data;
    cout << "Enter data: " << endl;
    cin >> data;

    // Обработка исключений при помощи try catch
    try 
    {
    Foo(data);
    }

    // Если мы используем throw для строки, то в блоке catch должны использовать указатель на char
    // catch (const char *ex)
    catch (const int ex)
    {
        cout << "Catched " << ex << endl;
    }

    return 0;
}