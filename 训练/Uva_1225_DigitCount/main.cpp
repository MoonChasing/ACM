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

int a[10];
//int main()
//{
//    int T;
//    int b;
//    scanf("%d", &T);
//    while(T--)
//    {
//        memset(a, 0, sizeof(a));
//        scanf("%d", &b);
//
//        for(int i=1; i<=b; i++)
//        {
//            for(int j=i; j; j /= 10)
//            {
//                a[j%10]++;
//            }
//        }
//
//        for(int i=0; i<9; i++)
//            printf("%d ", a[i]);
//        printf("%d\n", a[9]);
//    }
//    return 0;
//}
//
int main()
{
    for(int i=1; i<=10; i++)
        printf("%d:%d\n",i, i^9);
    return 0;
}







