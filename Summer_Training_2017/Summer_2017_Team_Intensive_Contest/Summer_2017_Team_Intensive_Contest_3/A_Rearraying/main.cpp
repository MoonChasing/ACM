#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 200000 + 10;
const int M = 100000 + 10;

pair<int, int> lane[N], arm[M];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++)
        lane[i].first = lane[i].second = i;
    for(int i=1; i<=m; i++)
        scanf("%d%d", &arm[i].first, &arm[i].second);
    sort(arm+1, arm+m+1);

    for(int i=1; i<=m; i++)
    {
        int y = arm[i].second;
        lane[y].first = lane[y+1].first = min(lane[y].first, lane[y+1].first);
        lane[y].second = lane[y+1].second = max(lane[y].second, lane[y+1].second);
    }

    for(int i=1; i<=n; i++)
        printf("%d%c", lane[i].second-lane[i].first+1, i==n ? '\n' : ' ');
    return 0;
}
