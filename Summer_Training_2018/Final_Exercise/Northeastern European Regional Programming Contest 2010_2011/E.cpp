#include <algorithm>
#include  <iostream>
#include   <cstdlib>
#include   <cstring>
#include    <cstdio>
#include    <string>
#include    <vector>
#include     <stack>
#include     <cmath>
#include       <map>
using namespace std;
#define LL			    long long
#define MOD 		    1000000007
#define mod(x)		    (x%MOD)
#define CLR(a,x)        memset(a,x,sizeof(a))
#define FILL(a,n,x)     fill(a,a+n,x)
#define INF 		    0x3fffffff
#define pb 		        push_back
#define WHILE() 	    int T;scanf( "%d", &T );while( T-- )
#define rep( i, l, r ) 	for( int i = l; i <= r; ++i )

int n, m;
const int N = 4000+7;
struct node {
    int id, pos;
} teams[N], shelters[N];

int cmp( node n1, node n2 ) {
    return n1.pos < n2.pos;
}

LL dp[2][N];
bool path[N][N];
int ans[N];

void run(int n, int m)
{
    if(n==0 || m==0)
        return;
    ans[teams[n].id] = shelters[m].id;
    run(n-1, m - (path[n][m] ? 1 : 0));
}

LL solve()
{
    for(int i=1; i<=m; i++)
        dp[0][i] = INF;
    dp[0][0] = 0;
    for(int i=1; i<=n; i++)
    {
        int cur = i&1;
        int pre = 1-cur;
        for(int j=0; j<=m; j++)
            dp[cur][j] = INF;

        for(int j=1; j<=m && j<=i; j++)
        {
            if(dp[pre][j-1] < dp[pre][j])
            {
                dp[cur][j] == dp[pre][j-1] + abs(teams[i].pos - shelters[j].pos);
                path[i][j] = true;
            }
            else
            {
                dp[cur][j] = dp[pre][j] + abs(teams[i].pos - shelters[j].pos);
                path[i][j] = false;
            }
        }
    }
    return dp[n&1][m];
}

int main() {
   while(~scanf("%d", &n))
   {
        for(int i=1; i<=n; i++)
        {
            scanf("%d", &teams[i].pos);
            teams[i].id = i;
        }
        scanf("%d", &m);
        for(int i=1; i<=m; i++)
        {
            scanf("%d", &shelters[i].pos);
            shelters[i].id = i;
        }

        sort(teams+1, teams+n+1, cmp);
        sort(shelters+1, shelters+m+1, cmp);

        printf("%lld\n", solve());
        run(n, m);
        for(int i=1; i<=n; i++)
            printf("%d%c", ans[i], " \n"[i==n]);
   }
    return 0;
}
