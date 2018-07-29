#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define LOCAL
//#define DEBUG
const int MAXN = 1<<17;
using namespace std;

int T, n;
int a[MAXN];
int x,y;
int kind;
int arr[8];
int ans[8];
int zuida, cida, zuixiao, cixiao;
struct Tree
{
    int zuida, cida, zuixiao, cixiao;
}SegTree[MAXN<<2];

void init()
{
    memset(a, 0, sizeof a);
    memset(SegTree, 0, sizeof SegTree);
}
void PushUp(int root)
{
    arr[0] = SegTree[root<<1].zuida;
    arr[1] = SegTree[root<<1].cida;
    arr[2] = SegTree[root<<1].cixiao;
    arr[3] = SegTree[root<<1].zuixiao;
    arr[4] = SegTree[root<<1|1].zuida;
    arr[5] = SegTree[root<<1|1].cida;
    arr[6] = SegTree[root<<1|1].cixiao;
    arr[7] = SegTree[root<<1|1].zuixiao;
    sort(arr, arr+8);
    SegTree[root].zuida = arr[7];
    SegTree[root].cida = arr[6];
    SegTree[root].zuixiao = arr[0];
    SegTree[root].cixiao = arr[1];
}

void build(int root, int l, int r)
{
    if(l==r)
    {
        scanf("%d", &a[l]);
        SegTree[root].zuida = SegTree[root].zuixiao = SegTree[root].cida = SegTree[root].cixiao = a[l];
    }
    else
    {
        int mid = l+r>>1;
        build(root<<1, l, mid);
        build(root<<1|1, mid+1, r);
        PushUp(root);
    }
}

void query(int root, int l, int r, int a, int b)
{
    if(a>r || b<l)
        return;
    if(a<=l && b>=r)
    {
        ans[0] = SegTree[root].zuixiao;
        ans[1] = SegTree[root].cixiao;
        ans[2] = SegTree[root].cida;
        ans[3] = SegTree[root].zuida;
        ans[4] = zuida;
        ans[5] = cida;
        ans[6] = zuixiao;
        ans[7] = cixiao;
        sort(ans, ans+8);
        zuida = ans[7];
        cida = ans[6];
        zuixiao = ans[0];
        cixiao = ans[1];
        return;
    }

    int mid = l+r>>1;
    query(root<<1, l, mid, a, b);
    query(root<<1|1, mid+1, r, a, b);
}



void update(int root, int l, int r, int ind, int modifyVal)
{
    if(l==r)
    {
        SegTree[root].zuida = SegTree[root].zuixiao = SegTree[root].cida = SegTree[root].cixiao = modifyVal;
        return;
    }
    int mid = l+r>>1;
    if(ind <= mid)
        update(root<<1, l, mid, ind, modifyVal);
    else
        update(root<<1|1, mid+1, r, ind, modifyVal);
    PushUp(root);
}

int main()
{
    scanf("%d", &T);
    while(T--)
    {
        init();
        scanf("%d", &n);
        n = 1<<n;
        build(1, 1, n);
        int m;
        scanf("%d", &m);
        while(m--)
        {
            scanf("%d%d%d", &kind, &x, &y);
            if(kind == 1)
            {
                zuida = -MAXN;
                zuixiao = MAXN;
                query(1, 1, n, x, y);
                if(zuida < 0)
                    printf("%d\n", zuida*cida);
                if(zuixiao > 0)
                    printf("%d\n", zuixiao*cixiao);
                if(zuida>0 && zuixiao < 0)
                    printf("%d\n", zuida*zuixiao);
            }
            else
            {
                update(1, 1, n, x, y);
                printf("%4d%4d%4d%4d\n",zuida,cida,zuixiao,cixiao);
            }
        }


    }

    return 0;
}

