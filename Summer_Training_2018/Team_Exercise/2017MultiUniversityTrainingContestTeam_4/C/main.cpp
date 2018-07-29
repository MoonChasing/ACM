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
#define MAXN 10000
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

int prime[MAXN+1];
const int MOD = 998244353;

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

long long factor[100][2];
int fatCnt;
int getFactors(long long x)
{
    fatCnt = 0;
    long long tmp = x;

    for(int i=1; prime[i]<=tmp/prime[i]; i++)
    {
        factor[fatCnt][1] = 0;
        if(tmp%prime[i]==0)
        {
            factor[fatCnt][0] = prime[i];
            while(tmp%prime[i] == 0)
            {
                factor[fatCnt][1] ++;
                tmp /= prime[i];
            }
            fatCnt++;
        }
    }

    if(tmp != 1)
    {
        factor[fatCnt][0] = tmp;
        factor[fatCnt++][1] = 1;
    }
    return fatCnt;
}

//get pow(x, k) factors count
int getFactorNum(LL x, int k)
{
    int cnt = getFactors(x);
    int ret = 1;
    for(int i=0; i<cnt; i++)
    {
        ret = (ret * (factor[i][1]*k+1)%MOD) % MOD;
    }
    return ret;
}

int main()
{
    getPrime();
    int T;
    scanf("%d", &T);
    int l, r, k;
    while(T--)
    {
        scanf("%d%d%d", &l, &r, &k);
        int ans = 0;
        for(int i=l; i<=r; i++)
            ans = ans + (getFactorNum(i, k) % MOD) % MOD;
        printf("%d\n", ans);
    }
    return 0;
}











