#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Обработка исключений try catch
// Обработка исключений - обработка исключительных ситуаций, то есть тех проблем, которые не зависят от программиста, но которые он предвидел
// Под обработкой подразумевается реакция на исключительную ошибку, к примеру, уведомление или попытка все восстановить
// Обработка исключительных ситуаций будет рассмотрена на примере работы с файлами 

int main()
{
    string path = "C:\\Users\\SkyDaaance\\Desktop\\myfile.txt";
    ifstream fin;
    // Включение обработки исключительных ситуаций для класса ifstream. Стоит учесть, что это именно специфика класса ifstream
    fin.exceptions(ifstream::badbit | fstream::failbit);
    // Самый простой способ попасть в блок catch - изменить путь к файлу на некорректный 
    
    try
    {
        cout << "try to open file" << endl;

        fin.open(path);

        cout << "file opened" << endl;
    }
    // класс ifstream имеет собственный обработчик ошибок
    // Стандартный обработчик - std::exception
    catch(const ifstream::failure& ex)
    {   
        cout << ex.what() << endl; // Стандартный обработчик
        cout << ex.code() << endl; // Обработчик класса ifstream
        cout << "file open error" << endl;
    }
    

    return 0;
}