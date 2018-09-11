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
#define MAXN 100007
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

char mp[30][30];
char key[MAXN], text[MAXN];
int keylen, textlen;
void init()
{
    for(char i = 'A'; i <= 'Z'; i++)
    {
        for(char j = 'A'; j <='Z'; j++)
        {
            mp[i-'A'][j-'A'] = 'A' + (i+j+1)%26;
        }
    }
}

int main()
{
    init();
    while(scanf("%s", key) && !(key[0]=='0' && key[1]==0))
    {
        scanf("%s", text);
        keylen = strlen(key);
        textlen = strlen(text);
        for(int i=0; i<textlen; i++)
        {
            putchar(mp[key[i%keylen]-'A'][text[i]-'A']);
        }
        putchar(10);
    }

    return 0;
}











