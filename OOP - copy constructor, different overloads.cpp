#include <iostream>
#include <string>

using namespace std;

//Перегрузка оператора равенства 
//По умолчанию оператор равенства не реализован
//Перегрузка оператора сложения
class Point{
    private:
        int x;
        int y;

    public:
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
        //Краткий вариант сравнения полей объектов класса
        //This указывает на объект, который сравнивается
        //other указывает на объект, с которым сравнивают
        return this -> x == other.x && this -> y == other.y;

        //Полный вариант того, что написано выше
        // if(this -> x == other.x && this -> y == other.y){
        //     return true;
        // }
        // else{
        //     return false;
        // }
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
};
//Конструктор копирования
//Перегрузка оператора присваивания
//Перегрузка операторов равентсва и неравентсва
class MyClass{
    private:
        int arraySize;

    public:
        int *data;
    
    MyClass(int size){
        this -> arraySize = size;
        this -> data = new int[size];
        for( int i = 0; i < size; i++){
            data[i] = i;
        }
        cout << "Вызвался конструктор " << this << endl;

    };
//Конструктор копирования по ссылке
    MyClass(const MyClass &other){
        this -> arraySize = other.arraySize;//передаем переменную Size, так как она приватная
        this -> data = new int[other.arraySize];//присваиваем новому массиву размер старого массива
        for(int i = 0; i < other.arraySize; i++){
            this -> data[i] = other.data[i];//в новый массив копируем данные из старого массива
        }
        cout << "Вызвался конструктор копирования " << this << endl;
        
    }
//Метод перегрузки оператора присваивания
//Перегрузка должна быть функцией с возвращаемой переменной, причем разыменованной
    MyClass & operator = (const MyClass &other){
        cout << "Вызвался оператор присваивания " << this << endl;

        this -> arraySize = other.arraySize;

        //Для общих случаев очистки памяти
        if(this -> data != nullptr){
            delete[] this -> data;
        }

        //delete[] this -> data;//работает для освобождения памяти из-под динамического массива

        this -> data = new int[other.arraySize];
        for(int i = 0; i < other.arraySize; i++){
            this -> data[i] = other.data[i];
        }

        return *this;
    }

    ~MyClass(){
        cout << "Вызвался деструктор " << this << endl;
        

        delete[] data;
    };
};

//Передача параметра по значению
//При передаче параметра по значению у нас внутри нашей функции создается новая переменная, того типа, которой мы принимаем парметры 
//И данные из той переменной, которую мы передаем в эту функицию копируются в ноую функцию
//Поэтому изменения новой переменной не повлияют на первоначальную переменную

//По умолчанию выполняется копирование по умолчанию
void Foo(MyClass value){
    cout << "Вызвана функция Foo1 " <<endl;
}

MyClass Foo2(){
    cout << "Вызвана функция Foo2 " <<endl;
    MyClass temp(2);

    return temp;
}

int main(){

    setlocale(LC_ALL, "ru");

    //Foo2();
    MyClass a(10);
    //MyClass b(a);//для конструктора копирования
    MyClass c(2);
    MyClass d(5);
    

    a = c = d;

    //Перегрузка операторов равенства и неравенства
    Point z(5, 1);
    Point x(5, 1);
    Point v(5, 1);
    bool result = z == x;//сравнивание объектов класса z и x для проверки перегрузки оператора равенства
    bool result1 = z != v;//сравнение объектов класса v и x для проверки перегрузки оператора неравенства

    //Перегрузка оператора сложения
    Point zx = z + x;


    // MyClass c(2);//для переполнения оператора равенства
    
    // a = c; - error

    //Foo(a);

    return 0;
} 