#include <iostream>
#include <string>

using namespace std;
//Вынос методов из класса

//Реализацию методов класса выносят из класса с целью упростить чтение кода
//При этом внутри класса остаются определенными сигнатуры класса
//Для быстрого создания класса можно использовать tab
//Для того чтобы быстро вынести метод из класса необходимо написать его сигнатуру внутри класса
//Затем нажать на имя функции, после чего появится лампочка. Благодаря этой лампочке происходит вынос функции из класса
//void test(); для примера
class OOP_outside_methods
{
private:
    /* data */
public:
    OOP_outside_methods(/* args */);
    ~OOP_outside_methods();
    void test();
    void PrintMessage();
};

OOP_outside_methods::OOP_outside_methods(/* args */){

}

OOP_outside_methods::~OOP_outside_methods(){

}

void OOP_outside_methods::PrintMessage(){
    cout << "Hello" << endl;
}

int main(){
    setlocale(LC_ALL, "ru");

    OOP_outside_methods test;
    test.PrintMessage();

}