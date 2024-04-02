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
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];
    
    for(int i=0; i<n; i++){
        cout<<"Enter the "<<i<<" element of the array: ";
        cin>>arr[i];
    }

    selectionSort(arr,n);

}