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
#define MAXN 2005
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

int n, m, k;
char maz[MAXN][MAXN];

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    getchar();
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
            scanf("%c", &maz[i][j]);
        getchar();
    }
    int ans=0, cnt=0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(maz[i][j] == '.')
                cnt++;
            else if(maz[i][j] == '*' )
            {
                if(cnt >= k)
                    ans += cnt-k+1;
                cnt = 0;
            }
        }
        if(cnt >= k)
            ans += cnt-k+1;
        cnt = 0;
    }
    for(int j=1; j<=m; j++)
    {
        for(int i=1; i<=n; i++)
        {
            if(maz[i][j] == '.')
                cnt++;
            else if(maz[i][j] == '*')
            {
                if(cnt >= k)
                    ans += cnt-k+1;
                cnt = 0;
            }
        }
        if(cnt >= k)
            ans += cnt-k+1;
        cnt = 0;
    }
    if(k == 1)
        printf("%d\n", ans/2);
    else
        printf("%d\n", ans);
    return 0;
}









