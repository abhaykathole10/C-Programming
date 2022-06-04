//Stack implementation using static array
#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 5 //Preprocessor macro

void insert(void);
void delete(void);
void display(void);

int queue[CAPACITY], front=0, rear=0;

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
    if(rear == CAPACITY){
        printf("\nQueue is Full\n");
    }
    else{
        int ele;
        printf("Enter element: ");
        scanf("%d", &ele);

        queue[rear] = ele;
        rear++;
    }
}
void delete(){
    if(front==rear){
        printf("\nQueue is Empty\n");
    }
    else{
        printf("\n%d deleted successfully\n", queue[front]);
        for(int i=front; i<rear; i++){
            queue[i] = queue[i+1];
        }
        rear--;
    }
}
void display(){
    if(front==rear)
    {
        printf("\nQueue is Empty\n");
    }
    else
    {
        printf("\nThe queue: (front)  ");
        for(int i=front; i<rear; i++){
            printf("%d  ",queue[i]);
        }
        printf("(rear)\n");
    }
}
//front always stays at 0th index, it doesn't move after deletion
//the elements get shifted by one position till the rear