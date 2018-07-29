#include <iostream>
#include <cstdio>
using namespace std;

int main()
{

    int a;
    while( ~scanf("%d", &a) )
    {
        int t = a;
        int sum = 0;
        while( a )
        {
            int b = a%10;
            a  /= 10;
            sum += b*b*b;
        }
        if(t == sum)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
