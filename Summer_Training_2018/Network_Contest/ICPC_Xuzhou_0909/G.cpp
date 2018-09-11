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
#define MAXN 50007
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

int x[MAXN], y[MAXN];
int n;
set<int> s;
set<int>::iterator it;

int main()
{
    scanf("%d", &n);
    LL ans = 0;
    for(int i=0; i<n; i++)
    {
        scanf("%d%d", x+i, y+i);
    }

    for(int i=n-1; i>=0; i--)
    {
        it = s.lower_bound(x[i]);
        if(it == s.begin())
            ans += x[i];
        else
        {
            it--;
            ans += x[i] - *it;
        }
        s.insert(x[i]);
    }

    s.clear();

    for(int i=n-1; i>=0; i--)
    {
        it = s.lower_bound(y[i]);
        if(it == s.begin())
            ans += y[i];
        else
        {
            it--;
            ans += y[i] - *it;
        }
        s.insert(y[i]);
    }

    printf("%lld\n", ans);
    return 0;
}











