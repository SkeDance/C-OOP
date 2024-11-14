#include <iostream>
#include <string>

using namespace std;

// Структуры, struct
// Структура - практически идентична классу
// По умолчанию поля и методы класса являются private
// У структуры все поля и методы являются public
// Наследование происходит по тому же принципу: 
// у классов по умолчанию идёт наследование private,
// а у структур - public

class MyClass
{
    // Не указана секция для наглядности, что по умолчанию применятеся private
    int a = 10;
    int b = 40;
    void Print()
    {
        cout << a << endl;
    }
};

// Наследник класса MyClass
// Обращаем внимание, что не указан модификатор наследования
class MyClass2 : MyClass
{
   
};

struct MyStruct
{   
    // Конструктор по умолчанию
    MyStruct()
    {

    }
    // Конструктор 
    MyStruct(int a)
    {
        cout << "Struct1" << endl;
        this -> a = a;
    }
    // Деструктор
    ~MyStruct()
    {

    }
    private:
    // Переменная
    int a = 22;
    // Метод
    public:
    int b = 50;
    void Print()
    {
        cout << a << endl;
    }
};

struct MyStruct2 : MyStruct
{
    MyStruct2()
    {
        cout << "Struct2" << endl;
    }
};

int main()
{   
    setlocale(LC_ALL, "ru");

    MyClass c;
    MyStruct s(44);

    // Добавили поле int a = 22 в private сецию структуры, после чего она стала недоступна
    // cout << s.a << endl;
    s.Print();

    // Проверка того, как работает наследование
    MyClass2 c2;
    // Так как при создании класса наследника не был указан модификатор наследования,
    // то все поля получили модификатор private
    // Поэтому мы не можем обратиться к полям класса private
    // c2.a;
    MyStruct2 s2;
    cout << s2.b << endl;



    return 0;
}