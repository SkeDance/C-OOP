#include <iostream>
#include <string>
using namespace std;

class Human {
    public:
        int age; //field
        int weight; //field
        string name; //field

        void Print(){//method or func for class
            cout << "Имя " << name << "\nBec " << weight << "\nВозраст " << age << endl << endl;
        }
};

class Point1 {
    public://access modification 
        void Print(){
            cout << "z = " << z << "\nx = " << x << "\ny = " << y << endl << endl;
            PrintY();
        }
        int x;
    private:
        int y;
        int z;

        void PrintY(){
            cout << "y = " << y << endl;
            cout << "PrintY()" << endl << endl;
            //сокрытие части функицонала - инкапсуляция.
            //Пусть PrintY() и приватный метод, но обычный метод print имеет к ней доступ, так как они оба являются методами одного класса.
            //Поэтому мы можем вызвать метод PrintY() внутри метода Print(), а затем внури тела главной части программы обратиться к публичному методу Print();
        }
};

//Применение геттеров и сеттеров
class Point2 {


    private:
        int x;
        int y;

    public:
        int GetX(){
            return x;
        }
        void SetX(int valueX){
            x = valueX;
        }

        int GetY(){
            return y;
        }
        void SetY(int valueY){
            y = valueY;
        }

        void Print(){
            cout << "x = " << x << "\ny = " << y << endl << endl;
        }
};

//Пример скрытого функционала
//Добавление приватного метода, на который нельзя воздействовать из вне, также является инкапсуляцией.
class CoffeeGrinder{
    private:
        bool CheckVoltage(){//приватный метод
            return false;
        }
    
    public:
        void Start(){//публичный метод
            bool VoltageIsNormal = CheckVoltage();//вызов приватного метода и его дальнейшее использование
            if(VoltageIsNormal == true){
                cout << "Grinding is on" << endl;
            }
            else{
                cout << "Beep Beep" << endl << endl;
            }
        }

};

//Пример пименения конструкторов класса
//Конструктор класса - это функция, которая не имеет типа возврщаемых данных
//Конструктор класса нельзя вызвать вручную -  он вызывается сам при создании объекта класса
//Конструктор есть у каждого класса, даже в случае, если не задан в явном виде. Такой конструктор называется конструктором по умолчанию
//Ограничения количества конструкторов нет
class Point3{
    private:
        int x;
        int y;

    public:

        //Конструктор по умолчанию
        Point3(){
            x = 0;
            y = 0;
        }

        //Конструктор, который принимает значения переменных
        Point3(int valueX, int valueY){
            x = valueX;
            y = valueY;
        }

        Point3(int valueX, bool bolean){
            x = valueX;
            if(bolean == true){
                y = 1;
            }
            else{
                y = -1;
            }
        }
        

        void Print(){
            cout << "x = " << x << "\ny = " << y << endl << endl;
        }

};

//Применение деструкторов
//Деструктор может быть только один для каждого класса
//Деструктор может быть не объявлен явно, тогда будет использован деструктор по умолчанию
//Деструктор не может принимать параметры
class Destructor{
    private:
        int* data;//указатель на массив
    public:
        Destructor(int size){
            data = new int[size];//динамическое выделение памяти
            for( int i = 0; i < size; i++){
                data[i] = i;
            }
            cout << "Объект " << data << "Вызван конструктор" << endl;
        }

        ~Destructor(){
            delete [] data;//освобождение памяти из-под динамического массива
            cout << "Объект " << data << "Вызван деструктор" << endl;
        }
};
void Foo(){
    cout << "Foo beginning" << endl;
    Destructor Z(1);
    cout << "Foo ending" << endl << endl;
}

//Применение ключевого слова this
//В функции main() создается объект класса
//При это переменная x инициализируется с применением this, а y нет 
//По итогу х принимает нужное значение, а у остается нулем
class Point4{
    private:
        int x;
        int y;
    public:
        int GetX(){
            return x;
        }
        void SetX(int x){
            this -> x = x;
        }
         int GetY(){
            return y;
        }
        void SetY(int y){
            this -> y = y;
        }
        void Print(){
             cout << "x = " << x << "\ny = " << y << endl << endl;
        }
};
int main() {
 
    setlocale(LC_ALL, "ru");

    Foo();//функция для вызова класса с деструктором

    Human firstHuman; //object or example
    firstHuman.age = 30;
    firstHuman.name = "Ivanov Ivan Ivanovich";
    firstHuman.weight = 100;
    firstHuman.Print();//method


    Human secondHuman;
    secondHuman.age = 19;
    secondHuman.name = "Noname";
    secondHuman.weight = 60;
    cout << secondHuman.age << endl;
    cout << secondHuman.name << endl;
    cout << secondHuman.weight << endl << endl;

    Point1 a;
    a.x = 1;
    a.Print();

    //Пример инкапсуляции -  взаимодействие с приватными полями при помощи сеттеров и геттеров
    Point2 b;
    b.SetX(5); //присваиваем приватной переменной Х значение 5 при помощи сеттера
    int resultX = b.GetX();//выводим значение Х при помощи геттера
    cout << resultX << endl;//проверяем, правильное ли значение присвоили
    b.SetY(11);
    int resultY = b.GetY();
    cout << resultY << endl << endl;

    //Пример скрытого функционала
    CoffeeGrinder NIISK;
    NIISK.Start();//вызов публичного метода

    //Применение конструктора класса по умолчанию
    Point3 c;
    c.Print();
    
    //Применение конструктора класса, полностью определенного нами
    Point3 d(5, 44);
    d.Print();

    //Применение конструктора с переменной boolean
    Point3 e(22, true);
    e.Print();

    //Использование класса с деструктором
    Destructor X(2);
    Destructor C(3);

    //Пример применения ключевого слова this
    Point4 v;
    v.SetX(7);
    v.SetY(1);
    v.Print();
    

    return 0;
    }      