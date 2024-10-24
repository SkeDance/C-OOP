//Ключевое слово static
//Обычно, когда мы ходим обратиться к какому-либо публичному полю класса, мы это можем сделать на уровне экземпляра класса
//То есть нам нужно создать объект класса, который у нас где-то схематически описан, поставить точку и выбрать из списка. Такая переменная будет индивидуальная для каждого объекта класса
//Если мы создаем переменную с модификатором static, то такая переменная будет общей для всех объектов класса
//Это значит, что при обращении к переменной первого объекта с модификатором static через точку и последующим изменением этой переменной,
//то при обращении к такой же переменной, но уже второго объекта, мы получим измененное значение переменной
//Для работы с такой переменной нам не нужен экземпляр класса
//Для работы с такой static переменной мы можем обращаться к описанию класса, не указывая объект. Пример записи: Apple::Count
//Использавние статических переменных позволяет сделать самый простой генератор ID
#include <iostream>
#include <string>

using namespace std;

class Human;
class Apple;

class Human{
    public:
        void takeApple(Apple &apple);

        void EatApple(Apple &apple){
        }
};

class Apple{
    

    friend Human;//Класс Human является дружественным по отношению к классу 

    public:
        static int Count;
        //Конструктор объекта Apple
        Apple(int weight, string color){
            this -> weight = weight;
            this -> color = color;
            Count++;//Инкремент в конструкторе позволяет увеличивать переменную Count каждый раз, когда создаётся новый объект класса. Таким образом мы всегда будем знать, сколько объектов определнного класса было создано
        }
    private:
        int weight;
        string color;

};
//Для начала работы необходимо инициализировать статическую переменную вне класса
int Apple::Count = 0;


int main(){
    setlocale(LC_ALL, "ru");
    Apple apple(150, "red");
    Apple apple2(100, "green");
    Apple apple3(200, "yellow");

    //Обращение к переменной экземпляра объекта
    cout << apple.Count << endl;
    //Обращение к описанию класса
    cout << Apple::Count << endl;

    Human human;
    human.takeApple(apple);

    return 0;
}

void Human::takeApple(Apple & apple){

    cout << "Take apple " << "\tweight - " << apple.weight << "\tcolor - " << apple.color << endl;    

}
