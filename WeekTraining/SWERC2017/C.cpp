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
#define MAXN 256
#define INF 0x3f3f3f3f
#define rep( i, l, r ) 	for( int i = (l); i <= (r); ++i )
#define CLR(a,x)        memset(a,x,sizeof(a))
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

struct matrix
{
    LL mat[MAXN][MAXN];
}dp, ans, c, d;

LL n, m;


const int MOD = 1e9;

matrix operator	*(matrix &a, matrix &b)
{
    matrix c;
    memset(c.mat,0,sizeof(c.mat));
    for(LL i=0; i<MAXN; i++)
    {
        for(LL k=0; k<MAXN; k++)
        {
            if(a.mat[i][k]==0)
                continue;
            for(LL j=0; j<MAXN; j++)
                c.mat[i][j]=(c.mat[i][j]+(a.mat[i][k]%MOD)*(b.mat[k][j]%MOD))%MOD;
        }
    }
    return c;
}

matrix powerm(LL b)
{
    memset(d.mat,0,sizeof(d.mat));
    for(LL i=0; i<MAXN; i++)
    {
        for(LL j=0; j<MAXN; j++)
        {
            if(i==j)
                d.mat[i][j]=1;
        }
    }

    while(b)
    {
        if(b&1)
            d = d*dp;
        dp = dp*dp;
        b>>=1;
    }
    return d;
}

void dfs(LL pos, LL curS, LL toS)
{
    if(pos >= n)
    {
        dp.mat[curS][toS]++;
        return;
    }

    if( (curS>>pos) & 1 )
    {
        dfs(pos+1, curS, toS);
        dfs(pos+1, curS,    toS|(1<<(pos-1)) );
        if(pos+1<n && ((curS >> (pos+1) ))&1 )
            dfs(pos+2, curS, toS|(1<<(pos-1))|(1<<pos) );
    }
    else
        dfs(pos+1, curS, toS + (1<<(pos-1)) );
}

int main()
{
    scanf("%lld%lld", &n, &m);

    int up = 1<<n;
    for(int S=0; S<up; S++)
    {
        dfs(0, S, 0);
    }
    for(int S=0; S<up; S++)
        ans.mat[0][S] = dp.mat[up-1][S];



    dp = powerm(m-1);

    ans = ans*dp;
    printf("%lld\n", ans.mat[0][up-1]);
    return 0;
}












