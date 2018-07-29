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
    int num;
    int q;
    scanf("%d", &q);
    int cnt = 0;
    int minn = INF;

    while(q--)
    {
        scanf("%d", &num);
        cnt += num;
        if(cnt < minn)
            minn = cnt;
    }
    if(minn >= 0)
        printf("0\n");
    else
        printf("%d\n", -minn);
    return 0;
}










