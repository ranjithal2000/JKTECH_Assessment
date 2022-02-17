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
    for(int i=0;i<2;i++)
    {
    fflush(stdin);
     printf("enter the student name \n");
     scanf("%s",stu[i].name);
     printf("enter student age\n");
     scanf("%d",&stu[i].age);
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
    while(fread(&stu,sizeof(struct student),1,fp2))
    printf("student details are are:\n");
    for(int i=0;i<2;i++)
    {
        printf("student name:%s \n", stu[i].name);
        printf("student age: name:%d \n",stu[i].age);
    }
    fclose(fp2);
}
int main()
{
    write();
    read();
}
