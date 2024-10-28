#include <iostream>
#include <string>

using namespace std;

// Чисто виртуальная функция - пустая функция, в которой нет реализации
// Класс, в котором есть чисто виртуальная функция, является абстрактным. Экземпляры абстрактного класса компилятор не позволит создать. Это связано с тем, что в лсучае обращения методу такого экземпляра, компилятор не будет знать, что ему делать дальше

// В абстрактных классах могут быть реализованы не только чисто виртуальные методы

// Абстрактный класс
class Weapon
{
    public:
        //  Чисто виртуальная функция
        virtual void Shoot() = 0;
        void Foo()
        {
            cout << "Я - хардкод функция, которая реализована в абстрактном классе" << endl;
            cout << "Я нужна, чтобы показать возможность реализации не только чисто виртуальных функций внутри абстрактного класса" << endl;
        }
};

// Классы Gun, SniperRifle и Knife являются наследниками абстрактного класса Weapon. Классы SubMachineGun, LightMachineGun - наследники класса Gun
class Gun : public Weapon
{
    public:
        void Shoot() override
        {
            cout << "Shoot x1" << endl;
        }
};

class SubMachineGun : public Gun
{
    public:
        void Shoot() override
        {
            cout << "Shoot x5" << endl;
        }
};

class LightMachineGun : public Gun
{
    public:
        void Shoot() override
        {
            cout << "Shoot x100" << endl;
        }
};

class SniperRifle : public Weapon
{
    public:
        void Shoot() override
        {
            cout << "Дал 140, добивайте" << endl;
        }
};

class Knife : public Weapon
{
    public:
        void Shoot() override
        {
            cout << "Обожаю оружейную гонку" << endl;
        }
};

class Player
{
    public:
    void Shoot(Weapon *weapon)
    {
        weapon -> Shoot();
    }

};

int main(){

    setlocale(LC_ALL, "ru");

    Gun gun;
    SubMachineGun smg;
    LightMachineGun lmg;
    SniperRifle Kraber;
    Knife knife;
    Player Predator;

    // Игрок может взаимодействовать с любым видом снаряжения
    // Это также позволяет создавать множество видов снаряжения без необходимости определять метод для каждого из них внутри класса Player
    Predator.Shoot(&knife);

    // Функция Foo() может быть вызвана у любого экземпляра класса наследника
    // Однако это касается только прямых наследников - экземпляры класса Gun, SubMachineGun и LightMachineGun не могу использовать данную функцию
    Kraber.Foo();
    knife.Foo();
    

    return 0;
}