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
#define MAXN 60
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

int n;
int rec[MAXN][4], cur[4], cika[4][7];
int a[10][7] = {
    {1,1,1,0,1,1,1},
    {0,0,0,0,0,1,1},
    {0,1,1,1,1,1,0},
    {0,0,1,1,1,1,1},
    {1,0,0,1,0,1,1},
    {1,0,1,1,1,0,1},
    {1,1,1,1,1,0,1},
    {0,0,1,0,0,1,1},
    {1,1,1,1,1,1,1},
    {1,0,1,1,1,1,1}
};

bool next(int &a, int &b, int &c, int &d)
{
    d++;
    if(d>=10)
    {
        d = 0;
        c++;
    }
    if(c>=6)
    {
        c=0;
        b++;
    }
    if(b>=10)
    {
        b=0;
        a++;
    }
    if(10*a+b>=24)
    {
        a=0;
        b=0;
        return 0;
    }
    return 1;
}

bool judge()
{
    memset(cika, -1, sizeof(cika));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<4; j++)
        {
            for(int k=0; k<7; k++)
            {
                if(!a[ cur[j] ][k])
                {
                    if(a[ rec[i][j] ][k])
                        return false;
                }
                else
                {
                    if(cika[j][k] < 0)
                        cika[j][k] = a[ rec[i][j] ][k];
                    else if(cika[j][k] != a[rec[i][j]][k])
                        return false;
                }
            }
        }
        next(cur[0], cur[1], cur[2], cur[3]);
    }
    return true;
}

int main()
{
    int a, b, c, d;
    while(1 == scanf("%d", &n))
    {
        for(int i=0; i<n; i++)
            scanf("%1d%1d:%1d%1d", &rec[i][0], &rec[i][1], &rec[i][2], &rec[i][3]);
        bool first = true;
        a = b = c = d = 0;
        do
        {
            cur[0] = a; cur[1] = b; cur[2]=c; cur[3] = d;
            if(judge())
            {
                if(!first)
                    putchar(' ');
                first = false;
                printf("%d%d:%d%d", a, b, c, d);
            }
        }while(next(a, b, c, d));
        puts(first ? "none" : "");
    }
    return 0;
}









