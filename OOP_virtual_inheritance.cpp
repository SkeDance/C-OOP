#include <iostream>
#include <string>

using namespace std;

// Виртуальное наследование. Ромбовидное наследование

class Component
{
    public:
        Component(string companyName)
        {
            cout << "Конструктор Component" << endl;
            this -> companyName = companyName;
        }
    string companyName;
};

class GPU : public Component
{
    public:
        GPU(string companyName) : Component(companyName)
        {
            cout << "конструктор GPU" << endl;
        }
};

class Memory : public Component
{
    public:
        Memory(string companyName) : Component(companyName)
        {
            cout << "конструктор Memory" << endl;
        }
};

class GraphicCard : public GPU, public Memory
{
    public:
        GraphicCard(string GPUComapnyName, string MemoryCompanyName) : GPU(GPUComapnyName), Memory(MemoryCompanyName)
        {
            cout << "конструктор GraphicCard " << endl;
        }
};

// Ромбовидное наследование
// Стоит обратить внимание на вывод терминала
// В первом случае у нас дважды создается экземпляр класса Component
// Во втором случае экземпляр класса Character создается один раз 
// Оба варианта верные
// Второй вариант - пример ромбовидного наследования 
// Для избежания дублирования экземпляров класса было добавлено ключевое слово virtual при наслдедовании
// Ромбовидное наследование не всегда обходимо

class Character
{
    public:
        int HP;
        Character()
        {
            cout << "Character" << endl;
        }
};

// ключевое слово virtual при наследовании
class Orc : public virtual Character
{
    public:
        Orc()
        {
            cout << "Orc" << endl;
        }
};

// ключевое слово virtual при наследовании
class Warrior : public virtual Character
{
    public:
        Warrior()
        {
            cout << "Warrior" << endl;
        }
};

class OrcWarrior : public Orc, public Warrior
{
    public:
        OrcWarrior()
        {
        cout << "Orc Warrior" << endl;
        }
};

int main()
{

    GraphicCard RTX("amd", "hynix");
    cout << endl;

    // Ромбовидное наследование
    OrcWarrior OW;


    return 0;
}