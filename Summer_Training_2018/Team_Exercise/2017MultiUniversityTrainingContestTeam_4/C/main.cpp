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
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

const int MAXN = 1e6+7;
LL prime[MAXN+1];
LL num[MAXN+1];
LL a[MAXN];

const LL MOD = 998244353;
LL l, r, k;

void getPrime()
{
    memset(prime, 0, sizeof(prime));
    for(int i=2; i<=MAXN; i++)
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

void process()
{
    LL p, cnt;

    for(LL i=1; i<=prime[0] && prime[i] * prime[i]<=r; i++)
    {
        p = prime[i];
        for(LL j=(l+p-1)/p*p; j<=r; j+=p)
        {
            cnt = 0;
            while((a[j-l]%p==0) )
            {
                cnt++;
                a[j-l] /= p;
            }

            num[j-l] = (num[j-l] * ((k*cnt + 1) % MOD)) % MOD;
        }
    }
}


int main()
{
    getPrime();
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%I64d%I64d%I64d", &l, &r, &k);
        int len = r-l+1;
        for(int i=0; i<len; i++)
        {
            a[i] = l+i;
            num[i] = 1;
        }
        process();
        LL ans = 0;
        for(LL i=l; i<=r; i++)
        {
            if(a[i-l] > 1)
                num[i-l] = num[i-l] * (k+1) % MOD;
            ans = (ans + num[i-l]) %MOD;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}











