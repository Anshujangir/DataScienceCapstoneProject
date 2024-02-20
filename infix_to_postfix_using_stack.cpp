#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
int size=100,top=-1;
char stack[100];
void push(char item)
{
	if(top >= size-1)
	{
		printf("\nStack Overflow.");
	}
	else
	{
		top = top+1;
		stack[top] = item;
	}
}
char pop()
{
	char item ;
	if(top <0)
	{
		printf("stack under flow: invalid infix expression");
		exit(1);
	}
	else
	{
		item = stack[top];
		top = top-1;
		return(item);
	}
}
void display()
{
    if(top!=-1)
    {
        for(int i=top;i>=0;i--)
        {
            printf("%d  ",stack[i]);
        }
    }
    else
    {
        printf("empty stack");
    }
}
int is_operator(char symbol)
{
	if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol =='-')
	{
		return 1;
	}
	else
	{
	return 0;
	}
}
int precidency(char symbol)
{
	if(symbol == '^')/* exponent operator, highest precedence*/
	{
		return(5);
	}
	else if(symbol == '/')
	{
		return(4);
	}
	else if(symbol == '*')
	{
		return(3);
	}
	else if(symbol == '-')
	{
		return(2);
	}
	else if(symbol == '+')
	{
		return(1);
	}
	else
	{
		return(0);
	}
}
void InfixToPostfix(char inexp[],char postexp[])
{
    int i,j;
    char item,x;
    push('(');
    strcat(inexp,")");
    i=0;
    j=0;
    item=inexp[i];
    while(item!='\0')
    {
        if(item=='(')
        {
            push(item);
        }
        else if( isdigit(item) || isalpha(item))
        {
            postexp[j]=item;
            j++;
        }
        else if(is_operator(item)==1) //means  item is operator
        {
			x=pop();
			while(is_operator(x) == 1 && precidency(x)>= precidency(item))
			{
			    postexp[j]=x;
			    j++;
			    x=pop();
			}
			push(x);
			push(item);
        }
		else if(item == ')')
		{
			x = pop();
			while(x != '(')
			{
				postexp[j] = x;
				j++;
				x = pop();
			}
		}
		else
		{
			printf("Invalid infix Expression.\n");
			exit(1);
		}
		i++;
		item = inexp[i];
    }
	if(top>0)
	{
		printf("Invalid infix Expression.\n");
		exit(1);
	}
	postexp[j] = '\0';
}
int main()
{
    int ch;
	char infix[size], postfix[size];
	printf("note: The infix expression contains single letter variables and single digit constants only.\n");
	printf("\nEnter Infix expression : ");
	gets(infix);
	InfixToPostfix(infix,postfix);
	printf("Postfix Expression: ");
	puts(postfix);
	return main();
}
