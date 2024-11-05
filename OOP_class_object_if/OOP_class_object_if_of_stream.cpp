#include <iostream>
#include <string>
#include <fstream>

using namespace std;


// Чтение/сохранение объекта класса в файл

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
        this -> z =z;
    }

    void Print()
    {
        cout << x << endl << y << endl << z << endl;
    }
        int x;
        int y;
        int z;
    
};

int main()
{
    setlocale(LC_ALL, "ru");
    string path = "C:\\Users\\пк\\Desktop\\myFile.txt ";

    // В закомментированной части кода ниже происходит запись объекта класса в файл
    // Так как запись в файл происходит в непонятной кодировке, необходимо вывести записанную информацию в терминал
    // Point point(577, 240, 8760);
    // point.Print();

    // ofstream fout;

    // fout.open(path, ofstream::app);

    // if (!fout.is_open())
    // {
    //     cout << "error" << endl;
    // }
    // else{
    //     cout << "done" << endl;
    //     fout.write((char*)&point, sizeof(Point));
    // }

    // fout.close();

    // Код нже необходим для чтения объекта класса из файла и вывода его значений в терминал
    ifstream fin;
    fin.open(path);
    if(!fin.is_open())
    {
        cout << "error" << endl;
    }
    else
    {
        cout << "done" << endl;
        Point pnt;
        while (fin.read((char*)&pnt, sizeof(Point)))
        {
            pnt.Print();
        }
    }
    fin.close();


    return 0;
}