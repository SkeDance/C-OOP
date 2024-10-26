#include <iostream>
#include <string>

using namespace std;

// Вызов конструкторов при наследовании
// Класс С включает класса В, а класс В включает класс А
class A
{

    public:
    //  Конструктор класса
        A()
        {
            cout << "Constructor A" << endl;
        }
};

class B : public A
{
    public:
    //  Конструктор класса
        B()
        {
            cout << "Constructor B" << endl;
        }



};

class C: public B{
    public:
    //  Конструктор класса
        C()
        {
            cout << "Constructor C" << endl;
        }
};

int main(){


setlocale(LC_ALL, "ru");
// При создании класса С сначала вызывается конструктор класса А, заетем конструктор класса В, и только после этого конструктор класса С
// Это происходит из-за того, что класс С включает в себя класс В, который включает в себя класс А, то есть объект класса С не может существовать без объекта класса В, а класс В не может существовать без класса А
    C c;


    return 0;
}