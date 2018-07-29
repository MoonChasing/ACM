#include <iostream>
#include <cstdio>
#define offset 10000
#define MAXN 50005
using namespace std;

struct point
{
    int x,y;
} p[MAXN];

int main()
{
    int n;
    double area;
    double max_area = 0;
    while(scanf("%d",&n) && n!=-1)
    {
        for(int i=0; i<n; i++)
        {
            scanf("%d%d", &p[i].x, &p[i].y);
        }
        int i, j,k;
        for(i = 0; i + 2 < n; ++i)
        {
            for(j = i + 1; j < n; ++j)
            {
                for(k = j + 1; k < n; ++k)
                {
                    area = p[i].x* p[j].y - p[j].x * p[i].y + p[j].x * p[k].y - p[k].x * p[j].y + p[k].x * p[i].y - p[i].x * p[k].y;
                    if(area < 0)
                    {
                        area = -area;
                    }
                    if(max_area < area)
                    {
                        max_area = area;
                    }
                }
            }
        }
        printf("%.2f\n", max_area/2);
    }
    return 0;
}
