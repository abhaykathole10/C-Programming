#include<stdio.h>
int main(){
    int a[10];
    int i,n;

    printf("Enter number of elements you want: ");
    scanf("%d",&n);

    for(i=0 ; i < n ; i++)
        {
            printf("Enter element: ");
            scanf("%d",&a[i]);
        }
    for(i=0 ; i < n ; i++)
        {
            printf("%d\t",a[i]);
        }
    return 0;
}