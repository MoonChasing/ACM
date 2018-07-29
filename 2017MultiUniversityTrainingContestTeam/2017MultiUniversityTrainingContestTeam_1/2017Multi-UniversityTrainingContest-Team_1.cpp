#include <cmath>
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
typedef long long LL;

const double a = 0.30102999566398119521373889472449;

int main()
{
    int time = 0;
    int  n;
    while(~scanf("%d",&n))
    {
        int ans = a*n;
        printf("Case #%d: %d\n",++time, ans);

    }
    return 0;
}


