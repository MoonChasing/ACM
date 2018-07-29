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

int n;
struct Tree
{
    double val;
}segTree[MAXN << 2];

void init()
{
    //memset(a, 0, sizeof(a));
    memset(segTree, 0, sizeof(segTree));
}

void PUshUp(int root)
{
    segTree[root].val = segTree[root<<1].val + segTree[root<<1|1].val;
}

void build(int root, int l, int r)
{
    if(l == r)
    {
        scanf("%lf", &segTree[root].val);
    }
    else
    {
        int mid = l+r>>1;
        build(root<<1, l, mid);
        build(root<<1|1, mid+1, r);
        PUshUp(root);
    }
}

double query(int root, int l, int r, int a, int b)
{
    if(a>r || b<l)
        return 0;
    if(a<=l && b>=r)
        return segTree[root].val;

    int mid = l+r>>1;
    return query(root<<1, l, mid, a, b) + query(root<<1|1, mid+1, r, a, b);
}

void update(int root, int l, int r, int ind, double cur)
{
    if(l == r)
    {
        segTree[root].val = cur;
        return;
    }

    int mid = l+r>>1;
    if(ind <= mid)
        update(root<<1, l, mid, ind, cur);
    else
        update(root<<1|1, mid+1, r, ind, cur);
    PUshUp(root);
}

int main()
{
    init();
    scanf("%d", &n);
    build(1,1,n);

    int T;
    scanf("%d", &T);
    int op;
    int ind, l, r;
    double val;
    while(T--)
    {
        scanf("%d", &op);

        if(op == 1)
        {
            scanf("%d%lf", &ind, &val);
            update(1, 1, n, ind, val);
        }
        else
        {
            scanf("%d%d", &l, &r);
            double ans = query(1, 1, n, l, r)/(r-l+1);
            printf("%.6f\n", ans);
        }
    }
    return 0;
}











