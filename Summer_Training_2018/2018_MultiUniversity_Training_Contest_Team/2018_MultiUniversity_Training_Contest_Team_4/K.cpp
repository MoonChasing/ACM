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
#define MAXN 505
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

char expers[MAXN];
int len;

bool isop(char ch)
{
    return ch == '+' || ch == '*';
}

char * solve()
{
    if(expers[0] == '?')
        expers[0] = '1';

    if(isop(expers[0]) || isop(expers[len-1]) || (expers[0] == 48 && (isdigit(expers[1]) && expers[1]!=48) ) )
        return "IMPOSSIBLE";
    //char digfirst;
    for(int i=1; i<len ; i++)
    {
        if(expers[i] == '?')
        {
            if(expers[i-1] == 48)
            {
                if(i==1)
                    expers[1] = '+';
                if(i-2>0 && isdigit(expers[i-2]))
                    expers[i] = '1';
                if(expers[i+1] == 48)
                    expers[i] = '+';
                if(expers[i] == '?')
                    return "IMPOSSIBLE";
            }
            else
                expers[i] = '1';
        }

        //puts(expers);

        //Á¬×ÅµÄ·ûºÅ
        if(isop(expers[i-1]) && isop(expers[i]))
            return "IMPOSSIBLE";


        if(( isop(expers[i-1]) || (i==1 && expers[0] == '0') ) && expers[i] == 48 )
        {
            //cout << i << endl;
            if( i!=len-1 && ( expers[i+1]!='?' && !isop( expers[i+1] ) ) )
                return "IMPOSSIBLE";
            if( (i==1 && expers[0] == '0') && i==len-1)
                return "IMPOSSIBLE";
        }
    }
    if(expers[0] == 48 &&  expers[1] == 48)
        return "IMPOSSIBLE";
    if(isop(expers[len-1]))
        return "IMPOSSIBLE";
    return expers;
}
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%s", expers);
        len = strlen(expers);

        puts(solve());
    }
    return 0;
}











