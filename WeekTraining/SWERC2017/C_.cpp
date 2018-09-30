#include<cstdio>
#include<cstring>
#include <iostream>
#include<algorithm>
using namespace std;
const int MAXN = 1e5+7;
struct lap
{
    int m, s;
    bool operator < (const lap & a)
    {
        return m > a.m;
    }
}a[MAXN];
int b[MAXN];
int n;

int bit[MAXN];
void update(int x)
{
    while(x<MAXN)
    {
        bit[x]++;
        x += x&-x;
    }
}

int query(int x)
{
    //cout << x << " : ";
    int ans = 0;
    while(x)
    {
        ans += bit[x];
        x -= x&-x;
    }
    //cout << ans << endl;
    return ans;
}
int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d%d", &a[i].m, &a[i].s);
        b[i] = (a[i].s);
    }

    sort(a+1, a+1+n);
    sort(b+1, b+1+n);
    int uninum = unique(b+1, b+1+n) - b - 1;
    for(int i=1; i<=n; i++)
        a[i].s = lower_bound(b+1, b+1+uninum, a[i].s)-b;

    int ans = 0;
    //update(a[1].s);
    for(int i=1; i<=n; i++)
    {
        if(i-1-query(a[i].s))
            ans++;
        update(a[i].s);
    }
    printf("%d\n", ans);
    return 0;
}
