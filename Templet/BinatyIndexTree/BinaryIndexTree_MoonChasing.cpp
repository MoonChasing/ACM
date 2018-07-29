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
#define MAXN 10010
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;


int BinIndTree[MAXN];
int n;

int sum(int i)
{
    int ans = 0;
    while(i>0)
    {
        ans += BinIndTree[i];
        i -= i&-i;
    }
    return ans;
}

void add(int i, int val)
{
    while(i<=n)
    {
        BinIndTree[i] += val;
        i += i&-i;
    }
}

