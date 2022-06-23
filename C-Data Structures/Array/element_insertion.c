//Inserting an element into the array at specific location
#include<stdio.h>
int main(){
    int a[50];

    int i,n;
    int new,loc;

    printf("Enter size: ");
    scanf("%d",&n);

    printf("Enter %d elements\n",n);

    //Writing Array elements
    for(i=0 ; i < n ; i++)
        {
            printf("Enter number: ");
            scanf("%d",&a[i]);
        }

    //Reading array elements
    for(i=0 ; i < n ; i++)
        {
            printf("%d\n",a[i]);
        }

    //Reading the 'number'
    printf("Enter number you want to insert: ");
    scanf("%d",&new);

    //Reading the location
    printf("Enter location: ");
    scanf("%d",&loc);

    //Traversing till the loc and at the same time shifting the elements by one
    for (i = n-1 ; i > loc; i--)
        {
            a[i+1] = a[i];
        }

    //Increasing the size of array by One
    n = n+1;

    //Assigning 'new' element to the "loc"
    a[loc] = new;

    //Printing Array
    for(i = 0 ; i < n ; i++)
    {
        printf("%d\n",a[i]);
    }

    return 0;
}
