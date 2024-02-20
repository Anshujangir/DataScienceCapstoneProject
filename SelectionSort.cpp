#include <iostream>
#include<bits/stdc++.h>
#include <string>
using namespace std;
#define ll long long int

void selectionSort(int* arr, int n){
    for (int i =0; i<n-1; i++){
        int iMin = i;
        for (int j =i+1; j<n; j++){
            if (arr[j] < arr[iMin]) iMin = j;
        }
        int temp = arr[i];
        arr[i] = arr[iMin];
        arr[iMin] = temp;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Your code goes here
    int arr[] = {5,9,1,4,2,8};
    int size = sizeof(arr)/ sizeof(arr[0]);
    selectionSort(arr, size);
    for (int i =0; i<size; i++){
        cout<<arr[i]<<" "; 
    }

    return 0;
}