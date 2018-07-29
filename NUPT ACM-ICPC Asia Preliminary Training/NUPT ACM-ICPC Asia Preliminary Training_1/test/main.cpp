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
#define MAXN 200010
#define INF 0x3f3f3f3f
#define DEBUG
//#define DataIn
typedef long long LL;

using namespace std;

int main()
{
    #ifdef DataIn
	freopen("C:\\Users\\Administrator\\Desktop\\in.txt", "r", stdin);
    #endif // DataIn

    int T,n,m,l;
    int stone[MAXN];
    scanf("%d",&T);

    for(int kiss=1; kiss <= T; kiss++)
    {
        scanf("%d%d%d", &n, &m, &l);
        for(int i=0; i<n; i++)
        {
            scanf("%d", stone+i);
        }
        stone[n++] = m;

        std::sort(stone, stone+n);
        int ans = 0, jump = l, now = 0;
        for(int i=0; i<n; i++)
        {
            int d = stone[i] - now;
            if(d+jump <= l)
                jump += d;
            else if(d <= l)
            {
                jump = d;
                ans++;
            }
            else
            {
                int cnt = d/(l+1);
                ans += 2*cnt;
                int rest = d%(l+1);
                if(rest+jump<= l)
                    jump+=rest;
                else
                {
                    ans++;
                    jump = rest;
                }
            }
            now = stone[i];
        }
        printf("Case #%d: %d\n", kiss, ans);
    }
    return 0;
}












