#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* create(int);
void insert(struct node*, int);

int main(){
    struct node* root = NULL;
    insert(root, 50);
    insert(root, 40);
    insert(root, 60);
    insert(root, 30);
    insert(root, 25);
    insert(root, 55);
}
void insert(struct node* root, int item){
    if(root == NULL){
        root = create(item);
    }
    else{
        struct node* temp;
        temp = create(item);
        if(root->data > temp->data){
            root->left = temp;
        }
        else{
            root->right = temp;
        }
    }
}
//Create() functions creates a new node in heap and returns the address of the new node
struct node* create(int data){
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;        //returning the address of the new node(temp)
}

