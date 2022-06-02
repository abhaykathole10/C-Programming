#include<stdio.h>

int main(){
    //Declaring first array
    int a[10];
    int i,n;

    printf("Number of elements in 1st array: ");
    scanf("%d",&n);

    for(i=0 ; i < n ; i++)
        {
            printf("Enter 1st array elements: ");
            scanf("%d",&a[i]);
        }
    for(i=0 ; i < n ; i++)
        {
            printf("%d\t",a[i]);
        }

    //Declaring second array
    int b[10];
    int j,m;

    printf("\nNumber of elements in 2nd array: ");
    scanf("%d",&m);

    for(j=0 ; j < m ; j++)
        {
            printf("Enter 2nd array elements: ");
            scanf("%d",&b[j]);
        }
    for(j=0 ; j < m ; j++)
        {
            printf("%d\t",b[j]);
        }

    //Location for insertion
    int loc;

    printf("\nEnter location where you want to insert 2nd into 1st: ");
    scanf("%d",&loc);

    for(i = n-1 ; i >= loc ; i--)
        {
            a[i + m] = a[i];
        }
    for(j = 0 ; j < m; j++)
        {
            a[loc+j] = b[j];
        }
    for(i=0 ; i < n+m ; i++)
    {
        printf("%d\t",a[i]);
    }
    return 0;
}
