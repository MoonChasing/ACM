#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
struct trie
{
    trie *next[2];
    int cnt;
    trie()
    {
        memset(next,0,sizeof(next));
        cnt=0;
    }
};
trie *root;
void Insert(char *s,int x)
{
    trie *p=root;
    int i,k;
    for(i=31;i>=0;i--)
    {
        k=s[i]-'0';
        if(p->next[k]==NULL)
            p->next[k]=new trie();
        p=p->next[k];
    }
    p->cnt = x;
}
int query(char *s,int x,int dir)
{
    trie *p = root;
    for(int i=31;i>=0;i--)
    {
        int x = s[i] - '0';
        x = x^dir;
        if(p->next[x] == NULL)
            x^=1;
        p = p->next[x];
    }
    return (p->cnt) ^ x;
}
void del(trie *p)
{
    for(int i=0;i<2;i++)
        if(p->next[i]!=NULL)
            del(p->next[i]);
    free(p);
}
void toString(char *a,int x)
{
    int i;
    for(i=0;i<=31;i++)
        a[i] = '0';
    a[i] ='\0';
    i = 0;
    while(x)
    {
        a[i++] = (x%2)+'0';
        x /= 2;
    }
}

const int inf = 1e9;

int main(void)
{
    int T,n,i,j;
    int sum[50010];
    scanf("%d",&T);
    int kiss = 1;
    while(T--)
    {
        root=new trie();
        scanf("%d",&n);
        sum[0] = 0;
        for(i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            sum[i] = sum[i-1] ^ x;
        }
        char t[33];
        toString(t,0);
        Insert(t,0);
        int maxn = 0,minn = inf;
        for(i=1;i<=n;i++)
        {
            toString(t,sum[i]);
            maxn = max(maxn,query(t,sum[i],1));
            minn = min(minn,query(t,sum[i],0));
            Insert(t,sum[i]);
        }
        printf("Case %d: %d %d\n",kiss++,maxn,minn);
        del(root);
    }

    return 0;
}
