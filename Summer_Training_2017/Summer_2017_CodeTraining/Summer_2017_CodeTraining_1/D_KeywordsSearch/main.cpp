#include <iostream>
#include<cstdio>
#include<cstring>

using namespace std;

#define LL long long

const int N = 10000;
const int MAXLEN = 50;
char keywords[N+1][MAXLEN+1];
char str[1000010];

void kmp_pre(char x[], int len, int next[])
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

bool  KMP_Count(char x[], int m, char y[], LL n)
{
    LL ans = 0;
    LL i,j;
    int next[100];
    kmp_pre(x,m,next);
    i=j=0;
    while(i<n)
    {
        while(-1!=j && y[i]!=x[j] )
            j=next[j];
            i++;
            j++;
        if(j>=m)
            return true;
    }
    return false;
}

int main()
{

    int n;
    scanf("%d",&n);
    while(n--)
    {
        int time;
        int cnt = 0;
        scanf("%d",&time);
        getchar();
        for(int i=0; i<time;i++)
            gets(keywords[i]);
        gets(str);
        int len = strlen(str);
        for(int i=0; i<time;i++)
        {
            if(KMP_Count(keywords[i],strlen(keywords[i]),str,len))
                cnt++;
        }

    printf("%d",cnt);
    }
    getchar();
    return 0;
}
