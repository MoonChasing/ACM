#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>
#include <utility>

#define MAXN 1e9+10
#define INF 0x3f3f3f3f
typedef long long LL;

using namespace std;

pair<int,int> a[3];
pair<int,int> b[3];
pair<int,int> p;


int main()
{
    for(int i=0; i<3; i++)
        scanf("%d%d", &a[i].first, &a[i].second);
    for(int i=0; i<3; i++)
        scanf("%d%d", &b[i].first, &b[i].second);

    return 0;
}
