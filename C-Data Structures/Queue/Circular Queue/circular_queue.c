//Stack implementation using static array
#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 5 //Preprocessor macro

void insert(int);
void delete(void);
void display(void);

int cqueue[CAPACITY], front=-1, rear=-1;

int main(){
    int ch;
    while(ch != 4){
        printf("\nQueue using Array Operations\n");
        printf("1.Insert\n2.Delete\n3.display\n4.Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch){
            case 1: int ele;
                    printf("Enter element: ");
                    scanf("%d",&ele);
                    insert(ele);
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
void insert(int ele){

    //First Element insertion
    if(front==-1 && rear==-1){
        front = rear = 0;
        cqueue[rear] = ele;
    }

    //When queue is FULL
    // else if(front == rear+1 || rear == CAPACITY-1){
    //     printf("\nQueue is Full\n");
    // }

    //When there is empty space in front of rear, after a complete cycle
    else if(rear==CAPACITY-1){
        rear = 0;
        cqueue[rear] = ele;
    }

    //When one or more elements are already present, normal condition
    else{
        rear++;
        cqueue[rear] = ele;
    }

    // else
    // {
    //     rear=(rear+1)%CAPACITY;       // rear is incremented
    //     cqueue[rear]=ele;             // assigning a value to the queue at the rear position.
    // }

}
void delete(){
    //When queue is EMPTY
    if(front==-1 && rear == -1){
        printf("\nQueue is Empty\n");
    }
    //When front and rear are at same position
    else if(front == rear){
        printf("\nelement %d deleted successfully\n", cqueue[front]);
        front = rear = -1;
    }
    // //When front completes a cycle
    // else if(front == CAPACITY-1){
    //     printf("\nelement %d deleted successfully\n", cqueue[front]);
    //     front = 0;
    // }
    // //For normal deletion
    // else{
    //     printf("\nelement %d deleted successfully\n", cqueue[front]);
    //     front ++;
    // }
    else
    {
        printf("\nThe dequeued element is %d", cqueue[front]);
        front=(front+1)%CAPACITY;
    }
}
void display(){
    //When queue is EMPTY
    if(front==-1 && rear == -1){
        printf("\nQueue is Empty\n");
    }
    else if(front == rear+1){
        for(int i=0; i<rear; i++){
            printf("%d-->",cqueue[i]);
        }
        for(int i=front; i<+CAPACITY-1; i++){
            printf("%d-->",cqueue[i]);
        }printf("\n");
    }
    else{
        for(int i=front; i<=rear; i++){
            printf("%d-->",cqueue[i]);
        }printf("\n");
    }
}