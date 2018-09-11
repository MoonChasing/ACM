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
int a[MAXN];
int bit[MAXN];

int query(int x)
{
    int ans = 0;
    while(x)
    {
        ans += bit[x];
        x -= x&-x;
    }
    return ans;
}

void update(int x)
{
    while(x<MAXN)
    {
        bit[x]++;
        x += x&-x;
    }
}
int main()
{
    scanf("%d", &n);
    int ans = 0;
    int x;
    for(int i=1; i<=n; i++)
    {
        scanf("%d", &x);
        update(x);
        ans += i-query(x);

    }
    printf("%d\n", ans);
    return 0;
}












