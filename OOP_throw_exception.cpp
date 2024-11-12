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
        // throw data;
        // throw "error"
        throw runtime_error("ERROR");
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
    // catch (const char *ex) - для "error"
    // catch ( const int ex) - для переменной data
    // throw runtime_error("ERROR") или throw logic_error("ERROR"); - в функцию Foo()
    // catch (const exception &ex) - для примера на 42 строке
    catch (const exception &ex)
    {
        cout << "Catched " << ex.what() << endl;
    }

    return 0;
}