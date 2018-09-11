#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 1008;
vector<int>mp[maxn];
int color[maxn];

bool bfs(int s)
{
    color[s] = 0; //连通分支的起点可以染1也可以染0
    queue<int>q;
    q.push(s);
    while (!q.empty())
    {
        s = q.front();
        q.pop();
        for (int i = 0; i < (int)mp[s].size(); i ++) {
          int t = mp[s][i];
          if (color[t] == -1) color[t] = !color[s], q.push(t); //如果相邻顶点未被染色，则加入
                                                   //队列。
          if (color[t] == color[s]) { //如果相邻顶点染相同颜色，则不是二分图。
            return false;
          }
        }
    }
    return true;
}
int main()
{
    int T, n, m;
    scanf("%d", &T);

    while (T--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i ++) mp[i].clear();
        memset(color, -1, (n+1)*sizeof(color[0]));
        for (int i = 0; i < m; i ++) {
            int x, y;
            cin >> x>>y;
            mp[x].push_back(y); //无向图存储两条边
            mp[y].push_back(x);
        }
        int flag = true; //初始化无向图是二分图
        for (int i = 1; i <= n; i ++) {
            if (color[i] == -1 && !bfs(i)) { //对每个连通分支染色，如果两个相邻的点
                    //颜色相同，则不是二分图。
                flag = false;
                break;
            }
        }
        if (!flag) cout <<"No"<<endl;
        else
            cout <<"Yes"<<endl;
    }
    return 0;
}
