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

char ch[MAXN];
int main()
{
    int T;
    scanf("%d", &T);
    int len, sum;
    while(T--)
    {
        scanf("%d%d", &len, &sum);
        for(int i=1; i<=len; i++)
            ch[i] = '0';
        int l=1, r=len;

        if(sum > len*9 || (!(len&1) && (sum&1)) || ( sum==0 || (sum==1 && len>1)))
        {
            puts("-1");
            continue;
        }


        while(sum >= 18)
        {
            ch[l] = ch[r] = '9';
            sum -= 18;
            l++;
            r--;
        }

        if(sum)
        {
            if(r>l)
            {
                ch[l] = ch[r] = (sum/2)+48;
                l++;
                r--;
                sum&=1;
            }
            else if(r==l)
            {
                ch[(1+len)>>1] = sum+48;
                sum = 0;
            }
            else if(r<l)
            {

            }

            if(sum)
            {
                ch[(1+len)>>1] = sum+48;
            }
        }
        for(int i=1; i<=len; i++)
            putchar(ch[i]);
        putchar(10);
    }

    return 0;
}










