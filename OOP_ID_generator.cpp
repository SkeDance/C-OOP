#include <iostream>
#include <string>

using namespace std;

class Person;

class Person{
    
    public:

        static int Count;

        Person(int first_name, int second_name){
            this -> first_name = first_name;
            this -> second_name = second_name;
            Count++;            
            ID = Count;
        }
        
        int GetID(){
            return ID;
        }

    private:
        int first_name;
        int second_name;
        int ID;

};

int Person::Count = 0;

int main(){

    setlocale(LC_ALL, "ru");
    Person a(4, 3);
    Person b(5,6);
    Person c(4, 3);

    cout << a.GetID() << endl;
    cout << b.GetID() << endl;
    cout << c.GetID() << endl;

    return 0;
}
