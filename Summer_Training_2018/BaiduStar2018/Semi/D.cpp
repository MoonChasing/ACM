#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#define maxn 2005
#define maxm 2000005
using namespace std;
typedef long long LL;
const LL mod=1000000007;
int k,n,m,lajibaidu;
int temp[10];
struct dat
{
    int p[10];
    void init()
    {
        for(int i=0;i<=k;i++)
            p[i]=temp[i];
    }
    dat(){}
}LaJiBaidu[maxm];

bool operator<(dat a,dat b)
{
    return a.p[1]<b.p[1];
}

vector<int> pp[10][maxn];
LL BaiDuLAJI[maxm];

int GoogleNB(int now,int val)
{
    if(now==k+1)
        return    LaJiBaidu[++lajibaidu].init(),1;
    int len=pp[now][val].size();
    for(int i=0;i<len;i++)
    {
        temp[now]=pp[now][val][i];
        GoogleNB(now+1,val);

    }
    return 1;
}

int cc(int i,int j)
{
    for(int t=1;t<=k;t++)
        if(LaJiBaidu[i].p[t]<=LaJiBaidu[j].p[t])
            return false;
    return true;
}
int main()
{
    int kiss;
    scanf("%d",&kiss);
    while(kiss--)
    {
        lajibaidu=0;
        scanf("%d%d",&k,&n);
        for(int i=1;i<=k;i++)
            for(int j=1;j<=n;j++)
                pp[i][j].clear();

        for(int i=1;i<=k;i++)
        {
            for(int j=1;j<=n;j++)
            {
                int x;
                scanf("%d",&x);
                pp[i][x].push_back(j);
            }
        }

        for(int i=1;i<=n;i++)
            GoogleNB(1,i);

        sort(LaJiBaidu+1,LaJiBaidu+1+lajibaidu);

        LL ans=0;
        for(int i=1;i<=lajibaidu;i++)
        {
            BaiDuLAJI[i]=1;
            for(int j=1;j<i;j++)
                if(cc(i,j))
                    BaiDuLAJI[i]=(BaiDuLAJI[i]+BaiDuLAJI[j])%mod;
            ans=(ans+BaiDuLAJI[i])%mod;
        }
        printf("%lld\n",ans);
    }
}
