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
//#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

int n, m;
char line[MAXN];
int ind;
char c;

int main()
{
    int T;
    int ans = 0;
    int notequalcnt = 0;
    scanf("%d", &T);
    while(T--)
    {
        ans = 0;
        notequalcnt = 0;

        scanf("%d%d",&n, &m);
        getchar();
        scanf("%s", line+1);
        for(int i=1,j=n; i<j; i++, j--)
        {
            if(line[i] != line[j])
                notequalcnt++;
        }
        for(int i=0; i<m; i++)
        {
            scanf("%d %c", &ind, &c);
            if(line[ind] == line[n+1-ind])
            {
                if(line[n+1-ind] != c)
                    notequalcnt++;
            }
            else
            {
                if(line[n+1-ind] == c)
                    notequalcnt--;
            }
            line[ind] = c;
            #ifdef DEBUG
                cout << notequalcnt << endl;
                #endif // DEBUG
            if(notequalcnt == 0)
                ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}









