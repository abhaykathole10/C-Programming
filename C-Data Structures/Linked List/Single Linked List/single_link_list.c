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
    int ch;
    while(ch != 7)
    {
        printf("\nSingle Link list operations\n");
        printf("1.Append\n2.Add at begin\n3.Add at after\n4.Length\n5.Display\n6.Delete\n7.Quit\n");

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
            case 7: printf("Thank You");
                    exit(0);
                    break;
            default: printf("Invalid input\n");
        }

    }
}
void append(){
    //Creating a temporary pointer of struct node type
    struct node* temp;
    //Assigning memory address to the temp pointer, type casting to struct node type
    temp = (struct node*)malloc(sizeof(struct node));
    //Taking node data from the user
    printf("Enter data: ");
    scanf("%d", &temp->data);
    //Pointing the link to NULL for now
    temp->link = NULL;
    //Checking if root is NULL i.e no list exist, temp will be the first node
    if(root == NULL){
        root = temp;
    }
    //If already nodes are present then first traverse to the last node using pointer p
    else{
        struct node* p;
        p = root;
        while( p->link != NULL){
            p = p->link;
        }
        //Storing address of temp to the link of p hence, temp is connected to the list
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
        printf("\nThe list is: ");
        while(temp != NULL){
            printf("%d-->",temp->data);
            temp = temp->link;
        }
        printf("\n\n");
    }
}
void addatbegin(void){
    struct node* temp;

    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter node data: ");
    scanf("%d", &temp->data);

    temp->link = NULL;

    if(root == NULL){
        root = temp;
    }else{
         temp->link = root;
         root = temp;
    }
}
void addatafter(void){
    struct node *temp,*p;
    int loc,s,i=1;
    s = length();
    printf("Enter location: ");
    scanf("%d", &loc);

    if(loc > s){
        printf("Not possible, there are only %d nodes", s);
    }else{
        temp = (struct node*)malloc(sizeof(struct node));
        printf("Enter node data: ");
        scanf("%d", &temp->data);
        temp->link = NULL;
        p = root;
        while(i != loc){
            p = p->link;
            i++;
        }
        temp->link = p->link;
        p->link = temp;
    }
}
void delete(void){
    int loc,i=1;
    int len = length();

    struct node *temp;

    //Getting the location of the node that is to be deleted
    printf("Enter location of node to delete: ");
    scanf("%d", &loc);

    //Checking if the location entered is out of scope
    if(loc > len){
        printf("Impossible, there are only %d nodes", len);
    }
    //If the location entered is the for the first node
    else if(loc == 1){
        temp = root;
        root = temp->link;
        temp->link = NULL;
        free(temp);
    }
    //If the location entered is for the middle node or the last node
    else{
        struct node *p, *q;
        p = root;
        int i=1;

        while(i != loc-1){
            p = p->link;
            i++;
        }
        q = p->link;
        p->link = q->link;
        q->link = NULL;

        free(q);
    }
}

