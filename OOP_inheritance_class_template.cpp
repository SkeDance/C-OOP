#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Наследование шаблонов


class Point
{
    public:
        Point()
        {
            x = y = z = 0;
        }

        Point(int x, int y, int z)
        {
            this -> x = x;
            this -> y = y;
            this -> z = z;
        }
    private:
        int x;
        int y;
        int z;
};


template<typename T1>
class TypeSize
{
    public:

        TypeSize(T1 value1)
        {
            this -> value1 = value1;
        }
        // Функция, которая отправялет в терминал информацию о том, сколько места в памяти занимает переменная value
        void DataTypeSize()
        {
            cout << sizeof(value1) << endl;
        }
    protected:
        T1 value1;
};

// Наследник класса TypeSize
template<typename T1>
class TypeInfo : public TypeSize<T1>
{
    public:
        TypeInfo(T1 value):TypeSize<T1>(value)
        {

        }
        void ShowTypeName()
        {
            cout << "TypeName: " << typeid(this -> value1).name() <<endl;
        }
    private:
        T1 value;

};

int main()
{
    setlocale(LC_ALL, "ru");

    Point u;

    int a = 5.2;

    TypeInfo<Point> c (u);
    c.DataTypeSize();
    c.ShowTypeName();


    return 0;
}