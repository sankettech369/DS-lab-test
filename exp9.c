#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *left,*right;
};

struct node*createnode(int item){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));

    newnode->data=item;
    newnode->left=NULL;
    newnode->right=NULL;

    return newnode;
}
struct node *insert(struct node *root,int item){
    if(root ==NULL)
    return createnode(item);

    if(item<root->data)
    root->left=insert(root->left,item);
    else if(item>root->data)
    root->right=insert(root->right,item);

    return root;

}

void inorder(struct node *root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root){
    if(root != NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);

    }
}

void postorder(struct node *root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

int main()
{
    struct node *root=NULL;
    int n,item,i,choice;
    printf("enter number of nodes;");
    scanf("%d",&n);

    printf("enter the elements : ");
    for(i=0;i<n;i++){
        scanf("%d",&item);
        root=insert(root,item);
    }
    do{
        printf("\nmenu\n");
        printf("1. in oreder\n");
        printf("2. pre oreder\n");
        printf("3. post oreder\n");
        printf("4. exit\n");
        printf("enter your choice; ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
            printf("in order traversal:");
            inorder(root);
            printf("\n");
            break;

            case 2:
            printf("Pre-order traversal: ");
            preorder(root);
            printf("\n");
            break;

            case 3:
            printf("\nPost-order traversal: ");
            postorder(root);
            printf("\n");
            break;

            case 4:
            break;

            default:
            printf("invalid choice\n");

        }
    }while(choice !=4);


       
    return 0;
}
