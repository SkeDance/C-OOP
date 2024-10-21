#include <iostream>
#include <string>

using namespace std;

//Статические методы класса
//Статический метод является единственным для всех экземпляров класса
//Мы можем использовать такой метод без создания экземпляра класса
class Apple{

    public:

        Apple(int weight, string color){
            this -> weight = weight;
            this -> color = color;
            Count++;
            id = Count;
        }

        int GetId(){
            return id;
        }

        static int GetCount(){
            return Count;
        }

        static void ChangeColor(Apple & apple, string color){
            apple.color = color;
        }

    private:
        static int Count;
        int weight;
        string color;
        int id;
};

int Apple::Count = 0;

int main(){
    setlocale(LC_ALL, "ru");

    Apple apple(150, "red");
    //Поле static int Count является публичным. Это означает, что мы можем взаимодействовать с ним из вне
    //Однако, поле static int Count отвечает за функицонал наешго класса. Таким образом работа с этим полем из вне нарушит логику работы класса
    //Пример ниже:
    //Apple::Count = -10;
    //В дальнейшем static int count перемещена в private поля

    //В статических методах можно рабоать только со статическими переменными
    //При работе с нестатическими переменными будет выдана ошибка
    
    

    Apple apple2(100, "green");
    Apple apple3(200, "yellow");

    cout << apple.GetId() << endl;
    cout << apple2.GetId() << endl;
    cout << apple3.GetId() << endl;

    //Получаем количество созданных экземпляров класса при помощи статического метода GetCount
    cout << Apple::GetCount() << endl;

    apple.ChangeColor(apple, "blue");
    Apple::ChangeColor(apple, "black");



    return 0;
}