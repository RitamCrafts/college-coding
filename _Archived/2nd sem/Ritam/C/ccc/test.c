#include <stdio.h>
struct student{
    int roll;
    char name[20];
    float marks;
};
int main(){
    struct student s[3];
    //input struct
    int i;
    for(i=0; i<3;i++){
        printf("Enter roll:");
        scanf("%d",&s[i].roll);
        getchar();
        printf("Enter name:");
        fgets(s[i].name, sizeof(s[i].name), stdin);
        printf("Enter marks:");
        scanf("%f",&s[i].marks);
    }
    for(i=0;i<3;i++){
        printf("Student %d\n",i+1);
        printf("Name=%s\n",s[i].name);
        printf("Roll=%d\n",s[i].roll);
        printf("Name=%.2f\n\n",s[i].marks);
    }
    return 0;
}