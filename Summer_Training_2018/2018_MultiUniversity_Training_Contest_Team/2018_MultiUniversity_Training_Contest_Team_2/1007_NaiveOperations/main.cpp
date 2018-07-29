#include<bits/stdc++.h>
#define MAXN 100010
#define INF 0x3f3f3f3f
//#define DEBUG
#define DataIn

typedef long long LL;

using namespace std;


int a[MAXN], SegTree[MAXN << 2], bb[MAXN];

void init()
{
    memset(SegTree, 0, sizeof(SegTree));
    memset(a, 0, sizeof(a));
    memset(bb, 0, sizeof(bb));
}

void PushUp(int root)
{
    SegTree[root] = SegTree[root<<1] + SegTree[root<<1|1];
}

void build(int root, int l, int r)
{
    if(l == r)
        SegTree[root] = 0;
    else
    {
        int mid = l+r>>1;
        build(root<<1, l, mid);
        build(root<<1|1, mid+1, r);
        PushUp(root);
    }
}

int query(int root, int l, int r, int a, int b)
{
    if(a > r || b < l)
        return 0;
    if(a <=l && b>= r)
        return SegTree[root];

    int mid = l+r>>1;
    return query(root<<1, l, mid, a, b) + query(root<<1|1, mid+1, r, a, b);
}

void update(int root, int l, int r, int ind)
{
    if(l == r)
    {
        a[ind]++;
        SegTree[root] = a[ind] / bb[ind];
        return;
    }

    int mid = l+r>>1;
    if(ind <= mid)
    {
        update(root<<1, l, mid, ind);
    }
    else
        update(root<<1|1, mid+1, r, ind);
    PushUp(root);
}

int n, q;
char ch[10];
int ll, rr;

int main()
{
    while(~scanf("%d%d", &n, &q))
    {
        init();
        for(int i=1; i<=n; i++)
            scanf("%d", bb+i);
        while(q--)
        {
            scanf("%s%d%d", ch, &ll, &rr);
            if(ch[0] == 'a')
                for(int i=ll; i<=rr; i++)
                {
                    update(1, 1, n, i);
                    #ifdef DEBUG
                    for(int i=1; i<=n; i++)
                    {
                        printf("%-3d ",a[i]);
                    }
                    putchar(10);

                    for(int i=1; i<=n; i++)
                    {
                        printf("%-3d ", query(1,1,n,i,i));
                    }
                    putchar(10);
                    #endif // DEBUG
                }
            else
                printf("%d\n", query(1, 1, n, ll, rr));
        }
    }
    return 0;
}










