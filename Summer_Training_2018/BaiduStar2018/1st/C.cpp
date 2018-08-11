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
#define MAXN 10010
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

int N, K;
int cnt;
char ch[MAXN];
int dp[MAXN];
int main()
{
    while(~scanf("%d%d", &N, &K))
    {
        queue<int> only1, kt, zj, jw;
        memset(ch, 0, sizeof(ch));
        scanf("%s", ch);
        bool flag = true, have0 = false;
        cnt = 0;
        if(ch[0] == 48)
            flag = false;
        for(int i=0; i<N; i++)
        {
            if(ch[i] == '1')
            {
                cnt++;
            }
            else if(ch[i] == '0')
            {
                have0 = true;
                if(flag)
                {
                    kt.push(cnt);
                    flag = false;
                }
                else
                {
                    if(cnt)
                        zj.push(cnt);
                }
                cnt = 0;
            }
        }
        if(cnt && !have0)
            only1.push(cnt);
        else if(cnt)
            jw.push(cnt);

        cout << only1.size() << kt.size() << zj.size() << jw.size();
        if(!only1.empty())
            dp[0] = only1.front();
        else
            dp[0] = kt.front();
        for(int i=1; i<=k; i++)
        {

        }
    }
    return 0;
}










