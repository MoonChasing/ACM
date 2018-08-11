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
#define MAXN 10
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

int ans;
int n, k;
char mz[10][10];
bool visrow[10], viscol[10];

void dfs(int i, int used)
{
    if(used == k)
    {
        ans++;
        return;
    }
    if(i > n)
        return;


    for(int j=1; j<=n; j++)
    {
        if(mz[i][j] == '#')
        {
            if(!visrow[i] && !viscol[j])
            {
                visrow[i] = true;
                viscol[j] = true;

                dfs(i+1, used+1);

                visrow[i] = false;
                viscol[j] = false;
            }
        }
    }
    dfs(i+1, used);

}

int main()
{
    while(scanf("%d%d", &n, &k) && (~n || ~k))
    {
        ans = 0;
        memset(visrow, false, sizeof(visrow));
        memset(viscol, false, sizeof(viscol));
        memset(mz, '.', sizeof(mz));
        getchar();
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
                mz[i][j] = getchar();
            getchar();
        }
        dfs(1, 0);
        printf("%d\n", ans);
    }
    return 0;
}










