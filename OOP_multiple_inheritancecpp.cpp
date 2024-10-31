#include <iostream>
#include <string>

using namespace std;

// Множественное наследование - наследование от нескольких клаасов. В этом случае класс наследник получает все методы базовых классов

class Car
{
    public:
        string str1 = "Rayan Gosling";
        void Drive()
        {
            cout << "driving" << endl;
        }


};

class Airplane
{
    public:
        string str2 = "Twins";
        void Fly()
        {
            cout << "flying" << endl;
        }


};

// класс FlyingCar является наследником классов Car и Airplane
class FlyingCar : public Car , public Airplane
{

};

int main()
{   
    setlocale(LC_ALL, "ru");

    Car car;
    car.Drive();

    Airplane fly;
    fly.Fly();

    // Так как класс FlyingCar наследует методы от двух классов, то каждым из этиъ методов он может воспользоваться
    // Наследование от нескольких классов работает не только с методами, но и с полями
    FlyingCar FC;
    FC.Drive();
    FC.Fly();
    // Множественное наследование полей
    cout << FC.str2 << endl << FC.str1 << endl;

    // Указатель на базовый класс может хранить ссылку любого своего класса наследника
    Car *ptrcar = &FC;
    Airplane *ptrair = &FC;
    ptrair->Fly();
    ptrair->str2;
    ptrcar->Drive();
    ptrcar->str1;    


    return 0;
}