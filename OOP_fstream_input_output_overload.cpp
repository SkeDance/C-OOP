#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

// Перегрузка оператора потокового ввода и вывода

// << and >>
// Перегрузка данных операторов позволит выводить и вводить любой тип данных, для которого реализовна перегрузка оператора 
// Цель данного урока - реализовать перегрузка операторов << и >> для классов пользователя

using namespace std;

class Point
{
    public:
        Point()
        {
            x = y = z = 0;
        }
        Point(int x, int y, int z)
        {
            this -> x = x;
            this -> y = y;
            this -> z = z;
        }
    private:
        int x;
        int y;
        int z;
        // Объявляем методы дружественными, чтобы они могли получить доступ к private полям
        friend ostream& operator<<(ostream& os, const Point& point);
        friend istream& operator>>(istream& is, Point& point);
};  

// Метод, котороый возвращает ссылку на объект типа ostream
// Объект класса ofstream связан с ofstream, fstream и т.д цепочкой наследования 
// Первый параметр - объект ostream, - но после перегрузки мы сможем работать и с классами ofstream, instream, fstream из-за цепочки наследования
// Второй параметр - класс, для которого мы перегружаем оператор
ostream& operator<<(ostream& os, const Point& point)
{
    os << point.x << " " << point.y << " " << point.z;
    return os;
}

// Метод, котороый возвращает ссылку на объект типа istream
// Объект класса ofstream связан с ofstream, fstream и т.д цепочкой наследования 
// Первый параметр - объект ostream, - но после перегрузки мы сможем работать и с классами ofstream, instream, fstream из-за цепочки наследования
// Второй параметр - класс, для которого мы перегружаем оператор
istream& operator>>(istream& is, Point& point)
{
    is >> point.x >> point.y >> point.z;
    return is;
}

int main()
{
    setlocale(LC_ALL, "ru");
    Point point(22, 0, 2143);

    // Выводим в терминал данные об объекте класса point при помощи cout
    // Без перегрузки такая запись не сработает
    cout << point << endl;

    fstream fs;
    string path = "C:\\Users\\SkyDance\\Desktop\\myfile.txt";
    fs.open(path, fstream::app | fstream::in | fstream::out);

    if(!fs.is_open())
    {
        cout << " error" << endl;
    }
    else{
        cout << "done" << endl;
        // Запись параметров объекта класса point в файл
        // Строка закомментирована, таккак с ней не работает запись в объект класса
        // fs << point << "\n";

        while (true)
        {   
            Point p; 
            fs >> p;
                if (fs.eof())
                {
                    break;
                }
            cout << p << endl;
        }
    }
    fs.close();
    return 0;
}