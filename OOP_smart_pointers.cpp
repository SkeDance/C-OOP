#include <iostream>
#include <string>

using namespace std;

// Умные указатели
// Smart pointer - объектная оболочка типа данных
// Для написания SmartPointer'а используется template, чтобы этот класс мог работать с любыми типами данных

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
    
    // Выделение памяти для динамического массива. #45 and #46
    int *ptr = new int(5);
    // Получение адреса указателя ptr в памяти
    cout << ptr << endl;
    // Получение значения, которое хранится по указателю ptr
    cout << *ptr << endl;
    // Освобождение использованной памяти для предотвращения утечки
    delete ptr;

    // Создаем объект класса, выделяем динамическую память и присваиваем ему значения 10
    SmartPointer<int> pointer = new int(10);

    // Изменяем значение по указателю 
    *pointer = 14589;
    // Выводим значение в терминал
    cout << *pointer << endl;

    return 0;
}