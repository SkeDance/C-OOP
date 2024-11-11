#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Использование нескольких блоков catch
// Несколько блоков catch позволяют обнаркживать разичные ошибки при выполнении кода программы

// Разобраться с конструктором exception и тем, как работает throw
// Складывается ощущение, что функционал данных методов изменили, так как throw теперь не принимает строки

void Foo(int value)
{
    if(value < 0)
    {
        throw exception("Число меньше 0");
        throw "Число меньше 0";
    }
    cout << "Переменная = " << value << endl;
}

int main()
{
    setlocale(LC_ALL, "ru");

    try
    {
        {
            Foo(-55);
        }
    }
    catch(exception &ex)
    {
        cout << "Ошибка" << ex.what() << endl;
    }
    catch(const char &ex)
    {
        cout << "Ошибочная строка" << ex << endl;
    }
    
    return 0;
}