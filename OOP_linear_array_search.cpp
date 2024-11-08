#include <iostream>
#include <string>

using namespace std;



int main()
{
    setlocale(LC_ALL, "ru");

    srand(time(NULL));

    const int size = 10;

    int arr[size];

    for (int i = 0; i < 10; i++)
    {
        arr[i] = rand() % 10;
    }
    int x = 0; // Переменная для цикла while
    int value = 0; // Искомая цифра
    cout << "Enter number: " << endl;
    cin >> value; // Ввод искомой цифры с клавиатуры
    bool result = false; // Логическая переменная для вывода сообщения "empty result"
    while (x != size)
    {
        if (value == arr[x])
        {
            cout << "номер элемента в массиве: " << x + 1 << endl;
            result = true;
        }
        x++;
    }
    
    if (result == false)
    {
        cout << "empty result" << endl;
    }
    return 0;
}