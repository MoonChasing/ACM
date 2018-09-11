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

using namespace std;
const int MOD = 998244353;
const int MAXN = 1<<17;
int n;
LL bit[MAXN];

LL qpow_mod(LL a, LL b = MOD-2)
{
    LL ret = 1;
    while(b)
    {
        if(b & 1)
            ret = ret * a % MOD;
        b >>= 1;
        a = a*a%MOD;
    }
    return ret;
}

struct node
{
    int id, sz, p;
    bool operator < (const node &a) const
    {
        return sz > a.sz || sz == a.sz && id < a.id;
    }
} P[MAXN];

void update(LL x, LL v)
{
    for(LL i=x; i <= n; i += i&-i )
        bit[i] = bit[i]*v%MOD;
}

LL query(LL x)
{
    LL ret = 1;
    while(x)
    {
        ret = (ret * bit[x]) % MOD;
        x -= x&-x;
    }
    return ret;
}


int main()
{
    cin >> n;
    LL ans = 0;
    LL inv0 = qpow_mod(100);
    for(int i=0; i<MAXN; i++)
        bit[i] = 1;
    for(int i=0; i<n; i++)
    {
        cin >> P[i].p >> P[i].sz;
        P[i].id = i + 1;
    }
    sort(P, P+n);
    LL temp;
    for(int i=0; i<n; i++)
    {
        temp = (query(P[i].id-1) * (inv0*P[i].p%MOD) )%MOD;
        ans = (ans+temp)%MOD;
        update(P[i].id, inv0*(100-P[i].p)%MOD);
    }
    cout << ans <<endl;
    return 0;
}












