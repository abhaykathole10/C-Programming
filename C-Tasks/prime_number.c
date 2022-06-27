//To check if a number is prime or not
#include<stdio.h>

int main(){

        while(1)
        {
                int num,i;
                printf("Enter number: ");
                scanf("%d",&num);

                if(i==1)
                    printf("Neither Prime nor Unprime");

                i = 2;

                while(i <= num-1)
                {
                    if(num % i == 0)
                    {
                        printf("Not Prime\n");
                        break;
                    }
                    i++;
                }

                if( i == num)
                {
                    printf("Prime\n");
            }

        }




}


