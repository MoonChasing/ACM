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

int n, m, p, q;
char gar[MAXN][MAXN];
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &n, &m);
        getchar();
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
                gar[i][j] = getchar();
            getchar();
        }

        int lc=m/2, tr=n/2;

        for(int k=1; k<=n; k++)
        {
            for(int i=1; i<=m/2; i++)
            {
                if(gar[k][i] != gar[k][m+1-i])
                {
                    lc = min(lc, i);
                    break;
                }
            }
        }

        for(int k=1; k<=m; k++)
        {
            for(int i=1; i<=n/2; i++)
            {
                if(gar[i][k] != gar[n+1-i][k])
                {
                    tr = min(tr, i);
                    break;
                }
            }
        }
        int ans = (lc-1) * (tr-1);
        printf("%d\n", ans);
    }

}












