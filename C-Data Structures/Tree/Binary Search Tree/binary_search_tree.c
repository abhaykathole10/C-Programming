#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* create(void);
void inorder(struct node*);

int main(){
    struct node* root = NULL;
    root = create();
    inorder(root);
}

//Create() function will return the pointer of type struct node
struct node* create(){
    int d;
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));

    printf("Enter node data: ");
    scanf("%d",&d);

    //if data entered is -1 then terminate the program
    if(d == -1){
        return NULL;
    }
    //If the value is other than -1, then it gets stored in temp->data
    temp->data = d;

    //Now we are using recursion to build another node with same create() function
    printf("For left Subtree of %d\n",d);
    temp->left = create();

    printf("For right Subtree %d\n",d);
    temp->right = create();

    //We need to return the address of the new node
    return temp;
}
void inorder(struct node* root){
    if(root == NULL){
        printf("Binary Tree is Empty\n");
    }
    else{
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}