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

int main()
{
    int T, n, k;
    scanf("%d", &T);
    int minn=0, maxx;
    while(T--)
    {
        scanf("%d%d", &n, &k);
        if(k==0 || k==1)
            maxx = 0;
        else
            maxx = min(n-k, k-1);
        printf("%d %d\n", minn, maxx);
    }
    return 0;
}












