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
#define MAXN 65
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

int T, k;
LL n;
LL maxx;
LL tar;
bool sub[MAXN];

int main()
{
    scanf("%d", &T);
    for(int kiss = 1; kiss <= T; kiss++)
    {
        scanf("%lld%d", &n, &k);
        memset(sub, false, sizeof(sub));
        maxx = 1LL << k;
        tar = (maxx - n)/2;
        int cnt = 1;
        while(tar)
        {
            if(tar & 1)
            {
                sub[cnt] = true;
            }
            tar >>= 1;
            cnt++;
        }

        printf("Case #%d:\n", kiss);
        for(int i=1; i<=k-1; i++)
        {
            printf("%lld %c\n", 1LL<<(i-1), sub[i] ? '-' : '+');
        }

        if(n & 1)
            printf("%lld %c\n", 1LL<<(k-1), sub[k] ? '-' : '+');
        else
            printf("%lld %c\n", (1LL<<(k-1))+1, sub[k] ? '-' : '+');
    }

}












