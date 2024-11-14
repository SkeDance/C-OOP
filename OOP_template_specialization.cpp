#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Специализация шаблонов класса
// Механика шаблона такова, что каждый раз при создании шаблонного класса с каким-то конкретным типом данных, 
// компилятор будет использовать тот класс, который специализирован под определенный тип данных
// В данном примере написана специализация для переменной типа string, то есть при создании объекта класса Printer<string> p, будет вызван:
// template<>
// class Printer<string>

template<typename T>
class Printer
{
    public:
        void Print(T value)
        {
            cout << value << endl;
        }
};

// Создания специализации шаблонов
// Используем ключевое слово template, а затем указываем класс, для которого пишем специализацию
// В <> класса, для которого пишем специализацию, указываем тип данных, поведение с которым специализируется
template<>
class Printer<string>
{
    public:
        void Print(string value)
        {
            cout << "__" << value << "__" << endl;
        }
};

int main()
{
    setlocale(LC_ALL, "ru");
    // Если в <> указать int, то сработает другой метод Print()
    Printer<string> p;
    p.Print("Hello world");


    return 0;
}