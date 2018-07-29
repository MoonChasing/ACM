#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

const int maxn =100000;
char * suff[maxn+1];

int pstrcmp(const void *p, const void *q)
{
    return strcmp(*(char**)p,*(char**)q);
}

int comlen_suff(char * p, char * q)
{
    int len = 0;
    while(*p && *q && *p++ == *q++)
    {
        ++len;
        if(*p == '#' || *q == '#')
        {
            break;
        }
    }
    int count = 0;
    while(*p)
    {
        if(*p++ == '#')
        {
            ++count;
            break;
        }
    }
    while(*q)
    {
        if(*q++ == '#')
        {
            ++count;
            break;
        }
    }
    if(count == 1)
        return len;
    return 0;
}

void LCS_suffix(char * X, int xlen, char * Y, int ylen)
{
    int suf_index, maxlen, maxindex;
     suf_index = maxlen = maxindex = 0;

    int len_suff = xlen + ylen + 1;
    char * arr = new char [len_suff + 1];  /* 将X和Y连接到一起 */
    strcpy(arr,X);
    arr[xlen] = '#';
    strcpy(arr + xlen + 1, Y);

    for(int i = 0; i < len_suff; ++i)  /* 初始化后缀数组 */
    {
        suff[i] = & arr[i];
    }

    qsort(suff, len_suff, sizeof(char *), pstrcmp); //后缀数组进行排序

    for(int i = 0; i < len_suff-1; ++i)
    {
        int len = comlen_suff(suff[i],suff[i+1]);
        if(len > maxlen)
        {
            maxlen = len;
            suf_index = i;
        }
    }
    printf("%d",maxlen);
}

int main()
{
    char x[maxn+1], y[maxn+1];
    gets(x);
    gets(y);
    LCS_suffix(x,strlen(x),y,strlen(y));
    return 0;
}

#include<cstdio>
using namespace std;
int main()
{
    int i,b,n,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&b);
        for(i=0;i<9973;i++)
           if((((b%9973)*i)%9973-n)%9973==0)
           {
             // printf("%d  ",b*i-n);
              break;
           }
        printf("%d\n",i);
    }
    return 0;
}
