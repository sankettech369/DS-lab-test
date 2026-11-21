#include <stdio.h>
#include <stdlib.h>

struct node{
int data;
struct node *next;
};
struct node *top=NULL;

void push(){
struct node *newnode;
int item;
newnode=(struct node*)malloc(sizeof(struct node));
printf("entrt the item to push : ");
scanf("%d",&item);
newnode->data=item;
newnode->next=top;
top=newnode;
}

void pop(){
struct node *temp;
if(top==NULL){
printf("stack underflow");
return;
}
temp=top;
printf("%d deleted from the stack",top->data);
top=top->next;
free(temp);
}

void display(){
struct node *temp;
if(top==NULL){
printf("stack underflow");
return;
}
temp=top;
printf("stack contents\n");
while(temp!=NULL){
	printf("%d\n",temp->data);
	temp=temp->next;
}
}
int main(){
int choice;
while(1){
printf("\n1.push 2. pop 3.display 4.exit\n");
printf("entret your choice ");
scanf("%d",&choice);
switch(choice){
case 1:
push();
break;
case 2:
pop();
break;
case 3:
display();
break;
case 4:
exit(0);

default:
printf("invalid choice");
}
}
return 0;

}