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
int n, m;
int pos[MAXN], bit[MAXN << 1];
int ans[MAXN];
int len;

inline int lowbit(int x)
{
    return x&-x;
}

int query(int x)
{
    int ans = 0;
    while(x)
    {
        ans += bit[x];
        x -= lowbit(x);
    }
    return ans;
}

void update(int x, int val)
{
    while(x<=n)
    {
        bit[x] += val;
        x += lowbit(x);
    }
}
int a;
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        memset(bit, 0, sizeof(bit));
        scanf("%d%d", &n, &m);
        len = n;
        n += m;
        for(int i=1; i<=len; i++)
        {
            update(i, 1);
            pos[i] = len-i+1;
        }
        for(int i=1; i<=m; i++)
        {
            scanf("%d", &a);
            ans[i] = query(len) - query(pos[a]);
            update(pos[a], -1);
            len++;
            pos[a] = len;
            update(len , 1);
        }
        for(int i=1; i<=m; i++)
        {
            printf("%d%c", ans[i], " \n"[i==m]);
        }
    }
    return 0;
}











