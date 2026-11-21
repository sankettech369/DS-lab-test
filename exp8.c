#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *prev,*next;
};
struct node *head=NULL;

void insert(){
    struct node *newnode,*temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter data :");
    scanf("%d",&newnode->data);
    newnode->prev=NULL;
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
    }else{
        temp=head;
        while(temp->next != NULL)
            temp=temp->next;
        temp->next=newnode;
        newnode->prev=temp;
    }
    printf("node inserted successfully\n");
    }


void delete(){
    struct node *temp;
    int key;
    if(head==NULL){
        printf("list is empty\n");
        return;
    }
    printf("enter data to delete: ");
    scanf("%d",&key);
    temp=head;
    while(temp !=NULL && temp->data != key)
        temp=temp->next;
    if(temp==NULL){
        printf("node not found\n");
        return;
    }
    if(temp==head)
        head=temp->next;
    if(temp->next !=NULL)
        temp->next->prev=temp->prev;
    if(temp->prev != NULL)
        temp->prev->next=temp->next;
    free(temp);
    printf("node deleted successfully \n");
    
}

void display(){
    struct node *temp=head;
    if(head==NULL){
        printf("list is empty \n");
        return;
    }
    printf("doubly linked list:NULL<->");
    while(temp!=NULL){
        printf("%d<->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

int main(){
    int choice;
    while(1)
{
    printf("\n---doubly linked list---\n");
    printf("1.insert node\n");
    printf("2.delete node\n");
    printf("3.display list\n");
    printf("4.exit\n");
    printf("enter your choice:");
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
        exit(0);

        default:
        printf("invalid choice \n");
    }
}
return 0;
}
