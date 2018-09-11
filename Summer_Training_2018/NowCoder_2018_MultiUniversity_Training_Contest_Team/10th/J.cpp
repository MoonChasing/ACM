#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#define MAXN 100010
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

string tmp;
string ans;
vector<string> dat;
vector<int> letter[30];
int n;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int T;
    //scanf("%d", &T);
    cin >> T;
    while(T--)
    {
        dat.clear();
        for(int i=0; i<26; i++)
            letter[i].clear();

        cin >> n;
        for(int i=0; i<n; i++)
        {
            cin >> tmp;
            dat.push_back(tmp);
        }

        for(int i=0; i<n; i++)
        {
            int len = letter[i].size();
            int pos ;
            for(int i=0; i<len; i++)
            {

            }
        }
    }
    return 0;
}












#ifdef DataIn
	freopen("C:\\Users\\Administrator\\Desktop\\in.txt", "r", stdin);
#endif
