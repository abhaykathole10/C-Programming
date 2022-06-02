#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

//declaring root to NULL initially
struct node* root = NULL;

//Length variable declaration (global)
int len;

//Prototype declaration
void append(void);
void addatBegin(void);
void addAfter(void);
int length(void);
void display(void);
void delete(void);
void quit(void);

//main() function
int main(){

    while(1)
    {
        int ch;

        printf("\n\nDouble Linked list operations\n");
        printf("1. Append\n");
        printf("2. Add at begin\n");
        printf("3. Add at after\n");
        printf("4. Length\n");
        printf("5. Display\n");
        printf("6. Delete\n");
        printf("7. Quit\n");

        printf("Enter your choice: ");
        scanf("%d",&ch);

        switch(ch){
            case 1: append();
                    break;
            case 2: addatBegin();
                    break;
            case 3: addAfter();
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

//addatbegin() function definition
void addatBegin(){
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

//addafter() function definition
void addAfter(){
    struct node *temp, *p;
    int loc, s, i=1;

    printf("Enter location: ");
    scanf("%d",&loc);

    s = length();

    if(loc>s){
        printf("Invalid input, there are %d nodes", len);
    }else{
        temp = (struct node*)malloc(sizeof(struct node));

        printf("Enter node data: ");
        scanf("%d",&temp->data);
        temp->left = NULL;
        temp->right = NULL;

        p = root;
        while(i<loc){
            p = p->right;
            i++;
        }
        temp->right = p->right;
        p->right->left = temp;

        temp->left = p;
        p->right = temp;
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
        printf("\nThe list is: ");
        while(temp != NULL){
            printf("%d -> ",temp->data);
            temp = temp->right;
        }
    }
}

void delete(){

}

void quit(){

}