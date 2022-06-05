#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* root = NULL;

void insertion(struct node);
void deletion(void);
void search(void);

void inorder(struct node*);
void preorder(struct node*);
void postorder(struct node*);

int main(){
    int ch;

    while(ch!=7){
    printf("\nBinary Search Tree\n");
    printf("1.insertion\n2.deletion\n3.inorder\n4.preorder\n5.postorder\n6.search\n7.Quit\n");
    printf("Enter your choice: ");
    scanf("%d",&ch);
        switch(ch){
            case 1: struct node* temp;
                    temp = (struct node*)malloc(sizeof(struct node));
                    printf("Enter data: ");
                    scanf("%d",&temp->data);

                    insertion(temp->data);
                    break;
            case 2: deletion();
                    break;
            case 3: printf("\nInorder Traversal: ");
                    inorder(root);
            case 4: printf("\nPreorder Traversal: ");
                    preorder(root);
            case 5: printf("\nPostorder Traversal: ");
                    postorder(root);
            case 6: search();
                    break;
            case 7: printf("Thank You\n");
                    exit(0);
                    break;
        }
    }
}

void insertion(struct node temp){

    if(root == NULL){
        root = temp;
    }
    else{

    }
}
void deletion(){

}
void search(){

}
//INORDER LEFT->ROOT->RIGHT
void inorder(struct node* root){
    if(root == NULL){
        return;
    }
    else{
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
//PREORDER ROOT->LEFT->RIGHT
void preorder(struct node* root){
    if(root == NULL){
        return;
    }
    else{
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
//POSTORDER LEFT->RIGHT->ROOT
void postorder(struct node* root){
    if(root == NULL){
        return;
    }
    else{
        preorder(root->left);
        preorder(root->right);
        printf("%d ",root->data);
    }
}
