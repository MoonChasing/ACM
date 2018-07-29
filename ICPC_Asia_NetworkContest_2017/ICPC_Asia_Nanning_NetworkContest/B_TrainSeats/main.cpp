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
//#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

int n;
int start, endd, num;

struct Tree
{
    int val;
    int modify;
} SegTree[MAXN<<2];

void PushUp(int root)
{
    SegTree[root].val = max(SegTree[root<<1].val, SegTree[root<<1|1].val);
}

void PushDown(int root, int l, int r)
{
    if(SegTree[root].modify)
    {
        SegTree[root<<1].val += SegTree[root].modify;
        SegTree[root<<1|1].val += SegTree[root].modify;

        SegTree[root<<1].modify += SegTree[root].modify;
        SegTree[root<<1|1].modify += SegTree[root].modify;

        SegTree[root].modify = 0;
    }
}

void build(int root, int l, int r)
{
    if(l==r)
        SegTree[root].val = SegTree[root].modify = 0;
    else
    {
        int mid = l+r>>1;
        build(root<<1, l, mid);
        build(root<<1|1, mid+1, r);
        PushUp(root);
    }
}

void update(int root, int l, int r, int a, int b, int modify)
{
    if(a>r || b<l)
        return;
    if(a<=l && b>=r)
    {
        SegTree[root].val += modify;
        SegTree[root].modify += modify;
        return;
    }
    PushDown(root, l, r);
    int mid = l+r>>1;
    update(root<<1, l, mid, a, b, modify);
    update(root<<1|1, mid+1, r, a, b, modify);
    PushUp(root);
}

int query(int root, int l, int r, int a, int b)
{
    if(a>r || b<l)
        return 0;
    if(a<=l && b>=r)
        return SegTree[root].val;
    PushDown(root, l, r);
    int mid = l+r>>1;
    return max(query(root<<1, l, mid, a, b), query(root<<1|1, mid+1, r, a, b));
}

void init()
{
    memset(SegTree, 0, sizeof(SegTree));
}
int main()
{
#ifdef DataIn
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt", "r", stdin);
#endif

    while(scanf("%d", &n) == 1 && n)
    {
        init();
        //build(1, 1, 100);


        for(int i=1; i<=n; i++)
        {
            scanf("%d%d%d",&start, &endd, &num);
            update(1, 1, 100, start, endd-1, num);
#ifdef DEBUG
            for(int i = 1; i<=100; i++)
            {
                printf("%-4d", SegTree[i].val);
            }
#endif // DEBUG
        }
        printf("%d\n", SegTree[1].val);
    }

    puts("*");
    return 0;
}












