#include<stdio.h>
int main(){

    //Declaring an array of size 10
    int a[10];

    int i,n;

    printf("Enter number of elements you want: ");
    scanf("%d",&n);

    //Writing
    for(i=0 ; i < n ; i++)
        {
            printf("Enter element: ");
            scanf("%d",&a[i]);
        }

    //Reading
    for(i=0 ; i < n ; i++)
        {
            printf("%d\t",a[i]);
        }
    return 0;
}