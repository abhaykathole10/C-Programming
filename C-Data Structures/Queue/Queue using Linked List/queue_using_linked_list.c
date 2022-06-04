//Stack implementation using static array
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* link;
};

struct node *front, *rear;

void insert(void);
void delete(void);
void display(void);


int main(){
    int ch;
    while(ch != 4){
        printf("\nQueue using Array Operations\n");
        printf("1.Insert\n2.Delete\n3.display\n4.Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch){
            case 1: insert();
                    break;
            case 2: delete();
                    break;
            case 3: display();
                    break;
            case 4: printf("Thank You!\n");
                    exit(0);
                    break;
            default: printf("Invalid input\n");
        }
    }
}
void insert(){
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));

    if(temp == NULL){
        printf("Overflow\n");
    }
    else{
        printf("Enter data: ");
        scanf("%d", &temp->data);

        if(front == NULL){
            front = temp;
            rear = temp;
            front->link = NULL;
            rear->link = NULL;
        }
        else{
            rear->link = temp;
            rear = temp;
            rear->link = NULL;
        }
    }
}
void delete(){
    struct node* temp;
    if(front == NULL){
        printf("Underflow\n");
    }
    else{
        temp = front;
        front = front->link;
        free(temp);
    }
}
void display(){
    struct node* temp;
    temp = front;
    if(front == NULL){
        printf("\nQueue is Empty\n");
    }
    else{
        printf("\nQueue: ");
        while(temp != NULL){
            printf("%d --> ",temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
}