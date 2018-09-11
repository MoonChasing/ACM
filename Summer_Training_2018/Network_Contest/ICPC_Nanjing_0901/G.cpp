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

struct ask
{
    int replacenum, remain;
}ans[1000010];

int n, m, q;
int seg[MAXN<<2];
int room[MAXN];

void pushup(int root)
{
    seg[root] = min(seg[root<<1], seg[root<<1|1]);
}

void build(int root, int l, int r)
{
    if(l == r)
    {
        seg[root] = room[l];
        return;
    }
    int mid = l+r>>1;
    build(root<<1, l, mid);
    build(root<<1|1, mid+1, r);
    pushup(root);
}

int query(int root, int l, int r, int a, int b)
{
    if(b < l || a > r)
        return INF;
    if(a<=l && b>=r)
        return seg[root];

    int mid = l+r>>1;
    return min(query(root<<1, l, mid, a, b), query(root<<1|1, mid+1, r, a, b));
}

void update(int root, int l, int r, int ind)
{
     if(l==r)
    {
        seg[root] = INF;
        return;
    }
    int mid = l+r>>1;

    if(ind <= mid)
        update(root<<1, l, mid, ind);
    else
        update(root<<1|1, mid+1, r, ind);
    PushUp(root);
}

int binsearch(int a, int b, int cur)
{
    int l = a, r = b;
    int mid;
    while(l < r)
    {
        mid = l+r>>1;
        if(query(1, 1, n, l, r) >= cur)
            r = mid;
        else
            l = mid+1;
    }
    return l;
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++)
        scanf("%d", room + i);
    build(1, 1, n);
    scanf("%d", &q);
    int moon = 1;
    int cur = 0;
    while(seg[1])
    {
        cur += m;
        int l=1, r=n;
        while(query(1, 1, n, l, r) >= cur)
        {
            int mid = l+r>>1;

        }
    }
    return 0;
}













