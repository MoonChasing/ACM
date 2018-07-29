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
#define DEBUG
//#define DataIn
typedef long long LL;

using namespace std;

int main()
{
    #ifdef DataIn
	freopen("C:\\Users\\Administrator\\Desktop\\in.txt", "r", stdin);
    #endif

    int bian[5];
    for(int i=0; i<5; i++)
        scanf("%d", bian+i);
    sort(bian, bian+5);
    int cnt=0;
    for(int i=0; i<3; i++)
    {
        for(int j=i+1; j<4; j++)
        {
            for(int k=j+1; k<5; k++)
                if(bian[i]+bian[j]>bian[k])
                    cnt++;
        }
    }
    printf("%d\n", cnt);
}












