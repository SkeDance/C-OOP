#include <iostream>
#include <string>

using namespace std;

// Вызов виртуального метода базового класса в классе наследнике

class Msg
{
    public:
        Msg(string msg)
        {
            this -> msg = msg;
        }

        virtual string GetMsg()
        {
            return msg;
        }
    
    private:
        string msg;
};

class BraketsMsg : public Msg
{
    public:
    BraketsMsg(string msg):Msg(msg)
    {
    }
    string GetMsg() override
    { 
        return "[" + ::Msg::GetMsg() + "]";
    }
};

class Printer
{
    public:
        // Указатель на класс Msg
        void Print(Msg *msg)
        {
            cout << msg ->GetMsg() << endl;
        }
};


int main()
{
    setlocale(LC_ALL, "ru");

    BraketsMsg a("Привет");
    Printer p;
    p.Print(&a);



    return 0;
}