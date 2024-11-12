#include <string>
#include <iostream>
#include <fstream>

using namespace std;

// Создание собственного класса exception
// Необходим для того, чтобы при использовании класса или метода другим пользователем, он мог получить больше данных о возникшей ошибке

// Вместо базового класса exception для MyException используется класс runtime_error. Смотри прошлый урок 
class MyException : public runtime_error
{
    public:
        MyException(char *msg, int dataState):runtime_error(msg)
        {
            this->dataState = dataState;
        }

        int getDataState(){
            return dataState;
        }

    private:
        int dataState;
};

void Foo(int value)
{
    if (value < 0)
    {
        throw runtime_error("ERROR");
    }

    if (value == 1)
    {
        throw MyException("Equal 1", false);
    }
}

int main()
{
    setlocale(LC_ALL, "ru");

    try
    {
        Foo(1);
    }
    // Для компилятора первый catch равноценен второму catch 
    // Поэтому, в начале необходимо указывать наиболее конкретный catch, то есть, в данном примере MyException
    // Если их поменять местами, то сработает catch для обычного класса exception
    catch(MyException &ex)
    {   
        cout << "Data state is " << ex.getDataState() << endl;
        cout << "Catched " << ex.what() << endl;
    }
    catch(exception &ex)
    {
        cout << "Catched " << ex.what() << endl;
    }
   



    return 0;
}