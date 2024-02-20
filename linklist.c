#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
    int info;
    struct node* link;
}*new_node,*start,*temp,*last;
void create()
{
    int value;
    int choice;
do
{
    new_node = (struct node*)malloc(sizeof(struct node));
    printf("enter value");
    scanf("%d",&value);
    new_node->info=value;
    new_node->link=NULL;
    if(start==NULL)
    {
        start=new_node;
        last=new_node;
    }
    else
    {
        last->link=new_node;
        last=new_node;
        last->link=NULL;
    }
     printf("press 1 to continue 0 to exit");
     scanf("%d",&choice);
}
while(choice==1);
}
void display()
{
    printf("linklist : ");
    temp=start;
    while(temp->link!=NULL)
    {
        printf("%d->",temp->info);
        temp=temp->link;
    }
    printf("%d->",temp->info);
    printf("NULL");
}
void insert()

{
    int choice,pos,item,i;
    printf("\n***choice***\n1.insert at beg\n2. insert at end\n3. insert at specfic postion\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        printf("enter element : ");
        scanf("%d",&item);
        new_node=(struct node*)malloc(sizeof(struct node));
        if(new_node==NULL)
        {
            printf("out of memory\n");
            exit(1);
        }
        new_node->info=item;
        new_node->link=start;
        start=new_node;
        break;
        case 2:
        printf("enter element : ");
        scanf("%d",&item);
        new_node=(struct node*)malloc(sizeof(struct node));
        if(new_node==NULL)
        {
            printf("out of memory\n");
            exit(1);
        }
        new_node->info=item;
        new_node->link=NULL;
        last->link=new_node;
        last=new_node;
        break;
        case 3:
        printf("enter element  and positon: ");
        scanf("%d%d",&item,&pos);
        new_node=(struct node*)malloc(sizeof(struct node));
        if(new_node==NULL)
        {
            printf("out of memory\n");
            exit(1);
        }
        new_node->info=item;
        temp=start;
        for(i=0;i<pos-1;i++)
        {
            temp=temp->link;
        }
        new_node->link=temp->link;
        temp->link=new_node;
        break;
        default:
        printf("wrong choice");
        break;
    }
}
void delete()
{
    int i, pos, choice,value;
    printf("\nenter node to delete");
    printf("\n1.press 1 if you want to delete the value at begg \n2.press 2 delete the value at end\n3.press 3 delete at mid\n4.press 4 for exit delete operation ");
    scanf("%d",&choice);
    switch(choice) 
{
    case 1:
    {  printf("enter value to delete\n");
        scanf("%d",&value);
        new_node=(struct node*)malloc(sizeof(struct node));
        if(start=NULL)
        {
            printf("out of memory");
        }
        temp=start;
        start=start->link;
        temp->info=NULL;
    break;
    }
    case 2:
    {
    printf("enter value to delete\n");
        scanf("%d",&value);
        new_node=(struct node*)malloc(sizeof(struct node));
        temp==start;
        while(temp->link!=last)
        {temp=temp->link;
        }
        temp->info = NULL;
        last=temp; 
        break;
    }
    case 3:
    {
        printf("enter the value or pos in which you want to delete");
        scanf("%d%d",&pos,&value);
        new_node=(struct node*)malloc(sizeof(struct node));
        temp=start;
        for(i=0;i<=pos-1;i++)
        {
            temp=temp->link;
          
        }
     new_node->link=temp->link;
     temp->link=new_node;
   break;
    }
}
}
int main()
{
//start=NULL;
create();
display();
insert();
display();
delete();
display();
return 0;
}
