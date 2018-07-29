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
#define MAXN 300005
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

vector<int> G[MAXN];
char ch[MAXN];
int n,m, f[MAXN][26];  //f[i][j]为以i为顶点， 字母j的最大权

int dfs(int u, int c)  //u为顶点， c为字母
{
    if(-2 == f[u][c])
    {
        puts("-1");
        exit(0);
    }
    if(~f[u][c])
        return f[u][c];
    f[u][c] = -2;
    int ret = 0;
    for(int i=0; i<G[u].size(); i++)
    {
        int v = G[u][i];
        ret = max(ret, dfs(v,c));
    }
    if(ch[u]-'a' == c)
        ret++;
    f[u][c] = ret;
    return ret;
}
int main()
{
    int u,v;
    scanf("%d%d", &n, &m);
    scanf("%s", ch+1);
    for(int i=0; i<m; i++)
    {
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
    }
    memset(f, -1, sizeof(f));
    int ans = 0;
    for(int i=1; i<=n; i++)
        for(int j=0; j<26; j++)
            ans = max(ans, dfs(i,j));
    printf("%d\n", ans);
    return 0;
}





