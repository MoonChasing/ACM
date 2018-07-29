#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
using namespace std;
const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };
struct Node
{
    int rowA, colA, rg, cg, cnt;
    Node() : rowA(0), colA(0), rg(0), cg(0), cnt(0) {}
    Node(int ra, int ca, int rg, int cg, int cnt)
    {
        rowA = ra; colA = ca;
        this->rg = rg; this->cg = cg;
        this->cnt = cnt;
    }
};
int N, M;
char maze[30][30];
bool walk[30][30][30][30];
int main()
{
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; ++i)
        scanf("%s", maze[i]);
    Node cika;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (maze[i][j] == 'A')
            {
                cika.rowA = i; cika.colA = j;
                maze[i][j] = '.';
            }
            else if (maze[i][j] == 'G')
            {
                cika.rg = i; cika.cg = j;
                maze[i][j] = '.';
            }
        }
    }
    cika.cnt = 0;
    walk[cika.rowA][cika.colA][cika.rg][cika.cg] = true;
    queue<Node> que;
    que.push(cika);
    Node t;
    int r1, c1, r2, c2;
    int ans = -1;
    while (!que.empty())
    {
        t = que.front();
        que.pop();
        if (maze[t.rowA][t.colA] == 'P')
        {
            ans = t.cnt;
            break;
        }
        for (int i = 0; i < 4; ++i)
        {
            r1 = t.rowA + dx[i];
            c1 = t.colA + dy[i];
            if (r1 >= 0 && r1 < N&&c1 >= 0 && c1 < M&&maze[r1][c1] != 'X' && (r1 != t.rg || c1 != t.cg))
            {
                bool guard = false;
                if (t.cg < c1)
                {
                    c2 = t.cg + 1; r2 = t.rg;
                    if (c2 == c1&&r2 == r1)
                        continue;
                    if (maze[r2][c2] != 'X')
                    {
                        guard = true;
                    }
                }
                else if (t.cg > c1)
                {
                    c2 = t.cg - 1; r2 = t.rg;
                    if (c2 == c1&&r2 == r1)
                        continue;
                    if (maze[r2][c2] != 'X')
                    {
                        guard = true;
                    }
                }
                if (!guard)
                {
                    if (t.rg < r1)
                    {
                        r2 = t.rg + 1; c2 = t.cg;
                        if (c2 == c1&&r2 == r1)
                            continue;
                        if (maze[r2][c2] != 'X')
                        {
                            guard = true;
                        }
                    }
                    else if (t.rg>r1)
                    {
                        r2 = t.rg - 1; c2 = t.cg;
                        if (c2 == c1&&r2 == r1)
                            continue;
                        if (maze[r2][c2] != 'X')
                        {
                            guard = true;
                        }
                    }
                }
                if (guard == false)
                {
                    r2 = t.rg; c2 = t.cg;
                }
                if (!walk[r1][c1][r2][c2])
                {
                    que.push(Node(r1, c1, r2, c2, t.cnt + 1));
                    walk[r1][c1][r2][c2] = true;
                }
            }
        }
        if (ans > -1)
            break;
    }
    printf("%d\n", ans);
    return 0;
}
