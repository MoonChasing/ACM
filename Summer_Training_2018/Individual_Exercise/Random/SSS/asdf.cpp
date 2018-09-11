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

int n, m, x;
vector<int> a;
int main()
{
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &m);
        while(m--)
        {
            scanf("%d", &x);
            a.push_back(x);
        }
    }
    sort(a.begin(), a.end());
    for(vector<int>::iterator it = a.begin(); it!=a.end(); it++)
    {
        printf("%d ", *it);
    }

}











