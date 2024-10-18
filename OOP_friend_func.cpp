#include <iostream>
#include <string>
using namespace std;
class Test;
//Дружественные функции
//Дружественная функция по отношению к классу это та функция, которая описана вне класса, но имеет доступ к приватным полям класса
class Point{
    private:
        int x;
        int y;

    public:
        void Print(){
            cout << "x = " << x << "\t y = " << y << endl << endl;
        }

        Point(){
            x = 0;
            y = 0;
            cout << this << "Вызван конструктор класса Point" << endl;
        }

        Point (int valueX, int valueY){
            x = valueX;
            y = valueY;
        }
    //Функция перегрузки оператора равенства
    bool operator == (const Point & other){
        return this -> x == other.x && this -> y == other.y;
    }

    //Функция перегрузки оператора неравенства
    bool operator != (const Point & other){
        return !(this -> x == other.x && this -> y == other.y);
    }

    //Функция перегрузки оператора сложения 
    Point operator + (const Point & other){
        Point temp;
        temp.x = this -> x + other.x;
        temp.y = this -> y + other.y;
        return temp;
    }

    //Функция перегрузки оператора вычитания
    Point operator - (const Point & other){
        Point temp;
        temp.x = this -> x - other.x;
        temp.y = this -> y - other.y;
        return temp;
    }

    //Функция перегрузки оператора умножения
    Point operator * (const Point & other){
        Point temp;
        temp.x = this -> x * other.x;
        temp.y = this -> y * other.y;
        return temp;
    }

    //Функция перегрузки оператора деления
    Point operator / (const Point & other){
        Point temp;
        temp.x = this -> x / other.x;
        temp.y = this -> y / other.y;
        return temp;
    }

    //Функция перегрузки префиксного оператора инкремента
    Point & operator ++(){
        this -> x += 1;
        this -> y++;

        return *this;
    }

    //Функция перегрузки постфиксного оператора инкремента
    Point operator ++(int value){
        Point temp(*this);//Создание временного объекта, над которыми мы будем проводить дальнейшие операции
        this -> x++;
        this -> y++;

        return temp;
    }

    //Функция перегрузки префиксного оператора декремента 
    Point & operator --(){
        this -> x--;
        this -> y--;

        return *this;
    }

    //Функция перегрузки постфиксного оператора декремента
    Point operator --(int vlaue){
        Point temp(*this);
        this -> x--;
        this -> y--;

        return temp;
    }

    void SetX(int x){
    }
    int GetX(){
        return x;
    }
    void SetY(int y){
    }
    int GetY(){
        return y;
    }
    //Разрешение функции ChangeX доступ к приватным полям
    friend void ChangeX(Point &value, Test &testvalue);
};

class Test{
    public:
        void Print(){
        cout << "data = " << data << endl;
    }
    private:
        int data = 0; 
    friend void ChangeX(Point &value, Test &testvalue);
    
};

//Дружественная функция
//Внутри этой функции нельзя использовать ключевое слово  this
void ChangeX(Point &value, Test &testvalue){
    value.x = -1;
    testvalue.data = 100;
}
int main(){

    Test test; 

    Point a(5, 12);
    test.Print();
    a.Print();
    ChangeX(a, test);
    test.Print();
    a.Print();
}