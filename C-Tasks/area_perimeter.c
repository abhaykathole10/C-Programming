//Code to calculate area and perimeter using pointers
#include<stdio.h>

void areaperi(int, float*, float*);

int main(){
    int r;
    float area, peri;

    printf("Enter radius of the circle: ");
    scanf("%d",&r);

    areaperi(r, &area, &peri);

    printf("Area of circle = %f\n",area);
    printf("Perimeter of circle = %f\n",peri);

    return 0;
}

void areaperi(int r , float *a, float *p){
    *a = 3.14 * r * r;
    *p = 2 * 3.14 * r;
}

