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
#define MAXP 5800000
#define INF 0x3f3f3f3f
#define MOD (1<<32)
//#define DEBUG
//#define DataIn
typedef long long LL;

using namespace std;

unsigned prime[MAXP+1];
int pcnt;
unsigned sum[MAXP+1];
int T;
int kiss=1;
void getprime()
{
    memset(prime, 0, sizeof(prime));

    for(int i=2; i<=MAXP; i++)
    {
        if(!prime[i])
            prime[++prime[0]] = i;
        for(int j=1; j<=prime[0] && prime[j]<=MAXP/i; j++)
        {
            prime[prime[j]*i] = 1;
            if(i%prime[j] == 0)
                break;
        }
    }
    pcnt = prime[0];
}

unsigned int Deal(int n)
{
    int p = upper_bound(prime+1, prime+pcnt+1,n) - prime -1;
    unsigned int ans = sum[p];
    for (int i=1; i<pcnt && prime[i]*prime[i] <= n; i++)
    {
        int a = prime[i];
        int b = prime[i] * prime[i];
        while (b/a == prime[i] && b<=n)
        {
            b *= prime[i];
            a *= prime[i];
        }
        ans *= (a/prime[i]);
    }
    return ans;
}

void init()
{
    sum[0] = 1;
    for(int i=1; i<=MAXP; i++)
        sum[i] = sum[i-1]*prime[i];
}


int main()
{
    #ifdef DataIn
        freopen("C:\\Users\\Administrator\\Desktop\\in.txt", "r", stdin);
    #endif
    getprime();
    init();
    scanf("%d",&T);
    int a;
    for(kiss=1; kiss <= T; kiss++)
    {
        scanf("%d", &a);
        printf("Case %d: %u\n", kiss, Deal(a));
    }
}












