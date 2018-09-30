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
//#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

LL city[MAXN<<1];
LL sum[MAXN<<1];
LL seg[MAXN<<3], lazy[MAXN<<3];

void pushup(int root)
{
    seg[root] = min(seg[root<<1], seg[root<<1|1]);
}

void pushdown(int root, int l, int r)
{
    if(lazy[root])
    {
        int val = lazy[root];
        seg[root<<1] += val;
        seg[root<<1|1] += val;

        lazy[root<<1] += val;
        lazy[root<<1|1] += val;

        lazy[root] = 0;
    }
}

void build(int root, int l, int r)
{
    if(l==r)
    {
        lazy[root] = 0;
        seg[root] = sum[l];
        return;
    }

    int mid = l+r>>1;
    build(root<<1, l, mid);
    build(root<<1|1, mid+1, r);
    pushup(root);
}

void update(int root, int l, int r, int a, int b, LL modify)
{
    if(a>r || b<l)
        return;
    if(a<=l && b>=r)
    {
        seg[root] += modify;
        lazy[root] += modify;
        return;
    }
    pushdown(root, l, r);
    int mid = l+r>>1;
    update(root<<1, l, mid, a, b, modify);
    update(root<<1|1, mid+1, r, a, b, modify);
    pushup(root);
}

LL query(int root, int l, int r, int a, int b)
{
    if(a>r || b<l)
        return 0;
    if(a<=l && b>=r)
        return seg[root];

    //pushdown(root, l, r);

    int mid = l+r>>1;
    return min(query(root<<1, l, mid, a, b), query(root<<1|1, mid+1, r, a, b));
}

int n, c;
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        memset(seg, 0, sizeof(seg));
        memset(lazy, 0, sizeof(lazy));
        memset(sum, 0, sizeof(sum));

        scanf("%d%d", &n, &c);
        LL bal = c;

        for(int i=1; i<=n; i++)
            scanf("%lld", city+i);
        LL tmp;
        for(int i=1; i<=n; i++)
        {
            scanf("%lld", &tmp);
            city[i] -= tmp;
        }
        for(int i=1, j=n+1; i<=n; i++, j++)
            city[j] = city[i];

        int len = n<<1;
        for(int i=1; i<=len; i++)
            sum[i] = sum[i-1] + city[i];
#ifdef DEBUG
        for(int i=1; i<=len; i++)
            cout << city[i] << " ";
        putchar(10);
        for(int i=1; i<=len; i++)
            cout << sum[i] << " ";
        putchar(10);
#endif // DEBUG

        bal += sum[n];
        if(bal < 0)
        {
            puts("-1");
            continue;
        }

        int ans = 0;
        build(1, 1, len);

        for(int i=1; i<=n; i++)
        {
            //update(1, 1, len, i, i+n-1, -sum[i-1]);
            LL minn = query(1, 1, len, i, i+n-1);
            //cout << i << "жа" << i+n-1 << " : " << minn << endl;
            if(minn+c-sum[i-1] >= 0 )
            {
                ans = i;
                break;
            }
            //update(1, 1, len, i, i+n-1, sum[i-1]);
        }
        if(!ans)
            puts("-1");
        else
            printf("%d\n", ans);

    }
    return 0;
}











