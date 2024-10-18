#include <iostream>
#include <string>

using namespace std;

//Дружественные классы
//Дружественый метод класса - позволяет с помощью одного метода класса, то есть какой-то одной функции. можем получить доступ к закрытым полям другого класса
//Все же остальныем методы такого класса доступа к закрытым полям не получают
//Дружественные классы 


//Представим, что у есть два класса. Предположим, что у нас все методы класса Human должны уметь работать с классом Apple
// В таком случае нам неудобно будет описывать дружественность методов из-за их большого количества
// Поэтому была предусмотрена возможность сделать весь класс дружественным, что избавит от необходимости описывать дружественность каждой функции

//Дружественность классов нарушает инкапсуляцию. Пример в функции EatApple - мы можем обратиться к приватным полям класса Apple и изменить их
//Такой же пример закомментирован в функции вне класса takeApple

//Без крайней необходимости лучше не использовать дружественные классы из-за проблем, описанных выше
class Human;
class Apple;

class Human{
    public:
        void takeApple(Apple &apple);

        void EatApple(Apple &apple){
        //apple.color = "blue"
        }
};

class Apple{

    friend Human;//Класс Human является дружественным по отношению к классу 

    public:
        Apple(int weight, string color){
            this -> weight = weight;
            this -> color = color;
        }
    private:
        int weight;
        string color;

};


int main(){
    setlocale(LC_ALL, "ru");
    Apple apple(150, "red");

    Human human;
    human.takeApple(apple);

    return 0;
}

void Human::takeApple(Apple & apple){
    //apple.color = "blue";
    cout << "Take apple " << "\tweight - " << apple.weight << "\tcolor - " << apple.color << endl;    

}
