#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define SIZE 1000

using namespace std;

int SegTree[SIZE*4+1];
int a[] = {0,3,5,1,6};
int num;

void init()
{
    for(int i=0; i<SIZE*4+1; i++)
        SegTree[i] = INT_MAX;
    for(int i=0; i<SIZE; i++)
        a[i] = INT_MAX;
}

void build(int root, int l, int r)
{
    if(l == r)
        SegTree[root] = a[l];
    else
    {
        int mid = l+r >> 1;
        build(root<<1, l, mid);
        build(root<<1|1, mid+1, r);
        SegTree[root] = min(SegTree[root<<1], SegTree[root<<1|1]);
    }
}

//void updateone(int root, int l, int r, int ind, int val)
//{
//    if(l==r)
//    {
//        SegTree[root] = val;
//        return;
//    }
//    int mid = (l+r)>>1;
//    if(ind <= mid)
//        updateone(root<<1, l, mid, ind, val);
//    else
//        updateone(root<<1|1, mid+1, r, ind, val);
//    SegTree[root] = min(SegTree[root<<1], SegTree[(root<<1)|1]);
//}


void updateone(int root, int l, int r, int ind, int val)
{
    if(l==r)
    {
        SegTree[root] = val;
        return;
    }
    int mid = l+r >> 1;
    if(mid <= ind)
        updateone(root<<1, l, mid, ind, val);
    else
        updateone(root<<1|1, mid+1, r, ind, val);
    SegTree[root] = min(SegTree[root<<1], SegTree[(root<<1)|1]);
}

//int query(int a, int b, int k, int l, int r) //a,b表示要查询区间的范围， k为结点编号， l、r是结点的范围
//{
//    if(a>=r || b<=l)
//        return INT_MAX;
//    if(a<=l && b>=r)
//        return SegTree[k];
//    else
//    {
//        int vl = query(a, b, 2*k+1, l, (l+r)>>1);
//        int vr = query(a, b, 2*k+2, ((l+r)>>1)+1, r);
//        return min(vl, vr);
//    }
//}

int query(int a, int b, int root, int l, int r)
{
    if(a>=r || b<=l)
        return INT_MAX;
    if(a<=l && b>=r)
        return SegTree[root];
    else
        return min(query(a, b, root<<1, l, l+r>>1), query(a, b, root<<1|1, l+r>>1|1, r));


}

int main()
{
    build(1, 1, sizeof (a) / sizeof (a[0])-1);
    for(int i=1; i<=7; i++)
        printf("%5d", SegTree[i]);
    putchar(10);
    updateone(1, 1, 4, 3, -1);
    for(int i=1; i<=7; i++)
        printf("%5d", SegTree[i]);
    getchar();
    return 0;
}
