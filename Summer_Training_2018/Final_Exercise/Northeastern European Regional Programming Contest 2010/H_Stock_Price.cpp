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

int T, n;
struct sell
{
    int price, num;
    bool operator < (const sell& x) const
    {
        return price > x.price;
    }
};

struct buy
{
    int price, num;
    bool operator < (const buy& x) const
    {
        return price < x.price;
    }
};

priority_queue<sell> sellque;
priority_queue<buy> buyque;
char ch[10];

sell s;
buy b;
int last;
int oknum;

void update()
{
    while( !sellque.empty() && !buyque.empty() && buyque.top().price >= sellque.top().price)
    {
        b = buyque.top();   buyque.pop();
        s = sellque.top();  sellque.pop();
        last = s.price;
        oknum = min(b.num, s.num);
        b.num -= oknum;
        s.num -= oknum;
        if(b.num > 0)
            buyque.push(b);
        if(s.num > 0)
            sellque.push(s);
    }
}


void print()
{
	if (sellque.empty()) printf("- ");
	else printf("%d ", sellque.top().price);
	if (buyque.empty()) printf("- ");
	else printf("%d ", buyque.top().price);
	if (last == -1) printf("-\n");
	else printf("%d\n", last);
}

int main()
{
    scanf("%d", &T);
    while(T--)
    {
        while(!buyque.empty())
            buyque.pop();
        while(!sellque.empty())
            sellque.pop();
        last = -1;

        scanf("%d", &n);

        int num, price;

        for(int i=0; i<n; i++)
        {
            scanf("%s %d shares at %d", ch, &num, &price);
            if(ch[0] == 'b')
                buyque.push(buy{price, num});
            else if(ch[0] == 's')
                sellque.push(sell{price, num});
            update();
            print();
        }
    }
    return 0;
}









