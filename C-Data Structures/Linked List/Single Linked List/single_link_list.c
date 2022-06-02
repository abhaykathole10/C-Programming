#include <stdio.h>
#include <stdlib.h>

/*Structure declaration*/

struct node{
    int data;
    struct node* link;
};

struct node* root = NULL;

/*Length variable declaration (global)*/

int len;

/*Prototype declaration*/

void append(void);
void addatbegin(void);
void addatafter(void);
int length(void);
void display(void);
void delete(void);
void quit(void);

void main(){

    while(1)
    {
        int ch;

        printf("\nSingle Link list operations\n");
        printf("1. Append\n");
        printf("2. Add at begin\n");
        printf("3. Add at after\n");
        printf("4. Length\n");
        printf("5. Display\n");
        printf("6. Delete\n");
        printf("7. Quit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &ch);

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
}
void append(){

    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &temp->data);
    temp->link = NULL;

    if(root == NULL){
        root = temp;
    }
    else{
        struct node* p;
        p = root;
        while( p->link != NULL){
            p = p->link;
        }
        p->link = temp;
    }
}
int length(){
    int count = 0;
    struct node* temp;
    temp = root;

    while(temp != NULL){
        count ++ ;
        temp = temp->link;
    }
    return count;
}
void display(){

    struct node* temp;
    temp = root;

    if(temp == NULL){
        printf("List is Empty\n");
    }
    else{

        while(temp != NULL){
            printf("%d-->",temp->data);
            temp = temp->link; 
        }
        printf("\n\n");
    }
}
void addatbegin(void){

}
void addatafter(void){

}
void delete(void){

}
void quit(void){

}
