#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
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

int trans(char ch)
{
    if(ch>='A' && ch<='Z')
        return (ch-'A')<<1;
    if(ch>='a' && ch<='z')
        return (ch-'a')<<1|1;
    if(ch>='0' && ch<='9')
        return ch+12;
}

struct node
{
    string str;
    node();
    node(string _a)
    {
        str = _a;
    }
    bool operator < (const node & a) const
    {
        if(str.length() != a.str.length())
        {
            return str.length() < a.str.length();
        }
        else
        {
            int len = str.length();
            for(int i=0; i<len; i++)
            {
                if(str[i] != a.str[i])
                    return trans(str[i]) < trans(a.str[i]);
            }
        }
    }
};
vector<node> vec;

int main()
{
//    for(int i=0; i<26; i++)
//    {
//        cout << char('A'+i) << " : " << trans('A'+i) << endl;
//        cout << char('a'+i) << " : " << trans('a'+i)<< endl;
//    }
    string abc;
    while(cin >> abc)
    {
        vec.push_back(node(abc));
    }
    sort(vec.begin(), vec.end());
    for(vector<node>::iterator it = vec.begin(); it!=vec.end(); it++)
    {
        cout << (*it).str << " \n"[it==vec.end()-1];
    }
    return 0;
}











