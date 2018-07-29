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
#define MAXN 1005
#define INF 0x3f3f3f3f
//#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

typedef pair<int, int> P;
int w[MAXN];
int path[MAXN][2005];
bool dp[MAXN][2005];

map<int, string> good;
int wkit, m;
int weight;
int need;
vector<string> vec;

void work(int zl)
{
    for(int i=zl; i<=2000; i++)
    {
        if(dp[m][i])
        {
            int wei = i;
            for(int j=m-1; j>=0; j--)
            {
                if(path[j+1][wei] == wei)
                    continue;
                else
                {
                    wei = path[j+1][wei];
                    vec.push_back(good[j]);
                }
            }
            break;
        }
    }
}

int main()
{
    scanf("%d%d", &wkit, &m);
    string goodname;
    char name[15];
    for(int i=0; i<m; i++)
    {
        scanf("%s%d", name, &w[i]);
        goodname = name;
        good[i] = goodname;
    }

    memset(dp, false, sizeof(dp));
    dp[0][0] = true;

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<=2000; j++)
        {
            if( j-w[i] >= 0 && dp[i][j-w[i]] )
            {
                dp[i+1][j] = dp[i][j-w[i]];
                path[i+1][j] = j - w[i];
            }

            if( dp[i][j] )
            {
                dp[i+1][j] = true;
                path[i+1][j] = j;
            }
        }
    }
    #ifdef DEBUG
    for(int i=1; i<=m; i++)
    {
        for(int j=0; j<=2000; j++)
        {
            if(dp[i][j])
                cout << '(' << i << ',' << j << ')' << ' ';

        }
        putchar(10);
    }
    #endif // DEBUG
    int n;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &weight);
        need = (weight-1)/2+1 - wkit;
        if(need == 0)
        {
            puts("0");
            continue;
        }
        work(need);
        if(vec.size() == 0)
        {
            puts("-1");
            continue;
        }
        printf("%d ",vec.size());
        for(int i=0; i<vec.size(); i++)
        {

            cout << vec[i] << ((i == vec.size()-1) ? '\n' : ' ');
        }
        vec.clear();
    }
    return 0;
}












