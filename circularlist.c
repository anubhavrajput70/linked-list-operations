//singly circular linked list operations
#include<stdio.h>
#include<stdlib.h>
void append();
void display();
int length();
struct node
{
int data;
struct node *next;
};
struct node *root=NULL;
struct node *temp,*ptr;
int len=0;
void main()
{
int c;
while(1)
{
printf("\n1. append\n");
printf("2. display\n");
printf("3. length\n");
printf("4. exit\n");
printf("enter your choice=\n");
scanf("%d",&c);
switch(c)
{
case 1:
append();
break;
case 2:
display();
break;
case 3:
len=length();
printf("length=%d",len);
break;
case 4:
exit(0);
default:
printf("wrong choice");
}
}
}
void append()
{
temp=(struct node*)malloc(sizeof(struct node));
if(temp==NULL)
{
printf("out of memory space");
exit(0);
}
printf("enter the data value for the node=\n");
scanf("%d",&temp->data);
temp->next=NULL;
if(root==NULL)
{
root=temp;
temp->next=root;
}
else
{
ptr=root;
while(ptr->next!=root)
{
ptr=ptr->next;
}
ptr->next=temp;
temp->next=root;
}
}
void display()
{
ptr=root;
printf("\nThe List elements are:\n");
while(ptr->next!=root)
{
printf("%d\t",ptr->data);
ptr=ptr->next ;
}
printf("%d\t",ptr->data);
}
int length()
{
int count=0;
if(root==NULL)
{
printf("list is empty\n");
}
else
{
temp=root;
count++;
while(temp->next!=root)
{
count++;
temp=temp->next;
}
}
return count;
}
