#include <iostream>
#include <string>

using namespace std;
//Пример дружественного метода takeApple и обычного EatApple
//Первый может получить доступ к приватным полям, а второй - нет
//Обычно, вынос дружественных методов таким способом используется при классах с больши количеством полей, чтобы упростмить чтение кода
class Human;
class Apple;

class Human{
    public:
        void takeApple(Apple &apple);

        void EatApple(Apple &apple){

        }
};

class Apple{
    public:
        Apple(int weight, string color){
            this -> weight = weight;
            this -> color = color;
        }
    private:
        int weight;
        string color;

    friend void Human::takeApple(Apple &apple);
};


int main(){
    setlocale(LC_ALL, "ru");
    Apple apple(150, "red");

    Human human;
    human.takeApple(apple);

    return 0;
}

void Human::takeApple(Apple & apple){
    cout << "Take apple " << "\tweight - " << apple.weight << "\tcolor - " << apple.color << endl;    
}
