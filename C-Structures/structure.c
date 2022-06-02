#include<stdio.h>

struct emp{
    int sr;
    char name[20];
    float salary;
};

void main(){

    struct emp e = {1, "Abhay", 50000};

    printf("Sr: %d\n",e.sr);
    printf("Name: %s\n",e.name);
    printf("Salary: %f\n",e.salary);

}
