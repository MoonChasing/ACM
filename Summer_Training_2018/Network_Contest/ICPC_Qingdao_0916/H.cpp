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
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

char lig[MAXN];
int sum[MAXN];
int ti[MAXN];
int len;
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int use = 0;
        memset(sum, 0, sizeof(sum));

        scanf("%s", lig+1);
        len = strlen(lig+1);

        for(int i=1; i<=len; i++)
        {
            if(use & 1)//变化
            {
                if(lig[i] == '1')
                {
                    use += 2;
                    sum[i] = sum[i-1] + 2;
                    ti[i] = 2;
                }
                else
                {
                    use++;
                    sum[i] = sum[i-1] + 1;
                    ti[i] = 1;
                }
            }
            else    //没变化
            {
                if(lig[i] == '1')
                {
                    use++;
                    sum[i] = sum[i-1] + 1;
                    ti[i] = 1;
                }
                else
                {
                    use += 2;
                    sum[i] = sum[i-1] + 2;
                    ti[i] = 2;
                }
            }
        }

        LL ans = 0;
        int n = len+1;
        LL tot;

        for(int i=1; i<=len; i++)
        {
            tot = 1LL * (n-i)*i;
            ans += (lig[i] == '1') ? (n-i) : (n-i)<<1;
            ans += (tot-n+i)*ti[i];
        }

        printf("%lld\n", ans);
    }
    return 0;
}












