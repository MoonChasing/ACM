#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
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

string a[MAXN];
int sum[MAXN];
int w;
int main()
{
    int cur = 0;
    char ch;
    while( (ch = getchar()) != '\n')
    {
        if(ch == ',')
        {
            cur++;
            continue;
        }
        a[cur] += ch;
    }
    cur++;

    for(int i=0; i<cur; i++)
        sum[i] = sum[i-1]+a[i].length();

    scanf("%d", &w);

    for(int i=0; i<cur;)
    {
        int j;
        for(j=i+1; j<cur; j++)
        {
            if(sum[j]-sum[i-1]>w)
            {
                break;
            }
        }
        j--;
        if(j!=cur-1)
        {
            int len = sum[j]-sum[i-1];
            int num = j-i+1;
            int space = w-len;
            int ave = space / (num-1);
            int rem = space % (num-1);
            for(int k=i; k<j; k++)
            {
                cout << a[k];
                for()
            }
        }
        else
        {

        }
    }
    return 0;
}











