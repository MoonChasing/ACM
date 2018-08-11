#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include <iomanip>
#include <cstdio>
using namespace std;

const int N = 180;
const int N2 = 1000;

int maxlen[N+1];
vector<string> words[N2];

int main()
{
    freopen("alignment.in", "r", stdin);
    freopen("alignment.out", "w", stdout);
    string s, t;

    memset(maxlen, 0, sizeof(maxlen));

    int lencount = 0;
    while(getline(cin, s))
    {
        stringstream ss(s);

        int i = 0;
        while(ss >> t)
        {
            maxlen[i] = max((int)t.length(), maxlen[i]);
            words[lencount].push_back(t);
            i++;
        }
        lencount++;
    }

    cout << setiosflags(ios::left);
    for(int i=0; i<lencount; i++)
    {
        int j;
        for(j=0; j<(int)words[i].size()-1; j++)
            cout << setfill(' ') << setw(maxlen[j] + 1) << words[i][j];
        cout << words[i][j] << endl;
    }

    return 0;
}

