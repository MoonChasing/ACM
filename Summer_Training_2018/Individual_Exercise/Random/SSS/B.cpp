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
#define MAXN 10000010
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

struct node
{
    int key, value, times;
    bool operator < (const node & a) const
    {
        return times < a.times;
    }
};

map<int, int> mp; //key value

set<node> cika;

int maxsz;
char ch;

int main()
{
    scanf("%d", &maxsz);
    getchar();
    int key, val;
    node temp;

    while( ~(ch = getchar()))
    {
        if(ch == 'p')
        {
            scanf("%d%d", &key, &val);
            getchar();

            if(mp[key] != 0)    //cun zai
            {
                mp[key] = val;
            }
            else                            //bu cunzai
            {
                if(mp.size() == maxsz)
                {
                    mp.erase(mp.begin());
                }
                temp.value = val;
                temp.times = 1;
                mp[key] = temp;
            }
        }
        else
        {
            scanf("%d", &key);
            if(mp[key] == 0)
                printf("-1");
            else
            {
                printf("%d\n", mp[key]);
            }
        }
    }
    return 0;
}












