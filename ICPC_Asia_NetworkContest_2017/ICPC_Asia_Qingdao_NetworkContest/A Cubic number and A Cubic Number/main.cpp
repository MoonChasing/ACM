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

vector<LL> a;
void init()
{
    LL ans;
    for(LL i=1; i<=577355; i++)
    {
        ans = 3*i*i-3*i+1;
        a.push_back(ans);
    }
}

int main()
{
    //freopen("C:\\Users\\Administrator\\Desktop\\in.txt", "r", stdin);
    init();
    int T;
    scanf("%d", &T);
    while(T--)
    {
        LL n;
        scanf("%I64d", &n);

        if(find(a.begin(), a.end(), n) != a.end())
            puts("YES");
        else
            puts("NO");
    }

    return 0;
}











