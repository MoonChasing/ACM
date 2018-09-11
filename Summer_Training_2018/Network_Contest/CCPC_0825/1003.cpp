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

int main()
{
    int T;
    int p;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &p);
        for(int i=0; i<p; i++)
        {
            printf("%d", i);
            for(int j=1; j<p; j++)
                printf(" %d", (i+j)%p);
            putchar(10);
        }
        for(int i=0; i<p; i++)
        {
            printf("0");
            for(int j=1; j<p; j++)
                printf(" %d", (i*j)%p);
            putchar(10);
        }
    }
    return 0;
}












