//singly linked list operations
#include<stdio.h>
#include<stdlib.h>
void append();
void display();
int length();
void at_beg();
void at_end();
void at_pos();
void del_at_beg();
void del_at_end();
void del_at_pos();
void sort();
void find();
struct node
{
int data;
struct node *link;
};
struct node *root=NULL;
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
printf("4. insertion at beginning\n");
printf("5. insertion at end\n");
printf("6. insertion at specific position\n");
printf("7. deletion at beginning\n");
printf("8. deletion at end\n");
printf("9. deletion at specific position\n");
printf("10. sort\n");
printf("11. find\n");
printf("12. exit\n");
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
at_beg();
break;
case 5:
at_end();
break;
case 6:
at_pos();
break;
case 7:
del_at_beg();
break;
case 8:
del_at_end();
break;
case 9:
del_at_pos();
break;
case 10:
sort();
break;
case 11:
find();
break;
case 12:
exit(0);
default:
printf("wrong choice");
}
}
}
void append()
{
struct node *temp,*ptr;
temp=(struct node*)malloc(sizeof(struct node));
printf("enter node value=");
scanf("%d",&temp->data);
temp->link=NULL;
if(root==NULL)
{
root=temp;
}
else
{
ptr=root;
while(ptr->link!=NULL)
{
ptr=ptr->link;
}
ptr->link=temp;
}
}
void display()
{
struct node *ptr;
ptr=root;
if(ptr==NULL)
{
printf("list is empty");
}
else
{
while(ptr!=NULL)
{
printf("-->%d",ptr->data);
ptr=ptr->link;
}
}
}
int length()
{
int count=0;
struct node* temp;
temp=root;
while(temp!=NULL)
{
count++;
temp=temp->link;
}
return count;
}
void at_beg()
{
struct node* temp;
temp=(struct node*)malloc(sizeof(struct node));
printf("enter node value=");
scanf("%d",&temp->data);
temp->link=NULL;
if(root==NULL)
{
root=temp;
}
else
{
temp->link=root;
root=temp;
}
}
void at_end()
{
struct node *temp,*ptr;
temp=(struct node*)malloc(sizeof(struct node));
printf("enter node value=");
scanf("%d",&temp->data);
temp->link=NULL;
if(root==NULL)
{
root=temp;
}
else
{
ptr=root;
while(ptr->link!=NULL)
{
ptr=ptr->link;
}
ptr->link=temp;
}
}
void at_pos()
{
struct node *temp,*ptr;
int loc,i=0;
temp=(struct node*)malloc(sizeof(struct node));
printf("enter the location after which you want insert the node=");
scanf("%d",&loc);
printf("enter node value=");
scanf("%d",&temp->data);
temp->link=NULL;
len=length();
if(loc>len)
{
printf("invalid location\n");
printf("currently list have %d nodes",len);
}
else
{
ptr=root;
while(i<loc-1)
{
ptr=ptr->link;
i++;
}
temp->link=ptr->link;
ptr->link=temp;
}
}
void del_at_beg()
{
struct node *temp;
temp=root;
root=temp->link;
temp->link=NULL;
free(temp);
}
void del_at_end()
{
struct node *temp,*ptr;
temp=root;
while(temp->link!=NULL)
{
ptr=temp;
temp=temp->link;
}
ptr->link=NULL;
free(temp);
}


void del_at_pos()
{
struct node *temp,*ptr1,*ptr;
int loc,i=0;
printf("enter the location you want to delete=");
scanf("%d",&loc);
if(loc>length())
{
printf("invalid location");
}
if(loc==0)
{
ptr1=root;
root=ptr1->link;
ptr1->link=NULL;
free(ptr1);
}
else
{
i++;
temp=root;
while(i!=loc)
{
temp=temp->link;
i++;
}
ptr=temp->link;
temp->link=ptr->link;
ptr->link=NULL;
free(ptr);
}
}
void sort()
{
struct node *temp,*ptr;
int a;
ptr=root;
while(ptr->link!=NULL)
{
temp=ptr->link;
while(temp!=NULL)
{
if(ptr->data<temp->data)
{
a=ptr->data;
ptr->data=temp->data;
temp->data=a;
}
temp=temp->link;
}
ptr=ptr->link;
}
}
find()
{
struct node *temp;
int f,i=1,j=0;
printf("enter the element you wnat to search=");
scanf("%d",&f);
temp=root;
while(temp->link!=NULL)
{
i++;
temp=temp->link;
if(f==temp->data)
{
j=i;
break;
}
}
if(j!=0)
{
printf("element found at=%d",j);
}
else
{
printf("not found");
}
}

