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

const int MAXN = 2 * 1e5 + 5;
const int MOD = 1e9 + 7;

int tot;
int cory[MAXN];
int bit[MAXN], dp[MAXN];
map<int, int>mp;

inline int lowbit(int x)
{
    return x&-x;
}

struct point
{
    int x, y, v;
} P[MAXN];

bool cmp(point x, point y)
{
    return x.x < y.x;
}

void update(int x, int y)
{
    while (x <= tot)
    {
        bit[x] = max(y, bit[x]);
        x += lowbit(x);
    }
}

int query(int x)
{
    int maxx = 0;
    while (x)
    {
        maxx = max(maxx, bit[x]);
        x -= lowbit(x);
    }
    return maxx;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;

        for (int i = 1; i <= tot; i++)
            bit[i] = 0;
        mp.clear();

        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d%d", &P[i].x, &P[i].y, &P[i].v);
            cory[i] = P[i].y;
        }

        sort(cory + 1, cory + 1 + n);
        cory[0] = cory[1] - 1;

        tot = 0;
        sort(P + 1, P + 1 + n, cmp);

        for (int i = 1; i <= n; i++)
        {
            if (cory[i] != cory[i - 1])
                mp[cory[i]] = ++tot;
        }

        for (int i = 1; i <= n; i++)
            P[i].y = mp[P[i].y];

        int ans = 0;
        int j;

        for (int i = 1; i <= n; i = j)
        {
            j = i;
            while (P[i].x == P[j].x && j <= n)
            {
                dp[j] = query(P[j].y) + P[j].v;
                j++;
            }
            for (int k = i; k<j; k++)
            {
                update(P[k].y + 1, dp[k]);
                ans = max(ans, dp[k]);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}









