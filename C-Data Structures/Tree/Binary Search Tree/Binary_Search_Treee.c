#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* create(int);
struct node* insert(struct node*, int);

int main(){
    struct node* root = NULL;   //this root is local variable of main function
    root = insert(root, 50);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 30);
    root = insert(root, 25);
    root = insert(root, 55);
}
struct node* insert(struct node* root, int item){
    //If the tree is empty
    if(root == NULL){
        //Create a new node and return the address to root which is empty
        root = create(item);
        //Modifying his root won't modify our main function root
        //Because it is local to insert function
        //So we will have to return the address of this root to the main function root
        //return type of insert will change from void to struct node*
        return root;
        //There is also another way to deal with this, i.e pointer to pointer method, see below
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
    struct node* newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;        //returning the address of the new node(temp)
}




/*
"Pointer to Pointer method
This method is quite tricky to understand"

int main(){
    struct node* root = NULL;

    "This time we will be passing address of our main function root"
    "So we will be modifying out main root all the time, and not the local roots"

    insert(&root, 50);
    insert(&root, 40);
    insert(&root, 60);
    insert(&root, 30);
    insert(&root, 25);
    insert(&root, 55);
}

"I have changed name from root to rootPtr for better understanding"
"Even though the names are different, they points to same root"

void insert(struct node** rootPtr, int item){

    "First dereferencing the **root"

    if(*rootPtr == NULL){
        *rootPtr = create(item);

        "return type of insert will still remain void"
        "There is also another way to deal with this, i.e pointer to pointer method, see below"
    }
*/
