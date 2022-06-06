#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//STRUCTURE DEFINITION
struct node{
    int data;
    struct node *left, *right;
};

//PROTOTYPE DECLARATION
struct node* create(int);
struct node* insert(struct node*, int);
struct node* delete(struct node*, int);
struct node* findMin(struct node*);
bool search(struct node*, int);

void inorder(struct node*);
void preorder(struct node*);
void postorder(struct node*);

//MAIN() FUNCTION
int main(){

    struct node* root = NULL;   //this root is local variable of main function
    root = insert(root, 50);
    insert(root, 40);
    insert(root, 60);
    insert(root, 30);
    insert(root, 45);
    insert(root, 55);

    printf("\nInorder Traversal: ");
    inorder(root);
    printf("\nPreorder Traversal: ");
    preorder(root);
    printf("\nPostorder Traversal: ");
    postorder(root);

    printf("\n\nInorder Traversal before deletion(40): ");
    inorder(root);

    root = delete(root,40);

    printf("\n");
    printf("Inorder Traversal after deletion: ");
    inorder(root);

    int ele;
    printf("\nEnter the element to be searched: ");
    scanf("%d", &ele);
    if(search(root,ele)){
        printf("Found\n");
    }
    else{
        printf("Not Found\n");
    }
}

//INSERT() FUNCTION
struct node* insert(struct node* root, int item){
    //If the tree is empty
    if(root == NULL){
        //Create a new node and return the address to root which is empty
        root = create(item);
        /*
        Modifying his root won't modify our main function root
        Because it is local to insert function
        So we will have to return the address of this root to the main function root
        return type of insert will change from void to struct node*
        return root; First return was here
        There is also another way to deal with this, i.e pointer to pointer method, see below
        */
    }
    else if(item < root->data){
        root->left = insert(root->left, item);
    }
    else{
        root->right = insert(root->right, item);
    }
    //root->left and root->right will act as root for each iteration
    return root;
}

//Create() functions creates a new node in heap and returns the address of the new node
struct node* create(int data){
    struct node* newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;     //returning the address of the new node(temp)
}

//SEARCH FUNCTION
bool search(struct node* rootPtr, int key){
    if(rootPtr == NULL) return false;
    else if(rootPtr->data == key) return true;
    else if(key < rootPtr->data) return search(rootPtr->left,key);
    else return search(rootPtr->right,key);
}

struct node* findMin(struct node* root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

//DELETE FUNCTION
struct node* delete(struct node* root, int key){
    if(root == NULL) return root;
    else if(key<root->data) root->left = delete(root->left, key);
    else if(key>root->data) root->right = delete(root->right, key);
    else{
        //Case 1: No child
        if(root->left == NULL && root->right == NULL){
            free(root);
            root = NULL;
        }
        //Case 2: Only one child node
        else if(root->left == NULL){
            struct node* temp = root;
            root = root->right;
            free(root);
        }
        else if(root->right == NULL){
            struct node* temp = root;
            root = root->left;
            free(root);
        }
        //Case 3: Two children nodes
        else{
            struct node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = delete(root->right,temp->data);
        }
    }
    return root;
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
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
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
