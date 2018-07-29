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

struct block
{
    int w, l, h;
    bool operator < (block a)
    {
        return w<a.w || (w == a.w && l < a.w);
    }
};

block bb[100];
int data[3];
int n;
int kiss;
int dp[100];
int main()
{
    kiss = 1;
    while(cin >> n && n)
    {
        int cnt = 0;
        for(int i=1; i<=n; i++)
        {
            cin >> data[0] >> data[1] >> data[2];
            sort(data, data+3);
            bb[cnt].w = data[0];
            bb[cnt].l = data[1];
            bb[cnt++].h = data[2];

            bb[cnt].w = data[0];
            bb[cnt].l = data[2];
            bb[cnt++].h = data[1];

            bb[cnt].w = data[1];
            bb[cnt].l = data[2];
            bb[cnt++].h = data[0];
        }
        sort(bb, bb+cnt);
        for(int i=0; i<cnt; i++)
            dp[i] = bb[i].h;

        int ans = 0;
        for(int i=1; i<cnt; i++)
        {
            int maxx=0;
            for(int j=i-1; j>=0; j--)
                if(bb[i].w>bb[j].w&&bb[i].l>bb[j].l)
                    maxx = max(maxx, dp[j]);

            dp[i]+=maxx;
            ans=max(ans,dp[i]);
        }
        printf("Case %d: maximum height = %d\n", kiss, ans);
        kiss++;
    }
    return 0;
}

