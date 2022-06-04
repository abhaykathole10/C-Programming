//Stack implementation using static array
#include <stdio.h>
#include <stdlib.h>
// #define CAPACITY 5 //Preprocessor macro

struct node{
    int data;
    struct node* link;
};
struct node* top = NULL;

void push(void);
void pop(void);
void display(void);
void peek(void);

// int stack[CAPACITY], top=-1;

int main(){
    int ch;
    while(ch != 5){
        printf("\nStack using Linked list Operations\n");
        printf("1.push\n2.pop\n3.display\n4.peek\n5.Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch){
            case 1: push();
                    break;
            case 2: pop();
                    break;
            case 3: display();
                    break;
            case 4: peek();
                    break;
            case 5: printf("Thank You!\n");
                    exit(0);
                    break;
            default: printf("Inavlid input\n");
        }
    }

}

void push(){
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));

    if(temp==NULL){
        printf("Stack Overflow\n");
    }
    else{
        printf("Enter node data: ");
        scanf("%d", &temp->data);

        if(top == NULL){
            temp->link = NULL;
            top = temp;
        }
        else{
            temp->link = top;
            top = temp;
        }
    }
}

void pop(){
    if(top == NULL){
        printf("\nStack is Empty\n");
    }
    else{
        struct node *temp;
        temp = top;
        top = top->link;
        free(temp);
    }
}

void display(){
    if(top == NULL){
        printf("\nStack is Empty\n");
    }else{
        struct node* temp;
        temp = top;
        printf("\nThe Stack\n");
        while(temp != NULL){
            printf("%d\n", temp->data);
            temp = temp->link;
        }
    }
    printf("\n");
}

void peek(){
    printf("\nThe peek element is %d\n", top->data);
}

