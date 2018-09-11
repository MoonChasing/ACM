#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#define MAXN 210
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

int a, b, c;
bool vis[MAXN][MAXN];

//����һ��������͵��⣬����˼
struct node
{
    int pre, id, po1, po2, op, op1, op2, step;
};
vector<node> arr;
int bfs()
{
    queue<node> que;
    node cur = {0, 0, 0, 0, 0, 0, 0, 0};
    que.push(cur);
    arr.push_back(cur);
    vis[0][0] = true;
    int p1, p2, id, cnt = 1, step;

    while(!que.empty())
    {
        cur = que.front();

        que.pop();
        //cout << "Pre:" << arr[cur.pre].po1 << " " << arr[cur.pre].po2  << " Op: " << cur.op << cur.op1 << cur.op2 << endl << "Now: " << cur.po1 << " " << cur.po2 << endl;
        //getchar();
        if(cur.po1 == c || cur.po2 == c)
            return cur.id;

        p1 = cur.po1;
        p2 = cur.po2;
        id = cur.id;
        step = cur.step;


        if(!vis[a][p2])
        {
            vis[a][p2] = true;
            node todo = {id, cnt++, a, p2, 1, 1, 0, step+1};
            que.push(todo);
            arr.push_back(todo);
        }
        if(!vis[p1][b])
        {
            vis[p1][b] = true;
            node todo = {id, cnt++, p1, b, 1, 2, 0, step+1};
            que.push(todo);
            arr.push_back(todo);
        }
        if(!vis[0][p2])
        {
            vis[0][p2] = true;
            node todo = {id, cnt++, 0, p2, 2, 1, 0, step+1};
            que.push(todo);
            arr.push_back(todo);
        }
        if(!vis[p1][0])
        {
            vis[p1][0] = true;
            node todo = {id, cnt++, p1, 0, 2, 2, 0, step+1};
            que.push(todo);
            arr.push_back(todo);
        }
        int cur1, cur2;
        //pot1 -> pot2
        cur1 = p1-(b-p2);
        if(cur1 < 0)
            cur1 = 0;
        cur2 = p2+p1;
        if(cur2 > b)
            cur2 = b;

        if(!vis[cur1][cur2])
        {
            vis[cur1][cur2] = true;
            node todo = {id, cnt++, cur1, cur2, 3, 1, 2, step+1};
            que.push(todo);
            arr.push_back(todo);
        }

        //pot2 -> pot1
        cur2 = p2 - (a-p1);
        if(cur2 < 0)
            cur2 = 0;
        cur1 = p1+p2;
        if(cur1 > a)
            cur1 = a;

        if(!vis[cur1][cur2])
        {
            vis[cur1][cur2] = true;
            node todo = {id, cnt++, cur1, cur2, 3, 2, 1, step+1};
            que.push(todo);
            arr.push_back(todo);
        }
    }

    return -1;
}
bool cmp(node n1, node n2)
{
    return n1.id < n2.id;
}
void solve()
{
    //sort(arr.begin(), arr.end(), cmp);
    stack<node> st;
    int last = bfs();
    int cnt = 0;
    while(last != 0 && last != -1)
    {
        st.push(arr[last]);
        last = arr[last].pre;
        cnt++;
    }

    if(last == -1)
    {
        puts("impossible");
        return;
    }
    printf("%d\n", cnt);
    node cur;
    while(!st.empty())
    {
        cur = st.top();
        st.pop();
        if(cur.op == 1)
            printf("FILL(%d)\n", cur.op1);
        else if(cur.op == 2)
            printf("DROP(%d)\n", cur.op1);
        else if(cur.op == 3)
            printf("POUR(%d,%d)\n", cur.op1, cur.op2);
    }
}
int main()
{
    scanf("%d%d%d", &a, &b, &c);
    solve();
    return 0;
}












