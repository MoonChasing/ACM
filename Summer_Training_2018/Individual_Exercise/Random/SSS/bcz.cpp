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

map<int, int> mp;
int n, m;
int x;

int main()
{
    mp.clear();
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &m);
        while(m--)
        {
            scanf("%d",&x);
            mp[x]++;
        }
    }
    for(map<int, int>::iterator it = mp.begin(); it!=mp.end(); it++)
    {
        for(int i=0; i<it->second; i++)
        {
            printf("%d ", it->first);
        }
    }
    return 0;
}














