#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define M 80

struct chezhu
{
    char ID[20];//�������֤����
    char name[20];//��Ա��
    char nick[20];//�ǳ�
    int sex;//�Ա�
    char career[10];//ְҵ
    double driving,year;//���䣬����
} cz[M];

struct jiache
{
    char brand[10],color[10];//����Ʒ�ƣ������ɫ
    int ck;
} jc[M];

void dengjichezhuxinxi(struct chezhu cz[])//������Ϣ
{
    do
    {
        int i=strlen(cz.ID);
        printf("�������������֤��:");
        scanf("%s",&cz.ID);
        if(i!=18)
            printf("�����������������");
        else
            check=true;

    }
    while(!check);
    do
    {
        printf("���������:");
        scanf("%ld",&cz.driving);
        if(cz.driving<=0)
            printf("�����������������");
        else
            check=true;
    }
    while(!check);
    printf("�������Ա��:");
    scanf("%s",&cz.name);
    printf("�������ǳ�:");
    scanf("%s",&cz.nick);
    printf("�������Ա�(1Ϊ��,2ΪŮ):");
    scanf("%d",&cz.sex);
    printf("������ְҵ:");
    scanf("%s",&cz.career);
    printf("����������:");
    scanf("%ld",&cz.year);
}

void jiache(struct jiache jc[])
{
    printf("�����복����Ϣ:");
    scanf("%s%d%s",&jc.brand&jc.ck&jc.color);
}
void save()//������Ϣ���ļ���ʽ����
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
