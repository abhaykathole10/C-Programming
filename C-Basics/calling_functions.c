#include<stdio.h>

//Function prototype
void argentina();
void brazil();

//main() function
int main(){
    printf("I am home\n");

    //Calling function 1
    argentina();

    printf("Back home\n");

    return 0;
}

//Function 1
void argentina(){

    printf("I am in Argentina\n");

    //Calling function 2
    brazil();
}

//Function 2
void brazil(){

    printf("I am in brazil\n");
}

