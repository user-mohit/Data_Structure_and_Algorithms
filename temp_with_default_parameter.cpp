#include<iostream>
using namespace std;

template <class T1=int, class T2=float>

class Mohit {
    public:
        T1 a;
        T2 b;

        Mohit(T1 x, T2 y){
            a = x;
            b = y;
        }

        void display(){
            cout<<"The value of a is "<<a<<endl;
            cout<<"The value of b is "<<b<<endl;
        }
};

int main() {

    Mohit <> m(1, 1.8);
    m.display();
}
