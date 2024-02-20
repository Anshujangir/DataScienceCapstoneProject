#include <iostream>
#include<bits/stdc++.h>
#include <string>
using namespace std;
#define ll long long int

int partition(int* arr, int start, int end){
    int pivot = arr[end];
    int pIndex = start; // 0 based indexing so end = size -1

    for (int i = start; i< end; i++){
        if (arr[i] <= pivot) {
            swap(arr[i], arr[pIndex]);
            pIndex++;
        }
    }
    swap(arr[pIndex], arr[end]);
    return pIndex;
}
void quickSort(int* arr, int start, int end){
    if (start < end){
        int pIndex = partition(arr, start, end);
        quickSort(arr, start, pIndex -1);
        quickSort(arr, pIndex + 1, end);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Your code goes here
    int arr[] = {6,2,3,1,9,10,15,13,12,17};
    int size = sizeof(arr)/ sizeof(arr[0]);
    quickSort(arr, 0, size -1 );
    for (int i =0; i<size; i++){
        cout<<arr[i]<<" "; 
    }


    return 0;
}