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
#define MAXN 10010
#define INF 0x3f3f3f3f
#define DEBUG
//#define DataIn
typedef long long LL;

using namespace std;

LL C(LL N)
{
    return N*(N-1)*(N-2)*(N-3)/24;
}

LL factor[MAXN], ct, Count[MAXN], num[MAXN];

void Divide(LL N)
{
    ct = 0;
    for(int i=2; i*i<=N; i++)
    {
        if(N%i == 0)
        {
            factor[ct++] = i;
            while(N%i == 0)
                N /= i;
        }
    }
    if(N != 1)
        factor[ct++] = N;
}

void solve(LL N)
{
    Divide(N);
    for(int i=1; i<(1<<ct); i++)
    {
        LL temp = 1;
        LL odd = 0;
        for(int j=0; j<ct; j++)
        {
            if( (1<<j) & i)
            {
                odd++;
                temp *= factor[j];
            }
        }
        Count[temp]++;
        num[temp] = odd;
    }
}
int main()
{
    #ifdef DataIn
        freopen("C:\\Users\\Administrator\\Desktop\\in.txt", "r", stdin);
    #endif
    LL N,M;
    while(~scanf("%I64d",&N))
    {
        memset(Count,0,sizeof(Count));
        for(int i = 0; i < N; ++i)
        {
            scanf("%I64d",&M);
            solve(M);
        }
        LL ans = 0;
        for(int i = 0; i <= 10000; ++i)
        {
            if(Count[i])
            {
                if(num[i] & 1)
                    ans += C(Count[i]);
                else
                    ans -= C(Count[i]);
            }
        }
        printf("%I64d\n",C(N) - ans);
    }

    return 0;

}












