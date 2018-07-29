#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e7+1;

bool notprime[MAXN];
int primecnt[MAXN];
typedef long long LL;

void init()
{
    memset(notprime, false, sizeof(notprime));
    notprime[0] = notprime[1] = true;
    for(int i=2; i<MAXN; i++)
    {
        if(!notprime[i])
        {
            if( i > MAXN/i )
            {
                continue;
            }
            for(int j=i*i; j<MAXN; j+=i)
            {
                notprime[j] = true;
            }
        }
    }

    primecnt[0] =primecnt[1] = 0;
    for(int i=2; i<MAXN; i++)
    {
        if(!notprime[i])
            primecnt[i] = primecnt[i-1]+1;
        else
            primecnt[i] = primecnt[i-1];
    }
}



int sum = 0;
int n;
int temp;
LL ans = 0;
int main()
{
    init();
//    for(int i=1; i<100; i++)
//       printf("%d:%d\n", i, primecnt[i]);
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        temp = primecnt[n/i];

        ans += (LL)(1LL*(temp-1)*temp);
    }
    printf("%lld\n", ans);
    return 0;
}
