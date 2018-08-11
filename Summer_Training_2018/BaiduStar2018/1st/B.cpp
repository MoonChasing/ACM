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
#define MAXN 150003
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

deque<int> que[MAXN];
int N, Q;
int op, u, v, w, val, tmp;

void read(int &x)
{
	char ch = getchar();x = 0;
	for (; ch < '0' || ch > '9'; ch = getchar());
	for (; ch >='0' && ch <= '9'; ch = getchar()) x = (x<<3) + (x<<1) + ch - 48;
}
int main()
{
    read(N), read(Q);
    while(Q--)
    {
        read(op);
        if(op == 1)
        {
            read(u), read(w), read(val);
            if(w == 0)
                que[u].push_front(val);
            else
                que[u].push_back(val);
        }
        else if(op == 2)
        {
            read(u), read(w);
            if(que[u].empty())
            {
                puts("-1");
                continue;
            }
            if(!w)
            {
                printf("%d\n", que[u].front());
                que[u].pop_front();
            }
            else
            {
                printf("%d\n", que[u].back());
                que[u].pop_back();
            }
        }
        else if(op == 3)
        {
            read(u), read(v), read(w);
            if(!w)
            {
                while(!que[v].empty())
                {
                    tmp = que[v].front();
                    que[v].pop_front();
                    que[u].push_back(tmp);
                }
            }
            else
            {
                while(!que[v].empty())
                {
                    tmp = que[v].back();
                    que[v].pop_back();
                    que[u].push_back(tmp);
                }
            }
        }
    }
    return 0;
}












