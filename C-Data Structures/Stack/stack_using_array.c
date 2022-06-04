//Stack implementation using static array
#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 5 //Preprocessor macro

void push(void);
int pop(void);
int isEmpty(void);
int isFull(void);
void display(void);
void peek(void);

int stack[CAPACITY], top=-1;

int main(){
    int ch;
    while(ch != 5){
        printf("\nStack using Array Operations using Array\n");
        printf("1.push\n2.pop\n3.display\n4.peek\n5.Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch){
            case 1: push();
                    break;
            case 2: int p = pop();
                    if(p==0){
                        printf("Stack is Empty\n");
                    }else{
                        printf("\n%d popped successfully\n",p);
                    }
                    break;
            case 3: display();
                    break;
            case 4: peek();
                    break;
            case 5: printf("Thank You\n");
                    exit(0);
                    break;
            default: printf("Inavlid input\n");
        }
    }

}

void push(){
    int ele;

    printf("Enter Element: ");
    scanf("%d",&ele);

    if(isFull()){
        printf("Stack Overflow\n");
    }else{
        top++;
        stack[top] = ele;
        printf("\n%d pushed successfully!\n", ele);
    }
}

int pop(){
    if(isEmpty()){
        return 0;
    }else{
        return stack[top--];
    }
}

void display(){
    if(isEmpty()){
        printf("Stack is Empty\n");
    }
    else{
            printf("\nThe stack elements are: ");
            int i;
            for(i=0; i<=top; i++){
                printf("%d  ",stack[i]);
            }
            printf("\n");
        }
}

void peek(){
    if(isEmpty()){
        printf("Stack is Empty\n");
    }else{
        printf("\nPeek element is %d\n", stack[top]);;
    }
}

int isEmpty(){
    if(top == -1){
        return 1;
    }else{
        return 0;
    }
}
int isFull(){
    if(top == CAPACITY-1){
        return 1;
    }else{
        return 0;
    }
}