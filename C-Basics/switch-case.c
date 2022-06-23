#include<stdio.h>

int main(){

    //Declaring literal ex. int ch
    char ch;

    printf("Enter a chracter: ");
    scanf("%c",&ch);

    switch(ch) {
        //"Case insensitive" i.e 'a' and 'A' are same
        case 'a':
        case 'A':
            printf("You pressed a\n");
            break;

        case 'b':
            printf("You pressed b\n");
            break;

        case 'c':
            printf("You pressed c\n");
            break;

        //Default method is optional, if not present program will just return
        default:
            printf("Invalid input");
    }
    return 0;
}

