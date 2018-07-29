#include<cstdio>
#include<iostream>
#include<cstring>
#define MAXN 1010
#define DEBUG
using namespace std;

int next[MAXN];

char str1[MAXN] = "aba", str2[MAXN] = "abababababababababababababababa";
int len1; int len2;

void getNext(char x[], int m)
{
    int i, j;
    j = next[0] =-1;
    i = 0;
    while(i<m)
    {
        while(j!=-1 && x[i]!=x[j])
            j = next[j];
        if(x[++i] == x[++j])
            next[i] = next[j];
        else
            next[i] = j;
    }
}

void getNext(int x[], int m)
{
    int i=0 , j=-1;
    next[0] = -1;
    while(i<m)
    {
        while(j!=-1 && x[i]!=x[j])
            j = next[j];
        if(x[++i] == x[++j] )
            next[i] = next[j];
        else
            next[i] = j;
    }
}
void getNext_2(char x[], int m)
{
    int i,j;
    j = next[0] = -1;
    i = 0;
    while(i<m)
    {
        while(j!=-1 && x[i]!=x[j])
            j=next[j];
        next[++i] = ++j;
    }
}

int KMP(char x[], int m, char y[], int n)
{
    int i, j;
    int ans = 0;
    getNext(x, m);
    i = j =0;
    while(i<n)
    {
        while(j!=-1 && y[i]!=x[j])
            j= next[j];
        i++;
        j++;
        if(j>=m)
        {
            printf("%4d\n",i);
            ans++;
            j = next[j];
        }
    }
    return ans;
}


int main()
{
    len1 = strlen(str1);
    getNext_2(str1, len1);
    for(int i=0; i<len1; i++)
        printf("%-4c", str1[i]);
    putchar(10);
    for(int i=0; i<len1; i++)
        printf("%-4d", next[i]);
    putchar(10);
    printf("%d", KMP(str1, len1, str2, strlen(str2)));
    return 0;
}


void getNext(char  x[], int m)
{
    int i,j;
    next[0] = j = -1;
    i = 0;
    while(i<m)
    {
        while(j!=-1 && x[j]!=x[i])
            j = next[j];
        if(x[++i] == x[++j])
            next[i] = next[j];
        else
            next[i] = j;
    }
}

void getNext_2(char x[], int m)
{
    int i,j;
    i =0;
    next[0] = j = -1;
    while(i<m)
    {
        while(j!=-1 && x[i] != x[j] )
            j = next[j];
        next[++i] = ++j;
    }
}

int KMP(char x[], int m, char y[], int n)
{
    int i, j;
    int ans = 0;
    i = j = 0;
    while(i<n)
    {
        while(j!=-1 && x[j]!=y[i])
            j = next[j];
        i++;
        j++;
        if(j>=m)
        {
            ans++;
            j = next[j];
        }
    }
}






























