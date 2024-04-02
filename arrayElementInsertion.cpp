#include <iostream>
using namespace std;

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void elementInsertion(int arr[], int &size, int capacity, int index, int element)
{
    if (size >= capacity)
    {
        cout << "Invalid position for the insertion.";
    }
    for (int i = size; i > index; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[index] = element;
    size++;
}

void  elementDeletion(int arr[], int size, int index){
    if(index>=size){
        cout<<"Invalid Index."<<endl;
    }
    
    for(int i=index; i < size-1 ; i++){
        arr[i] = arr[i+1];
    }
}
int main()
{
    int capacity = 50;
    int arr[capacity] = {12, 56, 89, 79, 23};
    int size = 5;
    int element = 77;
    int index = 2;
    int indexToDelete = 0;
    cout << "Array before insertion: " << endl;
    display(arr, size);

    elementInsertion(arr, size, capacity, index, element);
    cout << "Array after insertion: " << endl;
    display(arr, size);

    elementDeletion(arr, size, indexToDelete);
    size -=1;
    cout<<"Array after deletion: "<< endl;
    display(arr, size);

    return 0;
}