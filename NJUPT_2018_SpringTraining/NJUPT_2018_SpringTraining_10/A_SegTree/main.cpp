#include<cstdio>
#include<iostream>
#include<cstring>

#define LOCAL
//#define DEBUG
#define MAXN 50005
using namespace std;

int T,n;
int kiss = 1;
int a[MAXN];
char ope[10];
int op1, op2;

struct Tree
{
    int val;
}segTree[MAXN << 2];

void init()
{
    memset(a, 0, sizeof(a));
    memset(segTree, 0, sizeof(segTree));
}

void PushUp(int root)
{
    segTree[root].val = segTree[root<<1].val + segTree[root<<1|1].val;
}

void build(int root, int l, int r)
{
    if(l == r)
    {
        scanf("%d", &a[l]);
        segTree[root].val = a[l];
    }
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
    if(a<=l && b>=r)
        return segTree[root].val;

    int mid = l+r>>1;
    return query(root<<1, l, mid, a, b) + query(root<<1|1, mid+1, r, a, b);
}

void update(int root, int l, int r, int ind, int modifyVal)
{
    if(l == r)
    {
        segTree[root].val += modifyVal;
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
        build(1, 1, n);
        printf("Case %d:\n", kiss++);
        while(scanf("%s",ope))
        {
            if(ope[0] =='E')
                break;
            scanf("%d%d",&op1, &op2);
            if(ope[0] == 'Q')
                printf("%d\n", query(1,1,n,op1,op2));
            else if(ope[0] == 'A')
                update(1, 1, n, op1, op2);
            else if(ope[0] == 'S')
                update(1, 1, n, op1, -op2);
        }
    }
    return 0;
}
