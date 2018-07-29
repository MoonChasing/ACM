#include <bits/stdc++.h>

using namespace std;

const int MAXN = 37;

int n, p[MAXN], a[MAXN], c[MAXN], m[MAXN], g[MAXN];
short dp[MAXN][MAXN][MAXN][MAXN][MAXN];
bool path[MAXN][MAXN][MAXN][MAXN][MAXN];
int P, A, C, M;

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d%d%d%d%d", p+i, a+i, c+i, m+i, g+i);
    scanf("%d%d%d%d", &P, &A, &C, &M);

    for(int i=n-1; i>=0; i--)
    {
        for(int ip=0; ip<=P; ip++)
        {
            for(int ia=0; ia<=A; ia++)
            {
                for(int ic=0; ic<=C; ic++)
                {
                    for(int im=0; im<=M; im++)
                    {
                        if(ip<p[i] || ia<a[i] || ic<c[i] || im<m[i])
                            dp[i][ip][ia][ic][im] = dp[i+1][ip][ia][ic][im];
                        else
                        {
                            if( dp[i+1][ip][ia][ic][im] < dp[i+1][ip-p[i]][ia-a[i]][ic-c[i]][im-m[i]] + g[i] )
                            {
                                dp[i][ip][ia][ic][im] = dp[i+1][ip-p[i]][ia-a[i]][ic-c[i]][im-m[i]] + g[i];
                                path[i][ip][ia][ic][im] = true;
                            }
                            else
                                dp[i][ip][ia][ic][im] = dp[i+1][ip][ia][ic][im];
                        }
                    }
                }
            }
        }
    }


        vector<int> ans;
        for(int i=0, ip=P, ia=A, ic=C, im=M; i<n; i++)
        {
            if(path[i][ip][ia][ic][im])
            {
                ans.push_back(i);
                ip -= p[i];
                ia -= a[i];
                ic -= c[i];
                im -= m[i];
            }
        }

        int sz = ans.size();
        printf("%d\n", sz);
        for(int i=0; i<sz; i++)
            printf("%d%c", ans[i], " \n"[i+1==sz]);
        if(sz==0)
            putchar(10);
        return 0;
    }


