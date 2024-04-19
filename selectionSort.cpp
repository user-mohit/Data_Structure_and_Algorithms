#include<iostream>
using namespace std ;

void selectionSort(int arr[],int size){
    for(int i=0; i<size-1; i++){
        for(int j=i+1; j<size; j++){
            if(arr[j]<arr[i]){
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }

    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int arr[] = {78,15,89,45,48,0};
    int n = 6;

    selectionSort(arr,n);

}