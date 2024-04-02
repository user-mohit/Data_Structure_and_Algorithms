#include<iostream>
using namespace std;

void bubbleSort(int arr[], int size, int counter=1){
    while(counter<size-1){
        for(int i=0; i<size-counter; i++){
            if(arr[i]>arr[i+1]){
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
        counter ++;
    }
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
}
int main (){

int n = 5;
int arr[n] = {56,78,89,23,45};
bubbleSort(arr,n);

}