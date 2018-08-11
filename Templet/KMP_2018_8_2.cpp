#include <bits/stdc++.h>

using namespace std;
const int MAXN = 10000;
int next[MAXN];
void prekmp(char x[], int m)
{
    int i,j;
    j = next[0] = -1;
    i = 0;
    while(i<m)
    {
        while(-1 != j && x[i] != x[j])
            j = next[j];
        next[++i] = ++j;
    }
}

void getnext(char str[], int len){
    int i=0,j=-1;
    next[0]=-1;
    while(i<len){
        if(j==-1 || str[i]==str[j]){
            i++;j++;
            next[i]=j;
        }else
            j=next[j];
    }
}

int kmpcount(char x[], int m, char y[], int n)
{
    int i,j;
    int ans=0;
    prekmp(x,m);
    i = j = 0;
    while(i<n)
    {
        while(-1 != j && y[i] != x[j])
            j = next[j];
        i++; j++;
        if(j >= m)
        {
            ans++;
            j=next[j];  // j = next[j]为计数可以重叠， j = 0为计数不重叠
        }
    }
    return ans;
}

int main()
{
    char s[100] = "abababa";
    char p[100] = "abababcdabcd";
    //prekmp(p, 3);
    //char test[100] = "ababcabc";
    int len = strlen(p);
    getnext(p, 12);
    for(int i=0; i<=12; i++)
        printf("%d ", next[i]);
    //cout << kmpcount(p, 3, s, 7) << endl;

    //printf("%d\n", (len%(len-next[len]) == 0) ? len/(len-next[len]) : 1 ) ;

    return 0;
}



