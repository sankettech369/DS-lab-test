#include <stdio.h>
#include <stdlib.h>

struct node{
int data;
struct node *next;
};
struct node *front=NULL;
struct node *rear=NULL;

void enqueue(){
struct node *newnode;
int item;
newnode=(struct node*)malloc(sizeof(struct node));
printf("enter the item to insert :");
scanf("%d",&item);
newnode->data=item;
newnode->next=NULL;
if(front==NULL){
front=rear=newnode;
}else{
rear->next=newnode;
rear=newnode;
}
printf("%d inserted to the queue.\n",item);
}


void dequeue(){
struct node *temp;
if(front==NULL){
printf("queue underflow\n");
return;
}
temp=front;
printf("deleted item : %d\n",front->data);
front=front->next;
if(front==NULL){
rear=NULL;
}
free(temp);
}


void display(){
struct node *temp;
if(front==NULL){
printf("queue is empty\n");
return;
}

temp=front;
printf("queue contents\n");
while(temp!=NULL){
printf("%d ",temp->data);
temp=temp->next;
}
printf("\n");
}


int main(){
int choice;
while(1){
printf("queue operations\n");
printf("1.enqueue\n");
printf("2.dequeue\n");
printf("3.display\n");
printf("4.exit\n");
printf("enter your choice: ");
scanf("%d",&choice);
switch(choice){
case 1:
enqueue();
break;
case 2:
dequeue();
break;
case 3:
display();
break;
case 4:
exit(0);
default:
printf("inavlid choice\n");
}
}
return 0;
}