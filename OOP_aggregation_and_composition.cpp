#include <iostream>
#include <string>

using namespace std;

//Агрегация и композиция

class Human{

    public:

        void Think(){
            brain.Think();
        }

    private: 

        class Brain{
            public:

                void Think(){
                    cout << "Я думаю" << endl;                
                }
        };
    Brain brain;
};

int main(){

    Human human;
    human.Think();



    return 0;
}