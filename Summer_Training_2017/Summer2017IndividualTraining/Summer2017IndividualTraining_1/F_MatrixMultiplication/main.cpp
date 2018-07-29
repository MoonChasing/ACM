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
#include <ctime>
#include <cmath>
#define MAXN 1005
#define INF 0x3f3f3f3f
typedef long long LL;

using namespace std;

LL a[MAXN][MAXN], b[MAXN][MAXN], c[MAXN][MAXN];
int n;

void readmatrix()
{

    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            scanf("%I64d",&a[i][j]);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            scanf("%I64d",&b[i][j]);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            scanf("%I64d",&c[i][j]);
}

bool judge()
{
    int i,j,k;
    for(int cnt=0; cnt<=50000; cnt++)
    {
        i = rand()%n+1;
        j = rand()%n+1;
        LL ans = 0;

        for(k=1; k<=n; k++)
            ans += a[i][k]*b[k][j];
        if(ans != c[i][j])
            return false;
    }
    return true;
}
int main()
{
    srand( (unsigned)time(NULL) );
    while(~scanf("%d",&n))
    {
    readmatrix();
    if(judge())
        puts("YES");
    else
        puts("NO");
    }
    return 0;
}


