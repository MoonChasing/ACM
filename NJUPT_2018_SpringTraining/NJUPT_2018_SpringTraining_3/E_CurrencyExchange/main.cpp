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

struct edge
{
    int u, v ;
    double r, c ;
} e[300];

int n, m, s ;
double cap ;
int cnt = 0 ;
double d[300] ;

bool Bellman_ford()
{
    for (int i = 1 ; i <= n ; i++)
        d[i] = 0 ;
    d[s] = cap ;
    bool flag ;
    for (int i = 1 ; i <= n ; i++)
    {
        flag = 1 ;
        for (int j = 0 ; j < cnt ; j++)
        {
            if (d[e[j].v] < ( d[e[j].u] - e[j].c ) * e[j].r )
            {
                flag = 0 ;
                d[e[j].v] = ( d[e[j].u] - e[j].c ) * e[j].r ;
            }
        }
        if (flag)
            return false ;
    }

    return true ;
}

int main ()
{
    scanf ("%d%d%d%lf", &n, &m, &s, &cap) ;
    while (m--)
    {
        scanf ("%d%d%lf%lf", &e[cnt].u, &e[cnt].v, &e[cnt].r, &e[cnt].c) ;
        cnt++;
        e[cnt].u = e[cnt - 1].v, e[cnt].v = e[cnt - 1].u ;
        scanf ("%lf%lf", &e[cnt].r, &e[cnt].c) ;
        cnt++;
    }
    if (Bellman_ford())
        puts ("YES") ;
    else
        puts ("NO") ;

    return 0 ;
}
