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
typedef long long LL;

using namespace std;

char qwert[200] = "`1234567890-=~!@#$%^&*()_+qwertyuiop[]\\QWERTYUIOP{}|asdfghjkl;'ASDFGHJKL:\"zxcvbnm,./ZXCVBNM<>?";
char dvorak[200] = "`1234567890[]~!@#$%^&*(){}',.pyfgcrl/=\\\"<>PYFGCRL?+|aoeuidhtns-AOEUIDHTNS_;qjkxbmwvz:QJKXBMWVZ";

int findindex(char ch)
{
    char *p1 = qwert;
    while(*p1 != ch)
        p1++;
    return p1-qwert;
}
int main()
{
    char ch;
    int index;

    while( ( ch = getchar() ) != EOF  )
    {
        if( ch == 10)
            putchar(10);
        else if( ch == ' ')
            putchar(ch);
        else
        {
            index = findindex(ch);
            putchar(dvorak[index]);
        }
    }
}
