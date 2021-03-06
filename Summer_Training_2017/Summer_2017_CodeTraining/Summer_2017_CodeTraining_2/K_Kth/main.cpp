#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int MAXN = 100010;
int tree[30][MAXN]; /*表示每层每个位置的值*/
int sorted[MAXN]; //已经排序好的数
int toleft[30][MAXN]; //toleft[p][i]表示第p层从1到i有数分入左边


void build(int l, int r, int dep)
{
    if(l==r)
        return;
    int mid = (l+r)>>1;
    int same = mid-l+1;
    for(int i=l; i<=r; i++)
        if(tree[dep][i] < sorted[mid])
            same--;
    int lpos = l;
    int rpos = mid+1;

    for(int i=l; i<=r; i++)
    {
        if(tree[dep][i] < sorted[mid])
            tree[dep+1][lpos++] = tree[dep][i];
        else if(tree[dep][i] == sorted[mid] && same > 0)
        {
            tree[dep+1][lpos++] = tree[dep][i];
            same--;
        }
        else
            tree[dep+1][rpos++] = tree[dep][i];
        toleft[dep][i] = toleft[dep][l-1]+lpos-l;
    }

    build(l,mid,dep+1);
    build(mid+1,r,dep+1);
}

int query(int L, int R, int l, int r, int dep, int k)
{
    if(l==r)
        return tree[dep][l];
    int mid = (L+R)>>1;
    int cnt = toleft[dep][r] - toleft[dep][l-1];

    if(cnt>=k)
    {
        int newl = L+toleft[l-1]-toleft[L-1];
        int newr = newl+cnt-1;
        query(L,mid,newl,newr,dep+1,k);
    }
    else
    {
        int newr = r+toleft[dep][R]-toleft[dep][r];
        int newl = newr-(r-l-cnt);
        query(mid+1, R, newl, newr, dep+1, k-cnt);
    }
}

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)==2)
    {
        memset(tree,0,sizeof(tree));
        for(int i = 1; i <= n; i++)
        {
            scanf("%d",&tree[0][i]);
            sorted[i] = tree[0][i];
        }
        sort(sorted+1,sorted+n+1);
        build(1,n,0);
        int s,t,k;
        while(m--)
        {
            scanf("%d%d%d",&s,&t,&k);
            printf("%d\n",query(1,n,s,t,0,k));
        }
    }
    return 0;
}
