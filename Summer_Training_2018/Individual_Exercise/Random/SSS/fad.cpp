#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define M 80

struct chezhu
{
    char ID[20];//车主身份证号码
    char name[20];//会员名
    char nick[20];//昵称
    int sex;//性别
    char career[10];//职业
    double driving,year;//驾龄，车龄
} cz[M];

struct jiache
{
    char brand[10],color[10];//车辆品牌，车款，颜色
    int ck;
} jc[M];

void dengjichezhuxinxi(struct chezhu cz[])//车主信息
{
    do
    {
        int i=strlen(cz.ID);
        printf("请输入您的身份证号:");
        scanf("%s",&cz.ID);
        if(i!=18)
            printf("输入错误请重新输入");
        else
            check=true;

    }
    while(!check);
    do
    {
        printf("请输入驾龄:");
        scanf("%ld",&cz.driving);
        if(cz.driving<=0)
            printf("输入错误请重新输入");
        else
            check=true;
    }
    while(!check);
    printf("请输入会员名:");
    scanf("%s",&cz.name);
    printf("请输入昵称:");
    scanf("%s",&cz.nick);
    printf("请输入性别(1为男,2为女):");
    scanf("%d",&cz.sex);
    printf("请输入职业:");
    scanf("%s",&cz.career);
    printf("请输入年龄:");
    scanf("%ld",&cz.year);
}

void jiache(struct jiache jc[])
{
    printf("请输入车辆信息:");
    scanf("%s%d%s",&jc.brand&jc.ck&jc.color);
}
void save()//车友信息以文件形式储存
{
    FILE *fp;
    fp=fopen("G:\\cheyou","wb");
    if(fp==0)
    {
        printf("file error\n");
        exit(1);
    }
    fwrite(cz,sizeof(cz),1,fp);
    fwrite(jc,sizeof(jc),1,fp);
    fclose(fp);
}

int main()
{

    return 0;
}
