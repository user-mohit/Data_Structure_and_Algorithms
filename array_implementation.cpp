#include<iostream>
#include<stdexcept>
using namespace std;
template <class T>

class myArray{
    T* data;
    int size;
    int capacity;
    public:
        myArray(int initialCapacity = 10){
            size = 0;
            capacity = initialCapacity;
            data = new T[capacity];
        }
        ~myArray(){
            delete[] data;
        }
        int getSize() const {
            return size;
        }
        int getCapacity() const {
            return capacity;
        }
        bool isEmpty() const {
            return size == 0;
        }
        void resize() {
            if (size == capacity){
                capacity *= 2;
                T* newData = new T[capacity];
                for(int i =0; i<size; i++){
                    newData[i] = data[i];

                }
                delete[] data;
                data = newData;
            }
        }
        void push_back(const T& value) {
            resize();
            data[size++]  = value;
    
        }

        void insertion(){

        }

        T& operator[](int index){
            if(index < 0 || index >= size){
                throw out_of_range("The index is out of range");
            }
            else {
             return data[index];
            }
        }
        void print() {
            for(int i=0; i<size; i++){
                cout<<data[i]<<" ";
                cout<<endl;
            }
        }
};
int main() {
    myArray<int> arr;
    arr.push_back(12);
    arr.push_back(22);
    arr.push_back(34);
    arr.push_back(89);

    arr.print();
    cout<<"The current size of the array is: "<<arr.getSize()<<endl;

    try {
        cout<<"The element on index 3: "<<arr[3]<<endl;

   } catch(const out_of_range& e){
        cerr<<"Exception: "<< e.what()<<endl;
   }

    return 0;
}