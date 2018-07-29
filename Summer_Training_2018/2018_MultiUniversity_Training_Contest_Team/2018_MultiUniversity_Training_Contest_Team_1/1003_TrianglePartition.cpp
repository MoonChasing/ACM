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
#define MAXN 3005
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

int n;
struct point
{
    int id, x, y;
    bool operator < (point p)
    {
        if(x < p.x)
            return true;
        else if(x == p.x)
        {
            if(y < p.y)
                return true;
            else
                return false;
        }
        else
            return false;
    }
}P[MAXN];

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i=0; i<3*n; i++)
        {
            scanf("%d%d", &P[i].x, &P[i].y);
            P[i].id = i+1;
        }

        sort(P, P+3*n);

        for(int i=0; i<3*n; i++)
        {
            printf("%d ", P[i].id);
            if(i+1%3==0)
                putchar(10);
        }
    }
    return 0;
}










