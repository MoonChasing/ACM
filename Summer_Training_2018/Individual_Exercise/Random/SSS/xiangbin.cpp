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

set<int> s;
int a[200007];
int cur[200007];
int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    for(int i=1; i<=n; i++)
    {
        scanf("%d", a+i);
        s.insert(i);
    }
    a[n+1] = INF;
    s.insert(n+1);
    int op, x, v, cap;
    set<int>::iterator it;
    while(q--)
    {
        scanf("%d", &op);
        if(op==1)
        {
            scanf("%d", &x);
            printf("%d\n", cur[x]);
        }
        else
        {
            scanf("%d%d", &x, &v);
            while(v>0)
            {
                it = s.lower_bound(x);
                cap = *it;
                if(cap > n)
                    break;
                if(v > cur[cap]-a[cap])
                {
                    v -= cur[cap]-a[cap];
                    s.erase(it);
                    cur[cap] = a[cap];
                }
                else
                {
                    cur[cap] += v;
                    v = 0;
                }
            }
        }
    }
    return 0;
}












