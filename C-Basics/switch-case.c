#include<stdio.h>

int main(){

    char ch;
    printf("Enter a chracter: ");
    scanf("%c",&ch);

    switch(ch) {
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
        default:
            printf("Invalid input");
    }
    return 0;
}

