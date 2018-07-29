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

int main()
{
    int T;
    scanf("%d", &T);

    while(T--)
    {
        string a, b, c;
        cin >> a >> b >> c;

        bool flag = true;
        int lenc = c.length();
        int cura = 0, curb = 0;
        char ch1, ch2;

        for(int i=0; i<lenc; )
        {
            if(flag == false)
                break;
            if(a[cura] != b[curb])
            {
                if(c[i] == a[cura])
                    cura++;
                else if(c[i] == b[curb])
                    curb++;
                else
                {
                    flag = false;
                    break;
                }
                i++;
            }
            else
            {
                int cnt;
                for(cnt = 1; a[cura+cnt] == b[curb+cnt]; cnt++);
                ch1 = a[cura+cnt];
                ch2 = b[curb+cnt];
                int pos1 = c.find(ch1,i);
                int pos2 = c.find(ch2,i);

                if(pos1 < pos2) //优先使用a
                {
                    int posa = cura + cnt;
                    for(; cura <= posa; )
                    {
                        if(c[i] == a[cura])
                        {
                            cura++;
                            i++;
                        }
                        else if(c[i] == b[curb])
                        {
                            curb++;
                            i++;
                        }
                        else
                        {
                            flag = false;
                        }
                    }
                }
                else    //优先使用b
                {
                    int posb = curb + cnt;
                    for(; curb <= posb; )
                    {
                        if(c[i] == b[curb])
                        {
                            curb++;
                            i++;
                        }
                        else if(c[i] == a[cura])
                        {
                            cura++;
                            i++;
                        }
                        else
                        {
                            flag = false;
                        }
                    }
                }

            }
        }
        if(flag)
            puts("YES,memeda!");
        else
            puts("Oh,i want memeda!");
    }
    return 0;
}







