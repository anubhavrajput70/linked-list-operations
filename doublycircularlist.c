//doubly circularlinked list operations
#include<stdio.h>
#include<stdlib.h>
void append();
void display();
int length();
struct node
{
int data;
struct node *next,*pre;
};
struct node *root=NULL,*temp;
int len=0;
void main()
{
int c;
while(1)
{
printf("\nmain menu\n");
printf("1. append\n");
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
struct node *ptr;
temp=(struct node*)malloc(sizeof(struct node));
printf("enter the data value for the newly created node=");
scanf("%d",&temp->data);
temp->next=NULL;
temp->pre=NULL;
if(root==NULL)
{
root=temp;
temp->next=root;
temp->pre=root;
}
else
{
ptr=root;
while(ptr->next!=root)
{
ptr=ptr->next;
}
ptr->next=temp;
temp->pre=ptr;
temp->next=root;
root->pre=temp;
}
}
void display()
{
temp=root;
if(temp==NULL)
{
printf("list is empty");
}
else
{
while(temp->next!=root)
{
printf("%d-->>",temp->data);
temp=temp->next;
}
printf("%d-->>",temp->data);
}
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
