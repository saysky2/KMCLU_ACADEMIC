//stack using array.
#include<stdio.h>
#include<stdlib.h>
#define MAXSTK 100
int top=-1;
int items[MAXSTK];
int Isempty();
int Isfull();
void Push(int);
int Pop();
void Display();
int main()
{
int x;
char ch='1';
while(ch!='4')
{
printf("\n 1-PUSH");
printf("\n 2-POP");
printf("\n 3-DISPLAY");
printf("\n 4-QUIT");
printf("\n Enter your choice:");
fflush(stdin);
ch=getchar();
switch(ch)
{
case '1':
printf("\n Enter the element to be pushed:");
scanf("%d",&x);
Push(x);
break;
case '2':
x=Pop();
printf("\n Pop element is %d\n:",x);
break;
case '3':
Display();
break;
case '4':
break;
default:
printf("\n Wrong choice!Try again:");
}
}
}
int Isempty()
{
if(top==-1)
return 1;
else
return 0;
}
int Isfull()
{
if(top==MAXSTK-1)
return 1;
else
return 0;
}
void Push(int x)
{
if(Isfull())
{
printf("\n Stack full");
return;
}
top++;
items[top]=x;
}
int Pop()
{
int x;
if(Isempty())
{
printf("\n Stack empty");
exit(0);
}
x=items[top];
top--;
return x;
}
void Display()
{
int i;
if(Isempty())
{
printf("\n Stack empty");
return;
}
printf("\n Elements in the Stack are :\n");
for(i=top;i>=0;i--)
printf("%d\n",items[i]);
}