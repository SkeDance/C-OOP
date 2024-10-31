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
        void Use()
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
        void Use()
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
    // Если в базовых классах реализовать два метода с одинаковым названием, но разным функционалом, то при вызове такого метода классом наследником компилятор выдаст ошибку, указав, что метод не является однозначным
    //FC.Use();
    // Чтобы решить эту проблему, необходимо использовать приведение типов
    ((Car)FC).Use();
    ((Airplane)FC).Use();
 
    return 0;
}