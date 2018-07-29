#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <vector>
#include <utility>
#include <algorithm>
#define MAXN 1010
#define INF 0x3f3f3f3f
#define DEBUG
//#define DataIn
typedef long long LL;

using namespace std;
int n,m;

int seat[MAXN][MAXN];
int kiss = 1;
int main()
{
    #ifdef DataIn
	freopen("C:\\Users\\Administrator\\Desktop\\in.txt", "r", stdin);
    #endif

    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &n, &m);

        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                seat[i][j] = 1;

        int foo;
        scanf("%d", &foo);
        int x,y;
        while(foo--)
        {
            scanf("%d%d", &x, &y);
            seat[x][y] = 0;
        }

        int cnt = 0;
        int minn = 0, maxx = 0;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(seat[i][j])
                    cnt++;
                else
                {
                    if(cnt == 0)
                    {}
                    else if(cnt == 1)
                    {
                        minn++;
                        maxx++;
                        cnt = 0;
                    }
                    else
                    {
                        minn += (cnt+2)/3;
                        maxx += (cnt+1)/2;
                        cnt = 0;
                    }
                }
            }

            if(cnt == 0)
                continue;
            else if(cnt == 1)
            {
                minn++;
                maxx++;
                cnt = 0;
            }
            else
            {
                minn += (cnt+2)/3;
                maxx += (cnt+1)/2;
                cnt = 0;
            }
        }

        printf("Case #%d: %d %d\n", kiss++, maxx, minn);
    }
    return 0;
}










