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
#define MAXN 25
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

int tim;
int num;
int a, b;
priority_queue<int> que;
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n;
        scanf("%d", &n);
        for(int i=1; i<=n; i++)
        {
            scanf("%d%d", &tim, &num);
            for(int j=0; j<num; j++)
                que.push(tim);
        }

        a=b=0;
        while(!que.empty())
        {
            int t = que.top();
            que.pop();
            if(a<=b)
                a+=t;
            else
                b+=t;
        }
        printf("%d\n", max(a,b));
    }
    return 0;
}






