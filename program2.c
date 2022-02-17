#include<stdio.h>
#include<stdlib.h>
struct student
{
    char name[20];
    int age;
};
void write()
{
    struct student stu[2];
    FILE *fp1;
    fp1=fopen("one.txt","w");
    if(fp1==NULL)
    {
        printf("file does not exist");
    }
    else
    {
    for(int i=0;i<2;i++)
    {
    fflush(stdin);
     printf("enter the student name \n");
     scanf("%s",stu[i].name);
     printf("enter student age\n");
     scanf("%d",&stu[i].age);
     fprintf(fp1,"%s\n%d\n",&stu[i].name,&stu[i].age);
    }
    }
    printf("content successfully written\n");
fclose(fp1);
}
void read()
{
    struct student stu[2];
    FILE *fp2;
    fp2=fopen("one.txt","r");
    if(fp2==NULL)
    {
        printf("file does not exist");
    }
    else
    {
    printf("student details are are:\n");
    for(int i=0;i<2;i++)
    {
        printf("Student Name:%s\n", stu[i].name);
        printf("Student Age:%d\n",stu[i].age);
        fscanf(fp2,"%s %d", &stu[i].name,&stu[i].age);
    }
    }
    fclose(fp2);
}
int main()
{
    write();
    read();
}
