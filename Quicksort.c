#include<stdio.h>
int beg,end,loc,n,i,j,item,temp,a[50];
int st1[50], top1 = -1, top2 = -1, st2[50];
void push(int x, int y)
{
    top1++;
    top2++;
    st1[top1] = x;
    st2[top2] = y;
}
void pop()
{
    top1--;
    top2--;

}

int getloc(){
    i = beg;
    j = end;
    item = a[i];
    loc = i;
    while(i<j){
        while(i<j&&item<a[j]){
            j--;
        }
        temp = a[loc];
        a[loc]=a[j];
        a[j]= temp;
        loc = j;
        while(i<j&&item>a[i]){
            i++;
        }
        temp = a[loc];
        a[loc] = a[i];
        a[i] = temp;
        loc = i;
    }
    return loc;
}


void main()
{
    printf("enter the no. of elements you want to insert: ");
    scanf("%d",&n);
    printf("enter the elements:\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("the elements are:\n");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    beg = 0;
    end = n-1;
    push(beg,end);
    while(top1!=-1&&top2!=-1){
        beg = st1[top1];
        end = st2[top2];
        pop();
        getloc();
        if(beg<end){
            push(beg,loc-1);
            push(loc+1,end);
        }
    }

    printf("\nsorted array is: ");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\nprogram finished");
}
