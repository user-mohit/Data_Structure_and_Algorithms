#include<iostream>
#include<list>

using namespace std;

void display(list<int>& lst){
    list<int> :: iterator it;

    for(it=lst.begin(); it!=lst.end(); it++){
        cout<< *it<<" ";
    }
    cout<<endl<<endl;
}

int main () {

    list<int> list1;
    list1.push_back(4);
    list1.push_back(2);
    list1.push_back(5);
    list1.push_back(1);
    list1.push_back(7);

    display(list1);

    list<int> list2(5);
    int count = 1;
    list<int> :: iterator iter;
    for(iter=list2.begin(); iter!=list2.end(); iter++){
        *iter = count;
        count ++;
    }

    display(list2);
    list2.pop_back();
    display(list2);

}