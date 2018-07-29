#include<cstdio>
#include<cstring>

using namespace std;
#define LL long long
#define MAXN 100000000
char str[MAXN+10];
char str1[MAXN+10];
LL  next[MAXN+10];
bool flag = false;

void getStr(LL n)
{
    for(LL i=0; i<n; i++)
        str1[i] = str[i];
    str1[n] = '\0';
}

void kmp_pre(char x[], LL len, LL next[])
{
    LL i,j;
    j = next[0] = -1;
    i=0;
    while(i < len)
    {
        while(-1 != j && x[i] != x[j])
            j=next[j];

        next[++i] = ++j;
    }
}

LL  KMP_Count(char x[], LL m, char y[], LL n)
{
    LL ans = 0;
    LL i,j;
    kmp_pre(x,m,next);
    i=j=0;
    while(i<n)
    {
        while(-1!=j && y[i]!=x[j] )
            j=next[j];
            i++;
            j++;
        if(j>=m)
        {
            ans++;
            j=0;
        }
    }
    return ans;
}

int main()
{
    gets(str);

    do
    {
        LL str_len = strlen(str);
        for(LL i=1; i<str_len; i++)
        {
            if(str_len % i != 0)
                continue;
            getStr(i);
            LL str1_len = strlen(str1);
            LL cnt = KMP_Count(str1,str1_len, str, str_len);
            if(cnt * str1_len == str_len)
            {
                printf("%d\n",cnt);
                flag = true;
                break;
            }
        }
        if(!flag)
            printf("1\n");
        gets(str);
    }while(strcmp(str,"."));

    return 0;
}

