#include <iostream>
#include <string>

using namespace std;

// Интерфейсы в ООП
// Интерфейс в программировании это те публичные методы, с помощью которых мы можем взаимодействовать с какой-то сущностью
// Любой объект, который реализует интерфейс велосипеда, может использоваться другим классом, который умел взаимодействоватьс велосипедом
// В С++ нет ключевого слова interface
// Интерфейс в С++ это абстрактный класс, в котором все методы чисто виртуальные
// Один объект может наследовать несколько интерфейсов

// Интерфейс
class IBicycle
{
    public:
    void virtual TwistTheWheel() = 0;
    void virtual Ride() = 0;

};

// Реализация интерфейса 1
class SimpleBicycle : public IBicycle
{
    public:
        void TwistTheWheel() override
        {
            cout << "wheel of simple bicycle" << endl;
        }

        void Ride() override
        {
            cout << "riding on simple bicycle" << endl;
        }

};

// Реализация интерфейса 2
class SportBicycle : public IBicycle
{
    public:
        void TwistTheWheel() override
        {
            cout << "sport wheel" << endl;
        }
        void Ride() override
        {
            cout << "sport riding" << endl;
        }
};

class Human
{
    public:
        void RideOn(IBicycle &bicycle)
        {
            cout << "Twist the wheel" << endl;
            bicycle.TwistTheWheel();
            cout << endl << "Riding on" << endl;
            bicycle.Ride();

        }
};

int main()
{
    setlocale(LC_ALL, "ru");
    Human h;
    SimpleBicycle SB;
    SportBicycle SpB;

    // В метод RideOn() можно передать ссылки как на объект класса SimpleBicycle, так и на SportBicycle
    // При этом человек свободно пользуется что тем, что другим велосипедом, так как у него есть метод RideOn()
    h.RideOn(SB);
    cout << endl << endl;
    h.RideOn(SpB);



    return 0;
}