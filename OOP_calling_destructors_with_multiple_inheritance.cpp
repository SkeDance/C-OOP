#include <iostream>
#include <string>

using namespace std;

// Вызов деструкторов при множественном наследованиии

class Car
{
    public:
        // Конструктор
        Car()
        {
            cout << "Вызван конструктор Car" << endl;
        }

        // Деструктор
        ~Car()
        {
            cout << "Вызван деструктор Car" << endl;
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
        // Конструктор
        Airplane()
        {
            cout << "Вызван конструктор Airplane" << endl;
        }

        // Деструктор
        ~Airplane()
        {
            cout << "Вызван деструктор Airplane" << endl;
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
        // Конструктор
        FlyingCar()
            {
                cout << "Вызван конструктор FlyingCar" << endl;
            }
        // Деструктор
        ~FlyingCar()
            {
                cout << "Вызван деструктор FlyingCar" << endl;
            }
};

int main()
{   
    setlocale(LC_ALL, "ru");

    FlyingCar FC;
    cout << endl;



    return 0;
}