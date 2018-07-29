#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAXN = 1e5+5;
int n, q, a[MAXN], b[MAXN];

struct node
{
    LL minx, valb, sum_zero, lazy;
} SegTree[MAXN << 2];

void PushDown(int root, int l, int r)
{
    if(SegTree[root].lazy)
    {
        SegTree[root<<1].lazy += SegTree[root].lazy;
        SegTree[root<<1|1].lazy += SegTree[root].lazy;

        SegTree[root<<1].minx -= SegTree[root].lazy;
        SegTree[root<<1|1].minx -= SegTree[root].lazy;

        SegTree[root].lazy = 0;
    }
}

void PushUp(int root)
{
    SegTree[root].sum_zero = SegTree[root<<1].sum_zero + SegTree[root<<1|1].sum_zero;
    SegTree[root].minx = min(SegTree[root<<1].minx, SegTree[root<<1|1].minx);
}

void build(int root, int l, int r)
{
    SegTree[root].lazy = SegTree[root].sum_zero = 0;
    if(l == r)
    {
        SegTree[root].minx = SegTree[root].valb = b[l];
        SegTree[root].sum_zero = 0;
        return;
    }

    int mid = l+r>>1;
    build(root<<1, l, mid);
    build(root<<1|1, mid+1, r);
    PushUp(root);
}

void update(int root, int l, int r, int a, int b)
{
    if(l > r)
        return;

    if(SegTree[root].minx > 1 && a==l && b==r)
    {
        SegTree[root].lazy++;
        SegTree[root].minx--;
        return;
    }

    if(l == r && SegTree[root].minx == 1)
    {
        SegTree[root].sum_zero++;
        SegTree[root].lazy = 0;
        SegTree[root].minx = SegTree[root].valb;
        return;
    }

    PushDown(root, l, r);
    int mid = l+r>>1;

    if(b <= mid)
        update(root<<1, l, mid, a, b);
    else if(a > mid)
        update(root<<1|1, mid+1, r, a, b);
    else
    {
        update(root<<1, l, mid, a, mid);
        update(root<<1|1, mid+1, r, mid+1, b);
    }
    PushUp(root);
}

LL query(int root, int l, int r, int a, int b)
{
    if(l > r)
        return 0;
    if(l == a && r == b)
        return SegTree[root].sum_zero;
    if(SegTree[root].minx <= 0)
        update(1, 1, n, a, b);

    int mid = l+r>>1;
    if(b <= mid)
        return query(root<<1, l, mid, a, b);
    else if(a > mid)
        return query(root<<1|1, mid+1, r, a, b);
    else
        return query(root<<1, l, mid, a, mid) + query(root<<1|1, mid+1, r, mid+1, b);
}
int main()
{
     while (~scanf("%d %d", &n, &q)) {
        for (int i = 1; i <= n; i++)
            scanf("%d", &b[i]);
        build(1, 1, n);
        while (q--) {
            char op[10];
            int l, r;
            scanf("%s %d %d", op, &l, &r);
            if (op[0] == 'a') {
                update(1, 1, n, l, r);
            } else {
                LL ans = query(1, 1, n, l, r);
                printf("%lld\n", ans);
            }
        }
    }
    return 0;
}









