#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
const int N=605;
int n,m;
char ss[N];
int h[N];
int sta[N],top;
int read ()
{
    char ch=getchar();int x=0;
    while (ch<'0'||ch>'9') ch=getchar();
    while (ch>='0'&&ch<='9') {x=x*10+ch-'0';ch=getchar();}
    return x;
}
inline void out(int x)
{
    int len=0;char ss[10];
    if(!x){putchar('0');return;}
    while(x)ss[len++]=x%10,x/=10;
    while(len)putchar(ss[--len]+48);
}
int ans[N][N];

int main()
{
    n=read();m=read();
    for (int u=1;u<=n;u++)
    {
        scanf("%s",ss+1);
        top=0;
        for (int i=1;i<=m+1;i++)
        {
            h[i]=ss[i]=='1'?h[i]+1:0;
            //printf("%d ",h[i]);
            while (top>0&&h[sta[top]]>h[i])
            {
                //printf("%d %d %d\n",max(h[sta[top-1]],h[i]),h[sta[top]]+1,i-sta[top-1]-1);
                ans[max(h[sta[top-1]],h[i])+1][i-sta[top-1]-1]++;
                ans[h[sta[top]]+1][i-sta[top-1]-1]--;
                top--;
            }
            while (top>0&&h[sta[top]]==h[i]) top--;
            sta[++top]=i;
        }
    }
    for (int u=1;u<=n;u++)
        for (int i=1;i<=m;i++)
            ans[u][i]=ans[u][i]+ans[u-1][i];
    for (int u=1;u<=n;u++)
    {
        int sum=0,lalal=0;
        for (int i=2;i<=m;i++)
        {
            lalal=lalal+ans[u][i];
            sum=sum+ans[u][i]*i;
        }
        for (int i=1;i<=m;i++)
        {
            ans[u][i]=ans[u][i]+sum;
            sum=sum-lalal-ans[u][i+1];
            lalal=lalal-ans[u][i+1];
        }
        /*for (int i=1;i<=m;i++)
        {
            for (int j=i+1;j<=m;j++)
                ans[u][i]=ans[u][i]+ans[u][j]*(j-i+1);
        }*/
    }
    for (int u=1;u<=n;u++)
    {
        for (int i=1;i<=m;i++)
        {
            out(ans[u][i]);
            putchar(' ');
        }
        putchar('\n');
    }
    return 0;
}
