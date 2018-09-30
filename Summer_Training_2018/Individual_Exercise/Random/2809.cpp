#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

string test(string a)
{
    return a;
}
string LastDateofMonth(string date)
{
    int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string ret;
    ret += date[0];
    ret += date[1];

    int m = (date[0]-48)*10 + date[1]-48;
    int d = days[m];
    ret += char(d / 10 + 48);
    ret += char(d % 10 + 48);
    return ret;
}
int main()
{
    cout << LastDateofMonth("0101");
    return 0;
}
//2809











