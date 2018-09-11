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
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

const int MAXN = 10000000+7;

using namespace std;

int prime[MAXN];
void getPrime()
{
    memset(prime, 0, sizeof(prime));
    for(int i=2; i<MAXN; i++)
    {
        if(!prime[i])
            prime[++prime[0]] = i;
        for(int j=1; j<=prime[0] && prime[j]<=MAXN/i; j++)
        {
            prime[prime[j]*i] = 1;
            if(i%prime[j]==0)
                break;
        }
    }
}

int l, r;

int main()
{
    freopen("C.IN", "r", stdin);
    getPrime();
    while(2 == scanf("%d%d", &l, &r))
    {
       int ans = lower_bound(prime+1, prime+prime[0]+1, r) - lower_bound(prime+1, prime+prime[0]+1, l);
       printf("%d\n", ans);
       putchar(10);
    }
    return 0;
}











