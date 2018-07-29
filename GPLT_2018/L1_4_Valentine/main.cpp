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

string temp, a, b;
int cnt;
int main()
{
    cnt = 0;
    while(cin >> temp)
    {
        if(temp == ".")
            break;
        cnt++;
        if(cnt == 2)
            a = temp;
        if(cnt == 14)
            b = temp;
    }
    if(cnt >= 14)
        cout << a << " and " << b << " are inviting you to dinner...\n";
    else if(cnt >=2 &&cnt < 14)
        cout << a << " is the only one for you...\n";
    else
        cout<< "Momo... No one is for you ...\n";
    return 0;
}







