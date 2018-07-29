#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int MAXN = 1e6+10;
int ans[MAXN];
const int SIZE = 'z' - 'A' + 1;
int ni;
struct Trie
{
    int next[MAXN][SIZE],fail[MAXN],end[MAXN];
    int root,L,id;
    int newnode()
    {
        for(int i = 0; i < SIZE; i++)
            next[L][i] = -1;
        end[L++] = 0;
        return L-1;
    }
    void init()
    {
        L = 0;
        root = newnode();
        id = 0;
    }
    void insert(char buf[])
    {
        int len = strlen(buf);
        int now = root;
        for(int i = 0; i < len; i++)
        {
            if(next[now][buf[i]-'A'] == -1)
                next[now][buf[i]-'A'] = newnode();
            now = next[now][buf[i]-'A'];
        }
        end[now] = ++id;
    }
    void build()
    {
        queue<int>Q;
        fail[root] = root;
        for(int i = 0; i < SIZE; i++)
            if(next[root][i] == -1)
                next[root][i] = root;
            else
            {
                fail[next[root][i]] = root;
                Q.push(next[root][i]);
            }
        while( !Q.empty() )
        {
            int now = Q.front();
            Q.pop();
            for(int i = 0; i < SIZE; i++)
                if(next[now][i] == -1)
                    next[now][i] = next[fail[now]][i];
                else
                {
                    fail[next[now][i]]=next[fail[now]][i];
                    Q.push(next[now][i]);
                }
        }
    }

    void query(char buf[])
    {
        memset(ans, 0, sizeof(ans));
        int len = strlen(buf);
        int now = root;
        int res = 0;
        for(int i = 0; i < len; i++)
        {
            now = next[now][buf[i]-'A'];
            int temp = now;
            while( temp != root )
            {
                ans[end[temp]]++;
                temp = fail[temp];
            }
        }
    }
};
char zi[MAXN], mu[MAXN];
Trie ac;
int main()
{
    int T;
    scanf("%d",&T);
    getchar();
    while( T-- )
    {
        ni = 0;
        ac.init();
        gets(mu);
        gets(zi);
        int len = strlen(zi);
        for(int i=0; i<len; i++)
            ac.insert(zi+i);
        //ac.insert(zi);
        ac.build();
        ac.query(mu);
        for(int i=1; i<=len; i++)
          printf("%d\n", ans[i]);
        for(int i=1; i<=len; i++)
            ni += ans[i] * (len-i+1) %1000000007;
        printf("%d\n",ni);
    }
    return 0;
}
