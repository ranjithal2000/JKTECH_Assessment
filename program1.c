#include<stdio.h>
#include<stdlib.h>
struct student
{
    char name[20];
    int age;
};
void write()
{
    FILE *fp1;
    fp1=fopen("one.txt","w");
    if(fp1==NULL)
    {
        printf("file does not exist");
    }
    struct student input1={"ranju",22};
    fwrite(&input1,sizeof(struct student),1,fp1);
    if(fwrite!=0)
        printf("contents are written successfully\n");
    else
        printf("error writing file");
    fclose(fp1);
}
void read()
{
    struct student stu;
    FILE *fp2;
    fp2=fopen("one.txt","r");
    if(fp2==NULL)
    {
        printf("file does not exist");
    }
    while(fread(&stu,sizeof(struct student),1,fp2))
        printf("student details are\n");
        printf("name=%s\nage=%d\n",stu.name,stu.age);
    fclose(fp2);
    return 0;
}
int main()
{
    write();
    read();
}
