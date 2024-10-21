#include <iostream>
#include <string>

using namespace std;

// Вложенный класс - класс, реализация которого описана внутри другого класса
// Такие классы могут называться внутренними, а тот класс, в который мы вкладываем класс - объемлющий класс
// Вложенный класс может находиться во всех модификаторах полей
// Вложенный класс обычно используют для внутренних нужд класса, в который он вложен

// Рассмотрим на примере изображения, которое состоит из пикселей

// У нас есть картинка. Картинка состоит из пикселей
// Для пикселей картинки создан массив, который мы заполнили вручную. Длина массива 5 элементов
// В методе GetImageInfo мы перебираем все элементы массива и вызываем для кадого из элементов метод GetInfo
// Метод GetInfo - содержится в классе Pixel, который является внутренним для класса image и полностью от него зависит
// Метод GetInfo класса Pixel вызывается методом GetImageInfo класса Image для каждого элемента массива Pixels

class Pixel{
    public:
        //Конструктор по умолчанию
        Pixel(){
            r = g = b = 0;
        }

        Pixel(int r, int g,  int b){
            this -> r = r;
            this -> g = g;
            this -> b = b; 
        }

        string GetInfo(){            // to_string - конвертирует значение переменной в строку
            return " Pixel: r = " + to_string(r) + " g = " + to_string(g) + " b = " + to_string(b);
        }

    private:
        int r;
        int g;
        int b;
};

class Image{
    public:

        void GetImageInfo(){
            for(int i = 0; i < Length; i++){
                cout << "№" << i << pixels[i].GetInfo() << endl;
            }
        }


    private:

        static const int Length = 5;

        Pixel pixels[Length]{
                Pixel(0, 4, 64),
                Pixel(4, 14, 10),
                Pixel(111, 6, 24),
                Pixel(244, 244, 14),
                Pixel(111, 180, 64)          
            };
};


int main(){
    setlocale(LC_ALL, "ru");

    // Работа со статическим массивом
    const int Length = 5;

    // Для работы необходим конструктор по умолчанию
    Pixel arr[Length]{
        Pixel(0, 4, 64),
        Pixel(4, 14, 10),
        Pixel(111, 6, 24),
        Pixel(244, 244, 14),
        Pixel(111, 180, 64)          
    };
        
        
    cout << arr[2].GetInfo() << endl;

    arr[2] = Pixel(11, 145, 222);

    // Обращаемся к жлементу массива, в котором лежит экземпляр класса Pixel. Благодаря этому мы имеем возможность вызвать метод этого класса при помощи точки
    cout << arr[2].GetInfo() << endl;


    // Работа с динамическим массивом
    Pixel *arr2 = new Pixel[Length];

    arr2[0] = Pixel(44, 67, 900);

    cout << arr2[0].GetInfo() << endl;

    delete[]arr2;
    return 0;
}