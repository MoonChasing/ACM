#include<cstdio>
#include<iostream>
#include<memset>
#define MAXN 100010
using namespace std;

int prime[MAXN+1];

void getPrime()
{
    for(int i=2; i<MAXN; i++)
    {
        if(!prime[i])
            prime[++prime[0]] = i;
        for(int j=1; j<=prime[0] && prime[j]<=MAXN/i; j++)
        {
            prime[i*prime[j]] = 1;
            if(i % prime[j] == 0)
                break;
        }
    }
}

void getPrime()
{
    for(int i=2; i<=MAXN; i++)
    {
        if(!prime[i])
            prime[++prime[0]] = i;
        for(int j=1; j<=prime[0] && prime[j]<=MAXN/i; j++)
        {
            prime[prime[j]*i] = 1;
            if(i%prime[j] == 0)
                break;
        }
    }
}

void getPrime()
{
    for(int i=2; i<=MAXN; i++)
    {
        if(!prime[i])
            prime[++prime[0]] = i;
        for(int j=1; j<=prime[0] && prime[j]<=MAXN/i; j++)
        {
            prime[prime[j]*i] = 1;
            if(i % prime[j] == 0)
                break;
        }
    }
}
int main()
{

    return 0;
}
