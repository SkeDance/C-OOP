#include <iostream>
#include <string>
#include <memory>

using namespace std;



int main()
{
    setlocale(LC_ALL, "ru");
    // Ввод количества элементов динамического массива с клавиатуры
    int SIZE;
    cin >> SIZE;

    // Создание динамического масисва
    int *arr = new int[SIZE] {1, 43, 321, 12, 29};

    // Умный указатель
    shared_ptr<int[]> ptr(arr);

    // Вывод всех элементов динамического массива  втерминал
    for (int i = 0; i < SIZE; i++)
    {
        ptr[i] = rand() %10;
        cout << ptr[i] << endl;
    }



    return 0;
}