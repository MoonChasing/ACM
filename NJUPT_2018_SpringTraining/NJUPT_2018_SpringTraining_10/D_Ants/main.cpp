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
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

int T;
int L, n;
int a[MAXN];
int main()
{
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &L, &n);
        for(int i=0; i<n; i++)
        {
            scanf("%d", a+i);
        }
        int minn = -1, maxx = -1;
        for(int i=0; i<n; i++)
        {
            minn = max(minn, min(a[i], L-a[i]));
            maxx = max(maxx, max(a[i], L-a[i]));
        }
        printf("%d %d\n", minn, maxx);
    }
    return 0;
}











