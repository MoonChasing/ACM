#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <vector>
#include <utility>
#include <algorithm>
#define MAXN 100010
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

struct card
{
    int rank;
    int suit;

    bool operator < (struct card c)
    {
        return rank < c.rank;
    }
    bool operator > (card c)
    {
        return rank > c.rank;
    }
    bool operator == (card c)
    {
        return rank==c.rank && suit == c.suit;
    }
};

card hand[10];

int cnt[10];
int n,m;
int a1,b1,a2,b2;

bool ok1()
{
    int se = hand[1].suit;
    for(int i=2; i<=5; i++)
        if(hand[i].suit != se)
            return false;
    for(int i=2; i<=5; i++)
        if(hand[i].rank - hand[i-1].rank != 1)
            return false;
    return true;
}

bool ok2()
{
    for(int i=1; i<=3; i++)
        if(hand[i].rank != hand[i+1].rank)
            return false;
    for(int i=2; i<=4; i++)
        if(hand[i].rank != hand[i+1].rank)
            return false;
    return true;
}

bool ok3()
{
    if(hand[1].rank == hand[2].rank && hand[2].rank == hand[3].rank && hand[4].rank == hand[5].rank)
        return true;
    else if(hand[1].rank == hand[2].rank && hand[3].rank == hand[4].rank && hand[4].rank == hand[5].rank)
        return true;
    else
        return false;
}

bool ok4()
{
    int se = hand[1].suit;
    for(int i=2; i<=5; i++)
        if(hand[i].suit != se)
            return false;
    return true;
}

bool ok5()
{
    for(int i=2; i<=5; i++)
        if(hand[i].rank - hand[i-1].rank != 1)
            return false;
    return true;
}

bool ok6()
{
    if(hand[1].rank == hand[2].rank && hand[2].rank == hand[3].rank)
        return true;
    else if(hand[4].rank == hand[2].rank && hand[2].rank == hand[3].rank)
        return true;
    else if(hand[3].rank == hand[4].rank && hand[4].rank == hand[5].rank)
        return true;
    else
        return false;
}

bool ok7()
{
    if(hand[1].rank == hand[2].rank && (hand[3].suit == hand[4].suit || hand[3].suit == hand[5].suit || hand[5].suit == hand[4].suit))
        return true;
    else if(hand[2].rank == hand[3].rank && (hand[1].suit == hand[4].suit || hand[1].suit == hand[5].suit || hand[5].suit == hand[4].suit))
        return true;
    else if(hand[3].rank == hand[4].rank && (hand[1].suit == hand[2].suit || hand[1].suit == hand[5].suit || hand[2].suit == hand[5].suit))
        return true;
    else if(hand[4].rank == hand[5].rank && (hand[1].suit == hand[2].suit || hand[1].suit == hand[3].suit || hand[2].suit == hand[3].suit))
        return true;
    else
        return false;
}

bool ok8()
{
    if(hand[1].rank == hand[2].rank || hand[2].rank == hand[3].rank || hand[3].rank == hand[4].rank || hand[4].rank == hand[5].rank )
        return true;
    else
        return false;
}

int main()
{
    card c1,c2;
    scanf("%d%d", &n, &m);
    scanf("%d%d%d%d", &c1.rank, &c1.suit, &c2.rank, &c2.suit);
    hand[1] = c1;
    hand[2] = c2;

    for(int rank1=0; rank1<n; rank1++)
    {
        for(int suit1=0; suit1<m; suit1++)
        {

            card c3 = {rank1, suit1};
            if(c3 == c1 || c3==c2)
                continue;
            hand[3] = c3;

            for(int rank2=0; rank2<n; rank2++)
            {
                for(int suit2=0; suit2<m; suit2++)
                {
                    card c4 = {rank2, suit2};
                    if(c4 == c1 || c4 == c2 || c4 == c3)
                        continue;
                    hand[4] = c4;

                    for(int rank3=0; rank3<n; rank3++)
                    {
                        for(int suit3=0; suit3<m; suit3++)
                        {
                            card c5 = {rank3, suit3};
                            if(c5 == c1 || c5==c2 || c5==c3 || c5==c4)
                                continue;
                            hand[5] = c5;

                            sort(hand+1, hand+6);

                            if(ok1)
                                cnt[1]++;
                            else if(ok2)
                                cnt[2]++;
                            else if(ok3)
                                cnt[3]++;
                            else if(ok4)
                                cnt[4]++;
                            else if(ok5)
                                cnt[5]++;
                            else if(ok6)
                                cnt[6]++;
                            else if(ok7)
                                cnt[7]++;
                            else if(ok8)
                                cnt[8]++;
                            else
                                cnt[9]++;
                        }
                    }
                }
            }
        }
        for(int i=1; i<=8; i++)
            printf("%d ", cnt[i]);
        printf("%d\n",cnt[9]);
        return 0;
    }
}








//    if(a1 > a2)
//        swap(a1, a2);
//    if(b1 != b2 || abs(a1-a2)>4)
//        cnt[1] = 0;
//    else
//    {
//       int left = a1-0;
//       int right = n - a2;
//       int diff = a2-a1;
//
//       if(diff == 4)
//        cnt[1] = 1;
//       if(diff == 1)
//       {
//
//       }
//    }





