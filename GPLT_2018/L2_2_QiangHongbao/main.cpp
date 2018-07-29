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
#define MAXN 10010
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

struct person
{
    int id, balance, num;
};

bool cmp(person a, person b)
{
    if(a.balance > b.balance)
        return true;
    else if(a.balance < b.balance)
        return false;
    else
    {
        if(a.num > b.num)
            return true;
        else if(a.num < b.num)
            return false;
        else
        {
            if(a.id < b.id)
                return true;
            else
                return false;
        }
    }
}

person pe[MAXN];
int n;

int main()
{
    scanf("%d", &n);
    int num, id, mon;
    for(int i=1; i<=n; i++)
    {
        pe[i].balance = 0;
        pe[i].id = i;
        pe[i].num = 0;
    }
    for(int i=1; i<=n; i++)
    {
        int sum = 0;
        scanf("%d", &num);
        for(int j=1; j<=num; j++)
        {
            scanf("%d%d", &id, &mon);
            pe[i].balance -= mon;
            pe[id].balance += mon;
            pe[id].num++;
        }
    }
    sort(pe+1, pe+1+n, cmp);
    for(int i=1; i<=n; i++)
        printf("%d %.2f\n", pe[i].id, pe[i].balance/100.0);

}










