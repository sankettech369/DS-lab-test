#include <stdio.h>
#include <stdlib.h>

int *queue;
int size;
int front=-1;
int rear=-1;

void resize(){
int newsize=size*2;
int *newqueue;
int i=0;
int index;

newqueue=(int*)malloc(newsize* sizeof(int));
if(newqueue==NULL){
printf("memeory alloaction failed\n");
return;
}

if(front!=-1){
index=front;
while(1){
newqueue[i]=queue[index];
if(index==rear)
break;
index=(index+1)%size;
i++;
}
front=0;
rear=i;
}
free(queue);
queue=newqueue;
size=newsize;
printf("queue is full queue size doubled to %d\n",size);
}


void insert(){
int item;
if((rear+1)%size==front){
resize();
}

printf("enter the item: ");
scanf("%d",&item);
if(front==-1){
front=0;
rear=0;
}
else{
rear=(rear+1)%size;
}
queue[rear]=item;
printf("%d inserted into the circular queue \n",item);
}

void delete(){
int item;
if(front==-1){
printf("circular queue underflow\n");
return;
}
item=queue[front];
if(front==rear){
front=-1;
rear=-1;
}
else{
front=(front+1)%size;
}
printf("%d deleted from the cicular queue\n",item);
}

void display(){
int i;
if(front ==-1){
printf("circular queue is empty\n");
return;
}
printf("circular queue contents");
i=front;
while(1){
printf("%d",queue[i]);
if(i==rear)
break;
i=(i+1)%size;
}
printf("\n");
}


int main(){
int choice;
printf("enter the size of cir queue:");
scanf("%d",&size);
queue=(int*)malloc(size* sizeof(int));
while(1){
printf("1.insert\n");
printf("2.Delete\n");
printf("3.display\n");
printf("4.exit\n");
printf("enter your choice");
scanf("%d",&choice);
switch(choice){
case 1:
insert();
break;
case 2:
delete();
break;
case 3:
display();
break;
case 4:
free(queue);
return 0;
default :
printf("invalid choice");
}
}
}