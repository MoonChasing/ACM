#include <cstdio>
#include <cstring>
typedef long long LL;
using namespace std;

int n;
const int MAXN = 10000007;
const int MOD = 1e9+7;

bool notprime[MAXN+1];
int prime[MAXN];
void getPrime()
{
    memset(notprime, false, true);
    memset(prime, 0, sizeof(prime));
    notprime[0] = notprime[1] = true;
    for(int i=2; i<=MAXN; i++)
    {
        if(!notprime[i])
            prime[++prime[0]] = i;
        for(int j=1; j<=prime[0]&&prime[j]<=MAXN/i; j++)
        {
            notprime[prime[j]*i] = true;
            if(i%prime[j] == 0)
                break;
        }
    }
}

LL qpow(LL a, LL b)
{
    LL res = 1;
    a = a%MOD;
    while(b)
    {
        if(b&1)
            res = res * a % MOD;
        b >>= 1;
        a = a*a%MOD;
    }
    return res;
}

int jc[MAXN];

void init()
{
    jc[0] = jc[1] = 1;
    for(int i=2; i<MAXN; i++)
        jc[i] = 1LL * jc[i-1] * i % MOD;
}

int main()
{
    init();
    getPrime();
    int cnt;
    LL res = 1;
    int p, z;
    while(~scanf("%d", &n) && n)
    {
        res = 1;
        for(int i=1; i<=prime[0] && prime[i]<=n; i++)
        {
            cnt = 0;
            p = prime[i];
            z = n;
            while(z)
            {
                cnt += z/p;
                z /= p;
            }
            if(cnt & 1)
            {
                res = (res * p) % MOD;
            }
        }
        printf("%lld\n", jc[n] * qpow(res, MOD-2) % MOD);
    }
    return 0;
}











