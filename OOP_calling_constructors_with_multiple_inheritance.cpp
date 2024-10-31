#include <iostream>
#include <string>

using namespace std;

// Вызов конструкторов при множественном наследованиии
// Наследовании в ООП необходимо для возможности передавать методы из одних базовых классов в другие дочерние классы

class Car
{
    public:
        Car()
        {
            cout << "Вызван конструктор Car" << endl;
        }
        string str1 = "Rayan Gosling";
        void Drive()
        {
            cout << "driving" << endl;
        }


};

class Airplane
{
    public:
        Airplane()
        {
            cout << "Вызван конструктор Airplane" << endl;
        }
        string str2 = "Twins";
        void Fly()
        {
            cout << "flying" << endl;
        }


};

// класс FlyingCar является наследником классов Car и Airplane
// Порядок вызова конструкторов при множественном наследовании зависит от порядка наследования
class FlyingCar : public Car , public Airplane
{
    public:
        FlyingCar()
            {
                cout << "Вызван конструктор FlyingCar" << endl;
            }
};

int main()
{   
    setlocale(LC_ALL, "ru");

    FlyingCar FC;



    return 0;
}