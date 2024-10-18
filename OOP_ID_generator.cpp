#include <iostream>
#include <string>

using namespace std;

class Person;
class BD;

class Person{
    
    public:
        static int ID;

        Person(string first_name, string second_name){
            this -> first_name = first_name;
            this -> second_name = second_name;
            ID++;
        }
        
        int GetID(){
            return ID;
        }
        // int BD(int ID){
        //     int* data;
        //     data = new int[ID];
        //     for(int i = 0; i < 4; i++){
        //         data[i] = i;
        //     }
        //     return* data;
        // }

    private:
        string first_name;
        string second_name;
};


int Person::ID = 0;

int main(){

    Person a("Zaxar", "Skadi");
    Person b("Ilya", "Refraction");
    Person c("Sueta", "Redhead");

    cout << Person::ID << endl;

    int z = a.GetID();
    cout << z;

    int* data;
    data = new int[z];
    for(int i = 0; i < z; i++){
        data[i] = z;
    }


    return 0;
    
}