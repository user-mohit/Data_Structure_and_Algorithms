#include<iostream>
#include<map>
#include<string>

using namespace std;

void display(map<string, int>& mark) {
    map<string, int> :: iterator it;

    for (it=mark.begin(); it!=mark.end(); it++){
        cout<<(*it).first<<" "<<(*it).second<<endl;
    }
}

int main (){

    map<string, int> marks;
    marks.insert({{"Mohit", 99},{"Ankit", 88}});
    marks["Anuj"] = 67;
    display(marks);
}
