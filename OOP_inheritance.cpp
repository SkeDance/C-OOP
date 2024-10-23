#include <iostream>
#include <string>

using namespace std;

// Наследование

class Human {
    private:
        string name;
    public:
        string GetName(){
            return name;
        }

        void SetName(string name) {
            this -> name = name;
        }

};

class Student : public Human
{
    public:
        string group;

        void learn(){
            cout << "studying" << endl;
    }
};

class ExtramuralStudent : public Student
{
    public:
        void learn(){
            cout << "studying less" << endl;
    }
};

class Teacher : public Human
{
    public:
        string subject;
};

int main(){
    
    setlocale(LC_ALL, "ru");

    Student st;
    st.SetName("Terentiy");
    Teacher tch;
    // tch.name = "Vadim";
    cout << st.GetName() << endl;
    st.learn();

    ExtramuralStudent est;
    est.SetName("Evlampiy");
    cout << est.GetName() << endl;
    est.learn();


    return 0;
}