#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<map>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
#define mem(x,y) memset(x,y,sizeof(x))
#define scan(x) scanf("%d",&x)
#define scan2(x,y) scanf("%d%d",&x,&y)
#define eps 1e-8
#define INF 100000000
#define MAXN 100005
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define debug  cout<<"******"<<endl;
using namespace std;
typedef long long LL;

using namespace std;

LL n, q;
LL a[MAXN], b[MAXN], sega[MAXN<<2], segb[MAXN<<2];


void builda(int root, int l, int r)
{
    if(l==r)
    {
        sega[root] = a[l];
        return;
    }
    int mid = l+r>>1;
    builda(root<<1, l, mid);
    builda(root<<1|1, mid+1, r);
    sega[root] = sega[root<<1] + sega[root<<1|1];
}

void buildb(int root, int l, int r)
{
    if(l==r)
    {
        segb[root] = b[l];
        return;
    }
    int mid = l+r>>1;
    buildb(root<<1, l, mid);
    buildb(root<<1|1, mid+1, r);
    segb[root] = segb[root<<1] + segb[root<<1|1];
}

LL query(int root, int l, int r, int ll, int rr, LL * seg)
{
    if(ll > r || rr < l)
        return 0;
    if(ll <= l && rr >= r)
        return seg[root];

    int mid = l+r>>1;
    return query(root<<1, l, mid, ll, rr, seg) + query(root<<1|1, mid+1, r, ll, rr, seg);
}

void update(int root, int l, int r, int ind, int val, LL *seg)
{
    if(l == r)
    {
        seg[root] = val;
        return;
    }
    int mid = l+r>>1;
    if(ind <= mid)
        update(root<<1, l, mid, ind, val, seg);
    else
        update(root<<1|1, mid+1, r, ind, val, seg);
    seg[root] = seg[root<<1] + seg[root<<1|1];
}

int main()
{
    scanf("%lld%lld", &n, &q);
    for(int i=1; i<=n; i++)
    {
        scanf("%lld", a+i);
        b[i] = a[i]*(n-i+1);//todo
    }
    builda(1, 1, n);
    buildb(1, 1, n);


    while(q--)
    {
        int u;
        scanf("%d",&u);
        if(u==1)
        {
            LL l,r;
            scanf("%lld%lld",&l,&r);
            printf("%lld\n",query(1,1,n,l,r,segb)-(n-r)*query(1,1,n,l,r,sega));
          //  cout<<query(1,1,n,l,r,segb)<<endl;
        }
        else
        {
            LL x,y;
            scanf("%lld%lld",&x,&y);
            update(1,1,n,x,y,sega);
            update(1,1,n,x,y*(n-x+1),segb);
        }
    }


    return 0;
}
