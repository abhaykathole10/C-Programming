#include<stdio.h>

void argentina();
void brazil();

int main(){
    printf("I am home\n");
    argentina();
    printf("Back home\n");
    return 0;
}
void argentina(){
    printf("I am in Argentina\n");
    brazil();
}
void brazil(){
    printf("I am in brazil\n");
}

