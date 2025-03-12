//Queue using an array.



#include<stdio.h>
#include<stdlib.h>
#define MAXQ 100    
int front=0,rear=-1;
int items[MAXQ];
int Isempty();
int Isfull();
void Insert(int);
int Delete();
void Display();
int main()
{
int x;
char ch='1';
while(ch!='4')
{
printf("\n 1-INSERT");
printf("\n 2-DELETE");
printf("\n 3-DISPLAY");
printf("\n 4-QUIT");
printf("\n Enter your choice:");
fflush(stdin);
ch=getchar();
switch(ch)
{
case '1':
printf("\n Enter the element to be inserted:");
scanf("%d",&x);
Insert(x);
break;
case '2':
x=Delete();
printf("\n Delete element is %d\n:",x);
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
if(rear<front)
return 1;
else
return 0;
}
int Isfull()
{
if(rear==MAXQ-1)
return 1;
else
return 0;
}
void Insert(int x)
{
if(Isfull())
{
printf("\n Queue full");
return;
}
rear++;
items[rear]=x;
}
int Delete()
{
int x;
if(Isempty())
{
printf("\n Queue is empty");
exit(0);
}
x=items[front];
front++;
return x;
}
void Display()
{
int i;
if(Isempty())
{
printf("\n Queue is empty");
return;
}
printf("\n Elements in the Queue are :\n");
for(i=front;i<=rear;i++)
printf("%d\n",items[i]);
}