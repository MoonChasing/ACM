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

struct P
{
    int x,y,z;
    bool operator == (P p1)
    {
        return x==p1.x && y==p1.y && z==p1.z;
    }
    bool operator != (P p1)
    {
        return !(*this == p1);
    }
    friend istream& operator >> (istream& in, P& p)
    {
        in >> p.x >> p.y >> p.z;
    }
};

void move(P &p, int x, int y, int z)
{
    if(x)
        p.x += x;
    else if(y)
        p.y += y;
    else if(z)
        p.z += z;
}

P temp1, temp2;
bool canmove(P p1, P p2, int x, int y, int z, int a, int b, int c)
{
    temp1 = p1;
    temp2 = p2;
    move(temp1, x, y, z);
    move(temp2, a, b, c);
    if(temp1 == p2  && temp2 == p1)
        return false;
    else
        return true;
}

struct vec
{
    int x,y,z;

    vec(int a, int b, int c)
    {
        x = a > 0 ? 1 : (a == 0) ? 0 : -1;
        y = b > 0 ? 1 : (b == 0) ? 0 : -1;
        z = c > 0 ? 1 : (c == 0) ? 0 : -1;
    }

    vec(P p1, P p2)
    {
        int a = p2.x - p1.x, b = p2.y-p1.y, c = p2.z-p1.z;
        x = a > 0 ? 1 : (a == 0) ? 0 : -1;
        y = b > 0 ? 1 : (b == 0) ? 0 : -1;
        z = c > 0 ? 1 : (c == 0) ? 0 : -1;
    }
};

int main()
{
    P abegin, aend, bbegin, bend;
    cin >> abegin >> aend >> bbegin >> bend;
    vec vec_a(abegin, aend);
    vec vec_b(bbegin, bend);
    P cur_a = abegin, cur_b = bbegin;
    while(cur_a != aend || cur_b != bend)
    {
        if(cur_a.x != aend.x)
        {

        }
    }
    return 0;
}












