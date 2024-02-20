#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    struct node* left;
    int info;
    struct node* right;
}*root,*new_node,*temp;
struct node* newnode(int data)
{
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->info=data;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}
void printPostorder(struct node* node) 
{ 
     if (node == NULL) 
        return; 
     printPostorder(node->left); 
     printPostorder(node->right); 
     printf("%d ", node->info); 
} 
void printInorder(struct node* node) 
{ 
     if (node == NULL) 
          return;
     printInorder(node->left); 
     printf("%d ", node->info);   
     printInorder(node->right); 
} 
void printPreorder(struct node* node) 
{ 
     if (node == NULL) 
          return; 
     printf("%d ", node->info);   
     printPreorder(node->left);   
     printPreorder(node->right); 
}    
int main()
{
    root=newnode(0);
    root->left=newnode(4);
    root->right=newnode(5);
    root->left->right=newnode(6);
    root->right->left=newnode(6);
    root->left->left=newnode(12);
    printf("inorder of binary tree : ");
    printInorder(root);
    printf("\npreorder of binary tree : ");
    printPreorder(root);
    printf("\npostorder of binary tree : ");
    printPostorder(root);
    return 0;
}
