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
#define MAXN 1000010
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

char str[MAXN];
int a[MAXN];
int pos[MAXN];
char let[MAXN];
int len;

int main()
{
    scanf("%s", str);
    len = strlen(str);

    int cur = 0;
    int cnt = 0;

    for(int i=0, j=1; i<len;)
    {
        if(str[i] == str[j])
        {
            j++;
        }
        else
        {
            let[cur] = str[i];
            a[cur++] = j-i;
            i = j;
            j++;
        }
    }

    pos[0] = 0;
    for(int i=1; i<cur; i++)
    {
        pos[i] = pos[i-1] + a[i-1];
    }

    int anslen=-INF, anspos = 0;
    for(int i=0; i<cur-2; i++)
    {
        if(a[i] == a[i+2] && a[i] > a[i+1])
        {
            if(a[i]+a[i+2]+a[i+1] > anslen)
            {
                anslen = (a[i]<<1)+a[i+1];
                anspos = pos[i];
            }
        }
    }

    int ed = anspos+anslen;
    if(anslen == -INF)
        puts("NULL");
    else
    {
        for(int i=anspos; i<ed; i++)
            putchar(str[i]);
    }
    return 0;
}










