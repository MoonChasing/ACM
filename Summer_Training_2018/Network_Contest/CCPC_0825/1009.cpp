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
struct point
{
    int x, y, v;
    bool operator < (const point & a) const
    {
        return x < a.x && y < a.y;
    }
}P[MAXN];

int dp[MAXN];
int n;
map<int, int> mp;
vector<pair<int, int> > cor[MAXN];
int cmp( point p1, point p2 ) {
    return p1.x == p2.x ? p1.y < p2.y : p1.x < p2.x;
}

int findlast( int i ) {
    int x = P[i].x;
    int y = P[i].y;
    int l = 1, r = mp[x]-1;
    while( l <= r ) {
        int mid = ( l+r ) / 2;
        int j = lower_bound(cor[mid].begin(), cor[mid].end(), make_pair(y, 0)) - cor[mid].begin();
        if( j == 0 ) {
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    l -= 1;
    int index = lower_bound(cor[l].begin(), cor[l].end(), make_pair(y, 0)) - cor[l].begin() - 1;
    return cor[l][index].second;
}


int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        mp.clear();
        for(int i=0; i<MAXN; i++)
            cor[i].clear();
        memset(dp, 0, sizeof(dp));
        scanf("%d", &n);
        for(int i=0; i<n; i++)
        {
            scanf("%d%d%d", &P[i].x, &P[i].y, &P[i].v);
        }
        P[n].x = 0;
        P[n].y = 0;
        P[n].v = 0;
        n++;
        sort(P, P+n, cmp);

        int cnt = 1;
        for(int i=0; i<n; i++)
        {
            if(mp[P[i].x] == 0)
            {
                mp[P[i].x] = cnt++;
            }
            cor[ mp[P[i].x] ].push_back(make_pair(P[i].y, i));
        }

        //cout<<findlast(3)<<endl;

        for(int i=1; i<n; i++)
        {
            int j = 0;
            if( i != 0 ) {
                j = findlast(i);
                //printf("%d", j);
            }

            if(j == 0)
                dp[i] = P[i].v;
            else
            {
                //printf(" %d+%d ", dp[j], P[i].v);
                dp[i] = max(dp[i], dp[j]+P[i].v);
            }
            //printf(" %d\n", dp[i]);
        }
        int ans = 0;
        for(int i=0; i<n; i++)
            ans = max(ans, dp[i]);
        printf("%d\n", ans);
    }
    return 0;
}











