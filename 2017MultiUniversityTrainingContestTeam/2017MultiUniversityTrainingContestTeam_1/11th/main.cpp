//team 595
//B16041432 ´ÞÃ÷ºÆ
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
#define MAXN 100010
#define INF 0x3f3f3f3f
typedef long long LL;

using namespace std;
int time;
int main()
{
    LL n,k;
    while(scanf("%I64d%I64d",&n,&k) == 2)
    {
        if(k<=n)
            printf("Case #%d: %I64d\n",++time,k);
        else
        {
            LL did, mod;
            did = (k-n)/(n-1);
            mod = (k-n) % (n-1);

            if(did&1)
            {
                if(mod == 0)
                    printf("Case #%d: %I64d\n",++time,n-1);
                else
                    printf("Case #%d: %I64d\n",++time,mod);
            }
            else
            {
                if(mod == 0)
                    printf("Case #%d: %I64d\n",++time,n);
                else
                    printf("Case #%d: %I64d\n",++time,mod);
            }
        }
    }

    return 0;
}
