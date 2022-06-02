#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

//declaring root to NULL initially
struct node* root = NULL;

/*Length variable declaration (global)*/
int len;

//Prototype declaration
void append(void);
void addatbegin(void);
void addatafter(void);
int length(void);
void display(void);
void delete(void);
void quit(void);

//main() function
int main(){

    while(1)
    {
        int ch;

        printf("\nDouble Linked list operations\n");
        printf("1. Append\n");
        printf("2. Add at begin\n");
        printf("3. Add at after\n");
        printf("4. Length\n");
        printf("5. Display\n");
        printf("6. Delete\n");
        printf("7. Quit\n");

        printf("\nEnter your choice: ");
        scanf("%d",&ch);

        switch(ch){
            case 1: append();
                    break;
            case 2: addatbegin();
                    break;
            case 3: addatafter();
                    break;
            case 4: len = length();
                    printf("\nLength of SLL is %d\n", len);
                    break;
            case 5: display();
                    break;
            case 6: delete();
                    break;
            case 7: quit();
                    break;
            default: printf("Invalid input\n");
        }
    }
    return 0;
}

//append() function definition
void append(){
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter node data: ");
    scanf("%d", &temp->data);
    temp->left = NULL;
    temp->right = NULL;

    if(root == NULL){
        root = temp;
    }else{
        struct node* p;
        p = root;
        while(p->right != NULL){
            p = p->right;
        }
        p->right = temp;
        temp->left = p;
    }
}

//atatbegin() function definition
void addatbegin(){
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter node data: ");
    scanf("%d", &temp->data);
    temp->left = NULL;
    temp->right = NULL;

    if(root == NULL){
        root = temp;
    }else{
        temp->right = root;
        root->left = temp;
        root = temp;
    }
}

//length() function definition
int length(){
    struct node* temp = root;
    int count = 0;

    while(temp != NULL){
        count++;
        temp = temp->right;
    }
    return count;
}

//display() function definition
void display(){
    struct node* temp = root;
    if(temp == NULL){
        printf("It is an empty list\n");
    }else{
        while(temp != NULL){
            printf("%d -> ",temp->data);
            temp = temp->right;
        }
    }
}