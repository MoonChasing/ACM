#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#define MAXN 100010
#define LGD 10010043
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

LL ans;
map<int, int> mp;
LL dp[MAXN];
vector<int> g[MAXN];

//搜索节点u的所有子树中节点个数
void dfs(int u, int p)
{
    dp[u] = 1;
    for(int i=0; i<g[u].size(); i++)
    {
        int v=g[u][i];
        if(v == p)
            continue;
        dfs(v, u);
        dp[u] += dp[v] *LGD;
    }
    ans += mp[dp[u]];
    mp[dp[u]]++;
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<n; i++)
    {
        int u,v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, -1);
    printf("%lld\n",ans);
    return 0;
}








