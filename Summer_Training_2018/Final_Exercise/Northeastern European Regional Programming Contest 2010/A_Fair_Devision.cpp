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
#define MAXN 110
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

struct people
{
    int id, cur, val;
} a[MAXN];

bool cmpcur(people a, people b)
{
    return a.cur != b.cur ? a.cur > b.cur : a.id < b.id;
}

bool cmpid(people a, people b)
{
    return a.id < b.id;
}


int main()
{
    int T;
    int tot, n;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &tot, &n);
        int sum = 0;
        for(int i=0; i<n; i++)
        {
            scanf("%d", &a[i].cur);
            a[i].id = i;
            a[i].val = 0;
            sum += a[i].cur;
        }

        if(sum < tot)
        {
            puts("IMPOSSIBLE");
            continue;
        }


        sort(a, a+n, cmpcur);

        int m = n, mm;
        int ave;

        while(tot)
        {
            ave = tot / m;
            mm = m;
            if(ave == 0)
            {
                for(int i=0; i<tot; i++)
                {
                    a[i].val++;
                    a[i].cur--;
                }
                tot = 0;
            }
            else
            {
                sum = 0;
                for(int i = 0 ; i < mm; i++)
                {
                    if(a[i].cur <= ave)
                    {
                        sum += a[i].cur;
                        a[i].val += a[i].cur;
                        a[i].cur = 0;
                        m--;
                    }
                    else
                    {
                        a[i].val += ave;
                        a[i].cur -= ave;
                        sum += ave;
                    }
                }
                tot -= sum;
            }
        }

        sort(a, a+n, cmpid);
        for(int i=0; i<n; i++)
        {
            printf("%d%c", a[i].val, " \n"[i+1==n]);
        }
    }
    return 0;
}



















