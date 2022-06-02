#include<stdio.h>

int main(){
    int a,b,op;

    while(1)
    {
        printf("\nEnter 1st number: ");
        scanf("%d",&a);

        printf("Enter 2nd number: ");
        scanf("%d",&b);

        printf("1.add 2.sub 3.div 4.mul Enter operation: ");
        scanf("%d",&op);

        switch(op){
            case 1:
                    printf("Addition is %d", a+b);
                    break;

            case 2: printf("Substraction is %d", a-b);
                    break;

            case 3: printf("Division is %d", a/b);
                    break;

            case 4: printf("Multiplication is %d", a*b);
                    break;

            default: printf("Inavlid input");
        }

    }

    return 0;
}


