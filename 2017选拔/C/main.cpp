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
#define MAXN 1000100
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

struct foo
{
    int val;
    int pos;
}num[MAXN];

bool comp(struct foo f1, struct foo f2)
{
    return f1.val < f2.val;
}
int n,k;
int newpos[MAXN];


int main(void)
{
	scanf("%d%d", &n, &k);
	k--;
	for(int i=1; i<=n; i++)
    {
        scanf("%d", &num[i].val);
        num[i].pos = i;
    }

    sort(num+1, num+n+1, comp);
    for(int i=1; i<=n; i++)
        newpos[num[i].pos] = i;

    int ans = 0;

	for(int i=1; i<=n; i++)
	{
        int pos = newpos[i];
        int zhi = INT_MAX;
        int l = max(1, i-k);
        int r = min(i, n-k);
        for(int j=l; j<=r; j++)
        {
            zhi = min(zhi, num[j+k].val - num[j].val);
        }
        ans = max(ans, zhi);
	}

	printf("%d\n",ans);
	return 0;
}



/*
5 3
1 -2 10 5  4
*/





