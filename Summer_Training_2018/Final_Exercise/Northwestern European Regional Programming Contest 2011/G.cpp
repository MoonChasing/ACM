#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#define MAXN 107
#define MAXM 1007
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

int n, m, tot;
bool vis[MAXN];
double d[MAXN][MAXN];

struct person
{
    int x, y;
    string name;
} P[MAXN];

map<string, int> mp;

double getdis(int x, int y)
{
    double x11 = P[x].x - P[y].x;
    double y21 = P[x].y - P[y].y;
    return sqrt(x11*x11 + y21*y21);
}

void init()
{
    tot = 0;
    mp.clear();
    memset(vis, false, sizeof vis);
    for(int i=0; i<=n; i++)
        for(int j=0; j<=n; j++)
            if(i == j)
                d[i][j] = 0;
            else
                d[i][j] = INF;
}

void floyd()
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (d[i][j] > d[i][k] + d[k][j])
                {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int T;
    cin >> T;
    while(T--)
    {
        cin >> n >> m;
        init();
        for(int i=1; i<=n; i++)
        {
            cin >> P[i].name >> P[i].x >> P[i].y;
            mp[P[i].name] = i;
        }

        string s1, s2, s3, temp;
        int id1, id2, id3;

        for(int i=1; i<=m; i++)
        {
            cin >> s1 >> temp >> s2 >> temp >> temp >> s3;
            id1 = mp[s1];
            id2 = mp[s2];
            id3 = mp[s3];
            vis[id2] = vis[id3] = true;
            double dis = getdis(id1, id3) - getdis(id1, id2);
            if(dis < d[id2][id3])
                d[id2][id3] = dis;
        }

        floyd();

        int flag = true;
        for(int i=1; i<=n; i++)
        {
            if(vis[i])
                tot++;
            if(d[i][i] < 0)
            {
                flag = false;
                break;
            }
        }

        if(!flag)
        {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }

        int ans[MAXN], cnt=0;
        while(tot--)
        {
            for(int i=1; i<=n; i++)
            {
                if(!vis[i])
                    continue;
                flag = true;
                for(int j=1; j<=n; j++)
                {
                    if(i == j)
                        continue;
                    if(vis[j] && d[i][j] >= 0)
                        flag = false;
                }
                if(flag)
                {
                    ans[cnt++] = i;
                    vis[i] = false;
                    break;
                }
            }
            if(!flag)
                break;
        }

        if(tot!=-1)
        {
            cout << "UNKNOWN" << endl;
            continue;
        }

        for(int i=0; i<cnt; i++) {
            if( i!= 0) {

                cout<<" ";
            }
            cout << P[ans[i]].name;
        }
        cout<<endl;
    }
    return 0;
}












