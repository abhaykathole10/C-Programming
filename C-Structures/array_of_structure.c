#include<stdio.h>

int main(){
    struct student
        {
            int sr;
            char name[20];
            int marks;
        };

    struct student s[3];
    int i;

    printf("Enter the sr, name, marks of students");

    for(i = 0 ; i < 3 ; i ++)
        {
            scanf("%d%s%d", &s[i].sr, &s[i].name, &s[i].marks);
        }

    for(i = 0 ; i < 3 ; i ++)
        {
            printf("Sr: %d Name: %s Marks: %d\n", s[i].sr, s[i].name, s[i].marks);
        }
    return 0;
}


