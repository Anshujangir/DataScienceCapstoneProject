#include<stdio.h>
int main()
{
    int i,n=5,a[n],found,flag,loc=0;
    for(i=0;i<n;i++)
    {   printf("eneter the array");
    scanf("%d",&a[i]);
    }
    printf("your array :  ");
    for(i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }
    printf("\n enter element which you want to find");
    scanf("%d",&found);
    for(i=0;i<n;i++)
    {
        if(found==a[i])
        {
             flag=1;
             loc=1;
        } 
        
    }if (flag == 1 ){
    printf("item found and item is %d at position = %d ", a[loc],loc+1);}
    else{  
     printf("item not found");
     }  
}    
