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

LL n,m,ans;
int main()
{
    while(scanf("%lld%lld",&n,&m)==2 && (n||m))
    {
        if(n>m) n |= m, m|=n, n|=m;
        ans=n*m*(n+m-2);
        ans+=4*n*(n-1)*(n+1)/3;
        ans += 2*(m-n-1)*n*(n-1);
        printf("%lld\n",ans);
    }
    return 0;
}




