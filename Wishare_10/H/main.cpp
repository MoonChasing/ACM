#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <cmath>
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
    scanf("%d", &T);
    while(T--)
    {
        int s;
        scanf("%d",&s);
        int temp = 1+4*s;
        int m=floor(sqrt(temp)+0.5);
        if(m*m==temp)
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}









