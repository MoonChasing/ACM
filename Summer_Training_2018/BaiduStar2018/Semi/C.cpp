#include<bits/stdc++.h>
using namespace std;
const int MAXN=100000+7;
#define LL long long int
const LL mod=1e9+7;
vector<int>ufs[MAXN];
int fa[MAXN];
LL w[MAXN];
int n;
int u_find(int p)
{
    while(p!=fa[p])
    {
        fa[p]=fa[fa[p]];
        p=fa[p];
    }
    return p;
}

void ufsunion(int x, int y)
{
    x=u_find(x);
    y=u_find(y);
    if(x==y)
        return;
    else
    {
        fa[y]=x;
    }
}
int main()
{
    int T,m;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0; i<=n; i++)
            ufs[i].clear();
        for(int i=0; i<n; i++)
            scanf("%I64d",&w[i]);
        for(int i=0; i<=n; i++)
            fa[i]=i;
        int u,v;
        for(int i=1; i<=m; i++)
        {
            scanf("%d%d",&u,&v);
            u--,v--;
            ufsunion(u,v);
        }
        LL ans=0;
        for(int i=0; i<n; i++)
            ufs[u_find(i)].push_back(w[i]);
        for(int i=0; i<n; i++)
        {
            if(ufs[i].empty())
                continue;
            sort(ufs[i].begin(),ufs[i].end());
        }
        int dp[32];
        for(int i=0; i<n; i++)
        {
            memset(dp,0,sizeof(dp));
            int len=ufs[i].size();
            for(int j=0; j<len; j++)
            {
                LL it=ufs[i][j];
                for(int j=0; j<30; j++)
                {
                    if(it&(1<<j))
                    {
                        ans=(ans+(1LL*it*dp[j]%mod)*(1<<j))%mod;
                        dp[j]++;
                    }
                }
            }
        }
        printf("%I64d\n",ans);
    }
}

