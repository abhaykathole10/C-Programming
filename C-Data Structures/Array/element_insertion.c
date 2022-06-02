//Inserting an element into the array at specific location
#include<stdio.h>
int main(){
    int a[50];
    int i,n;
    int new,loc;
    printf("Enter size: ");
    scanf("%d",&n);
    printf("Enter %d elements\n",n);

    for(i=0 ; i < n ; i++)
        {
            printf("Enter number: ");
            scanf("%d",&a[i]);
        }
    for(i=0 ; i < n ; i++)
        {
            printf("%d\n",a[i]);
        }
    printf("Enter number you want to insert: ");
    scanf("%d",&new);
    printf("Enter location: ");
    scanf("%d",&loc);

    for (i=n-1 ; i > loc; i--)
        {
            a[i+1] = a[i];
        }
    n = n+1;
    a[loc] = new;

    for(i=0 ; i < n ; i++)
    {
        printf("%d\n",a[i]);
    }

    return 0;
}
