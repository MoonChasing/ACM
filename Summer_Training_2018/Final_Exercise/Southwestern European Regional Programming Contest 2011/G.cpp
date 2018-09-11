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
#define MAXN 1000010
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

int num[MAXN];
int seg[MAXN<<2];
int lazy[MAXN<<2];

void pushup(int root)
{
    seg[root] = min(seg[root<<1], seg[root<<1|1]);
}

void build(int root, int l, int r)
{
    if(l == r)
        seg[root] = num[l];
    else
    {
        int mid = l+r>>1;
        build(root<<1, l, mid);
        build(root<<1|1, mid+1, r);
        pushup(root);
    }
}

void pushdown(int root, int l, int r)
{
    if(lazy[root])
    {
        seg[root<<1] += lazy[root];
        seg[root<<1|1] += lazy[root];

        lazy[root<<1] += lazy[root];
        lazy[root<<1|1] += lazy[root];

        lazy[root] = 0;
    }
}

int query(int root, int l, int r, int a, int b)
{
    if(a>r || b<l)
        return INF;
    if(a<=l && b>=r)
        return seg[root];

    int mid = l+r>>1;
    return min(query(root<<1, l, mid, a, b), query(root<<1|1, mid+1, r, a, b) );
}

void qujianupdate(int root, int l, int r, int a, int b, int val) //区间加某一个数
{
    if(a>r || b<l)
        return;
    if(a<=l && b>=r)
    {
        seg[root] += val;
        lazy[root] += val;
        return;
    }

    pushdown(root, l, r);
    int mid = l+r>>1;
    qujianupdate(root<<1, l, mid, a, b, val);
    qujianupdate(root<<1|1, mid+1, r, a, b, val);
    pushup(root);
}

void dandianupdate(int root, int l, int r, int index, int val)
{
    if(l==r)
    {
        seg[root] = val;
        return;
    }
    int mid = l+r>>1;
    if(index <= mid)
        dandianupdate(root<<1, l, mid, index, val);
    else
        dandianupdate(root<<1|1, mid+1, r, index, val);
    pushup(root);
}

int main()
{

    return 0;
}











#ifdef DataIn
	freopen("C:\\Users\\Administrator\\Desktop\\in.txt", "r", stdin);
#endif
