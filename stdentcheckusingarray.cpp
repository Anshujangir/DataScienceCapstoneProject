#include<iostream>
#include<string>
#include<conio.h>
using namespace std;
class Data1 {
    private:
    string sfn[4];
    string sln[4];
    int roll[4];
    public:
   void data() {
        for(int i=0;i<4;i++)
        {
            cout<<"enter roll number : ";
            cin>>roll[i];
            cout<<"enter first name : ";
            cin>>sfn[i];
            cout<<"Enter last name : ";
            cin>>sln[i];
        }

    }
    void show_data(int rollnumber) {
        int flag=0,k;
        for(int i=0;i<4;i++)
        {
            if(roll[i]==rollnumber)
            {
                k=i;
                break;
            }
            else
            {
                flag++;
            }
            
        } 
        if(flag==4)
        {
            cout<<"in this class no student of this roll number "<<endl;

        }
        else
        {
            cout<<"student name is ";
            cout<<sfn[k]<<" "<<sln[k];
        }
                    
    }

};
int main()
{   int rl;
    Data1 d;
    d.data();
    cout<<"Enter student roll number for name :";
    cin>>rl;
    d.show_data(rl);
    return 0;
}
