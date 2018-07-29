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
#define DataIn
typedef long long LL;

using namespace std;

int a,b,c,d,e;
char s1[10], s2[10], s3[10];
int op1, op2, op3;
map<char, int> mp;

int getnum(char s[])
{
    int len = strlen(s);
    int ret=0;
    for(int i=0; i<len; i++)
    {
        ret = ret*10+mp[s[i]];
    }
    return ret;
}

int main()
{
#ifdef DataIn
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt", "r", stdin);
#endif

    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s%s%s", s1, s2, s3);
        int ans = 0;
        for(a=0; a<=9; a++)
        {
            if(strlen(a)==1 && a==0 && (s1[0]=='A' || s2[0]=='A' || s3[0]=='A'))
                continue;
            mp['A'] = a;
            for(b=0; b<=9&&b!=a; b++)
            {
                if(strlen(b)!b && (s1[0]=='B' || s2[0]=='B' || s3[0]=='B'))
                    continue;
                mp['B'] = b;
                for(c=0; c<=9&&c!=a&&c!=b; c++)
                {
                    if(!c && (s1[0]=='C' || s2[0]=='C' || s3[0]=='C'))
                        continue;
                    mp['C'] = c;
                    for(d=0; d<=9&&d!=a&&d!=b&&d!=c; d++)
                    {
                        if(d==0 && (s1[0]=='D' || s2[0]=='D' || s3[0]=='D'))
                            continue;
                        mp['D'] = d;
                        for(e=0; e<=9&&e!=a&&e!=b&&e!=c&&e!=d; e++)
                        {
                            if(e==0 && (s1[0]=='E' || s2[0]=='E' || s3[0]=='E'))
                                continue;
                            mp['E'] = e;
                            op1 = getnum(s1);
                            op2 = getnum(s2);
                            op3 = getnum(s3);
                            #ifdef DEBUG
                            printf("%d   %d   %d\n", op1, op2, op3);
                            #endif // DEBUG
                            if(op1 + op2 == op3)
                                ans++;
                            if(op1 * op2 == op3)
                                ans++;
                            if(op1 - op2 == op3)
                                ans++;
                            if(op2 && op1/op2==op3 && op1%op2==0)
                                ans++;
                        }
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}












