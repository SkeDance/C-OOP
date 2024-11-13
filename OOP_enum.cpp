#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// enum
// enum - перечисляемый тип, который служит для объявления символических имён, представляющих целочисленные константы



class PC
{
    public:

    enum PCState
    {
        OFF,
        ON,
        SLEEP
    };

    void SetState(PCState State)
    {
        this -> State = State;
    }
    PCState getPCState()
    {
        return State;
    }

    private:
        PCState State;

} ;

// enum со значениями, которые необходимы нам для функционала
enum Speed
{
    MIN = 150,
    RECOMEND= 600,
    MAX = 800
};


int main()
{
    setlocale(LC_ALL, "ru");

    PC pc;
    
    // Проверка enum'a с заданными параметрами 
    Speed sp = Speed::MAX;
    cout << sp << endl;


    pc.SetState(PC::PCState::ON);
    // if (pc.getPCState() == PCState::ON)
    // {
    //     cout << "PC is ON" << endl;
    // }

    // Пример использования enum'a для функции switch
    switch(pc.getPCState())
    {
        case PC::PCState::OFF:
            cout << " PC is OFF" << endl;
            break;
        case PC::PCState::ON:
            cout << "PC is ON" << endl;
            break;
        case PC::PCState::SLEEP:
            cout << "PC is SLEEP" << endl;
            break;
    }



    return 0;
}