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
void find();
void sort();
void del_full();
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
printf("4. insertion at beginning\n");
printf("5. insertion at end\n");
printf("6. insertion at specific position\n");
printf("7. deletion at beginnning\n");
printf("8. deletion at end\n");
printf("9. deletion at specific position\n");
printf("10. find\n");
printf("11. sort\n");
printf("12. delete full list\n");
printf("13. exit\n");
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
find();
break;
case 11:
sort();
break;
case 12:
del_full();
break;
case 13:
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
}
else
{
ptr=root;
while(ptr->next!=NULL)
{
ptr=ptr->next;
}
ptr->next=temp;
temp->pre=ptr;
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
while(temp!=NULL)
{
printf("%d-->>",temp->data);
temp=temp->next;
}
}
}
int length()
{
int count=0;
temp=root;
while(temp!=NULL)
{
count++;
temp=temp->next;
}
return count;
}
void at_beg()
{
temp=(struct node*)malloc(sizeof(struct node));
printf("enter the data value for the newly created node=");
scanf("%d",&temp->data);
temp->next=NULL;
temp->pre=NULL;
if(root==NULL)
{
root=temp;
}
else
{
struct node *ptr;
ptr=root;
temp->next=ptr;
ptr->pre=temp;
root=temp;
}
}

void at_end()
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
}
else
{
ptr=root;
while(ptr->next!=NULL)
{
ptr=ptr->next;
}
ptr->next=temp;
temp->pre=ptr;
}
}

void at_pos()
{
struct node *ptr;
int loc,i=1;
printf("enter the location at which you want to insert element=");
scanf("%d",&loc);
len=length();
if(loc>len)
{
printf("invalid location");
printf("currently list has %d elements",len);
}
else
{
ptr=root;
while(i<loc-1)
{
ptr=ptr->next;
i++;
}
temp=(struct node*)malloc(sizeof(struct node));
printf("enter the data value for the newly created node=");
scanf("%d",&temp->data);
temp->next=NULL;
temp->pre=NULL;
temp->next=ptr->next;
ptr->next->pre=temp;
ptr->next=temp;
temp->pre=ptr;
}
}
void del_at_beg()
{
struct node *ptr;
ptr=root;
temp=ptr->next;
root=ptr->next;
temp->pre=NULL;
free(ptr);
}
void del_at_end()
{
struct node *ptr;
temp=root;
while(temp->next!=NULL)
{
temp=temp->next;
}
ptr=temp->pre;
ptr->next=NULL;
temp->pre=NULL;
free(temp);
}
del_at_pos()
{
struct node *ptr;
int loc,i=1;
printf("enter the location at which you want to insert element=");
scanf("%d",&loc);
len=length();
if(loc>len)
{
printf("invalid location");
printf("currently list has %d elements",len);
}
else
{
temp=root;
while(i<loc-1)
{
temp=temp->next;
i++;
}
ptr=temp->next;
temp->next=ptr->next;
ptr->pre=NULL;
ptr->next->pre=temp;
ptr->next=NULL;
free(ptr);
}
}
void find()
{
int f,i=1,j=0;
printf("enter the element you want to search in the list=");
scanf("%d",&f);
temp=root;
while(temp->next!=NULL)
{
temp=temp->next;
i++;
if(temp->data==f)
{
j=i;
}
}
if(j==0)
{
printf("not found");
}
else
{
printf("element found at %d position",j);
}
}
void sort()
{
struct node *ptr;
int a;
ptr=root;
while(ptr->next!=NULL)
{
temp=ptr->next;
while(temp!=NULL)
{
if(temp->data>ptr->data)
{
a=temp->data;
temp->data=ptr->data;
ptr->data=a;
}
temp=temp->next;
}
ptr=ptr->next;
}
}
void del_full()
{
while(root!=NULL)
{
temp=root;
root=root->next;
free(temp);
}
}
