#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main()
{
    int GPLT[4];
    char ch;
    memset(GPLT, 0, sizeof(GPLT));
    while( (ch = getchar()) != '\n' )
    {
        if(ch == 'g' || ch == 'G')
            GPLT[0]++;
        else if(ch == 'p' || ch == 'P')
            GPLT[1]++;
        else if(ch == 'L' || ch == 'l')
            GPLT[2]++;
        else if(ch == 'T' || ch == 't')
            GPLT[3]++;
    }
    bool flag;
    while(1)
    {
        flag = false;
        for(int i=0; i<4; i++)
            if(GPLT[i])
            {
                if(i==0)
                {
                    GPLT[i]--;
                    putchar('G');
                }
                else if(i == 1)
                {
                    GPLT[i]--;
                    putchar('P');
                }
                else if(i == 2)
                {
                    GPLT[i]--;
                    putchar('L');
                }
                else if(i == 3)
                {
                    GPLT[i]--;
                    putchar('T');
                }
                flag =true;
            }
        if(!flag)
            break;
    }
    return 0;
}
