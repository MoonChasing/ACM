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

int adj[7][4]= {{0,0,0,0},{2,3,4,5},{1,3,4,6},{1,2,5,6},{1,2,5,6},{1,3,4,6},{2,3,4,5}};
int sco[7];
int main()
{
    int a,b,c;
    int duizhang, wo;
    int ans = 0;
    while(~scanf("%d%d%d", &a, &b, &c))
    {
        ans = 0;
        for(int i=1; i<=6; i++)
        {
            memset(sco, 0, sizeof(sco));
            for(int j=0; j<4; j++)
            {
                int v = adj[i][j];
                sco[v]--;
            }

            duizhang = sco[a]+sco[b]+sco[c];
            wo = sco[1]+sco[2]+sco[3]+sco[4]+sco[5]+sco[6] - duizhang;
            if(wo > duizhang)
            {
                ans = i;
                break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}








