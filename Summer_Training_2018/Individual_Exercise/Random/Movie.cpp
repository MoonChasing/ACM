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

int bit[MAXN<<1];
int pos[MAXN];
int n, m;

void update(int x, int val)
{
    while(x<(MAXN<<1))
    {
        bit[x] += val;
        x += (x&-x);
    }
}

int query(int x)
{
    int sum = 0;
    while(x)
    {
        sum += bit[x];
        x -= (x&-x);
    }
    return sum;
}

int main()
{
    int T;
    scanf("%d", &T);
    int ans = 0;
    int x;
    while(T--)
    {
        memset(bit, 0, sizeof(bit));
        scanf("%d%d", &n, &m);
        for(int i=1; i<=n; i++)
        {
            update(i, 1);
            pos[i] = n-i+1;
        }

        for(int i=1; i<=m; i++)
        {
            scanf("%d", &x);

            ans = query(i+n-1) - query(pos[x]);
            update(pos[x], -1);
            pos[x] = i+n;
            update(pos[x], 1);
            printf("%d%c", ans, " \n"[i==m]);
        }

    }
    return 0;
}










