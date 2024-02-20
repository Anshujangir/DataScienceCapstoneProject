#include<bits/stdc++.h>
using namespace std;
void quick(int a[],int l,int r)
{
    int i,j,x,temp;
    i=l;
    j=r;
    x=a[(l+r)/2];
    do
    {
        while(a[i]<x)
            i++;
        while(a[j]>x)
            j--;
        if(i<=j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            i++;
            j--;
        }
    }while(i<=j);
    if(l<j)
        quick(a,l,j);
    if(i<r)
        quick(a,i,r);
}
int main()
{
    int a[100],n,i;
    cout<<"Enter the number of elements: ";
    cin>>n;
    cout<<"Enter the elements: ";
    for(i=0;i<n;i++)
        cin>>a[i];
    quick(a,0,n-1);
    cout<<"Sorted array is: ";
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}   
