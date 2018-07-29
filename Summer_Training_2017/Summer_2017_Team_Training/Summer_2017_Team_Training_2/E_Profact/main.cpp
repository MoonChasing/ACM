#include <iostream>
#include <cstdio>
#include <algorithm>

#define LL long long
#define maxn 100005
#define SIZE 21
using namespace std;

LL fact[SIZE];
LL num[maxn];
bool flag = false;
void init()
{
    fact[0] = fact[1] = 1;
    for(int i=2; i<SIZE; i++)
        fact[i] = fact[i-1]*i;
//   for(int i=2; i<SIZE; i++)
//        printf("#%d: %I64d\n",i, fact[i]);
}

void  judge(LL a, int start = 20)
{
    if(flag == true)
        return;
    if(a==1)
        flag = true;
    if(find(fact, fact+SIZE, a) != fact+SIZE)
        flag = true;
    if(flag == true)
        return;
    for(int i=start; i>=2; i--)
    {
        if(a%fact[i] ==  0)
        {
            judge(a / fact[i], i);
            judge(a, i-1);
        }
    }
}

int main()
{
    init();
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        flag = false;;
        scanf("%I64d", num+i);
        judge(num[i]);

        if( flag )
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

//251073478656000
