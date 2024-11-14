#include <iostream>
#include <string>
#include <memory>

using namespace std;

// auto_ptr - 
template<typename T>
class SmartPointer
{   
    public:
        SmartPointer(T *ptr)
        {
            cout << "construct" << endl;
            this -> ptr = ptr;
        }
        ~SmartPointer()
        {
            cout << "destruct" << endl;
            delete ptr;
        }
        // Перегрузка оператора *, при помощи которого возвращается значение по указателю ptr
        T& operator*()
        {
            return *ptr;
        }
    private:
        // Обобщенный указатель
        T *ptr;
};

int main()
{
    setlocale(LC_ALL, "ru");

    // // Указывает на адрес в динамической памяти, где хранится 5
    // SmartPointer<int> sp1 = new int(5);
    // // Указывает sp1
    // SmartPointer<int> sp2 = sp1; 

    // На данный момент auto_ptr устарел и почти не используется
    // В ходе выполнения программы ap1 теряет связь с new int(5), поэтому ошибки не происходит
    // auto_ptr<int> ap1(new int(5));
    // auto_ptr<int> ap2(ap1);

    // Нельзя передать up1 в up2, то есть ситуация как в SmartPointer не воспроизводится 
    // unique_ptr<int> up1(new int(5));
    // unique_ptr<int> up2(up1);

    // Чтобы избежать этого необходимо воспользоваться методом move()
    unique_ptr<int> up1(new int(5));
    unique_ptr<int> up2;
    // move() - позволяет сменить владельца данных
    // То есть после использования move() up1 ни на что не указывает,
    // а up2 начинает указывать на то, на что указывал up1
    up2 = move(up1);

    // Также можно использовать метод swap, который принадлежит классу unique_ptr
    //up2.swap(up1);

    // Позволяет вернуть указатель на адрес в памяти, где хранится 5
    int *p = up2.get();
    cout << p << endl;

    // Метод reset позволяет стереть данные из памяти и указатель ни на что не указывает, так как данных нет
    int *z = new int(10);
    unique_ptr<int> z1(z);
    z1.reset();

    // Метод release позволяет указателя забыть о данных, но оставялет их в памяти 
    int *x = new int(20);
    unique_ptr<int> z2(x);
    z2.release();

    // shared_ptr может ссылаться на другие указатели, так как данные удаляются только в тот момент, когда из видимости программы выходит послений shared_ptr
    // Такая работа реализована при помощи счетчика ссылок 
    shared_ptr<int> shp1(new int(40));
    shared_ptr<int> shp2(shp1);



    return 0;
}