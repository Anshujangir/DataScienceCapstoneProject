#include<iostream>
using namespace std;
int main() {
    int x,y;
    x=5;
    y= ++x;
    cout<<x<<" "<<y<<endl;
    y=y*++x;
    cout<<x<<" "<<y<<endl;
    y=y*++x;
    cout<<x<<""<<y<<endl;
    x=5;
    y=0;
    y=++x*++x*++x;
    cout<<x<<" "<<y<<endl;
    return 0;
}