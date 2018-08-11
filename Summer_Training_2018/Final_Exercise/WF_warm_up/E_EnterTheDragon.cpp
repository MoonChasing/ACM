#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e6+7;

int T, n, m, lastTime[MAXN], ans[MAXN];
set<int> todo;

int main()
{
    scanf("%d", &T);
    while(T--)
    {
        memset(lastTime, 0, sizeof(lastTime));
        memset(ans, 0, sizeof(ans));
        todo.clear();
        int lake;

        scanf("%d%d", &n, &m);
        bool yes = true;
        for(int i=0; i<m; i++)
        {
            scanf("%d", &lake);
            if(!yes)
                continue;
            if(lake == 0)
                todo.insert(i);
            else
            {
                ans[i] = -1;
                set<int>::iterator it = todo.lower_bound(lastTime[lake]);
                if(it == todo.end())
                    yes = false;
                else
                {
                    ans[*it] = lake;
                    lastTime[lake] = i;
                    todo.erase(it);
                }
            }
        }

        if(!yes)
            puts("NO");
        else
        {
            puts("YES");
            for(int i=0; i<m; i++)
                if(ans[i] >= 0)
                printf("%d%c", ans[i], " \n"[i==m-1]);
        }
    }
    return 0;
}
