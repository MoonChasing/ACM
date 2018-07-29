#include<bits/stdc++.h>
using namespace std;

int n;
char A[1024];

bool guanji[3000];

int degree[3000];

int heads[3000];
int len;

struct node
{
    int v, next;
} E[3000];

void addEdge( int u, int v )
{
    E[len].v = v;
    E[len].next = heads[u];
    heads[u] = len++;
}

int ans, cnt;

void solve()
{
    while( true )
    {
        vector<int> V;
        while( true )
        {
            bool exit = true;
            for( int i = 1; i < cnt; ++i )
            {
                if( degree[i] == 0 )
                {
                    degree[i] -= 1;
                    if( guanji[i] == false )
                    {
                        exit = false;
                        for( int j = heads[i]; j != -1; j = E[j].next )
                        {
                            int v = E[j].v;
                            degree[v] -= 1;
                        }
                    }
                    else
                    {
                        V.push_back( i );
                    }
                }
            }
            if( exit )
            {
                break;
            }
        }
        int size = V.size();
        if( size == 0 )
        {
            break;
        }
        ans += 1;
        for( int i = 0; i < size; ++i )
        {
            int u = V[i];
//          degree[u] = -1;
            for( int j = heads[u]; j != -1; j = E[j].next )
            {
                int v = E[j].v;
                degree[v] -= 1;
            }
        }
    }
}

int main()
{
	freopen( "C:\\Users\\Administrator\\Desktop\\in.txt", "r", stdin );
    scanf("%d", &n);
    getchar();
    getchar();
    int cases = 1;
    while(n--)
    {
        map<string,int> M;
        cnt = 1;
        memset( guanji, false, sizeof(guanji) );
        memset( degree, 0, sizeof(degree) );
        memset( heads, -1, sizeof(heads) );
        len = 0;

        while( gets(A) && A[0] != '\0' )
        {
            int len = strlen( A );
            string u, v;
            int i = 0;
            for( i = 0; i < len; ++i )
            {
                if( A[i] != ':' && A[i] != '*' )
                {
                    u += A[i];
                }
                else
                {
                    break;
                }
            }
            int a = M[u], b = cnt+1;
            if( a == 0 )
            {
                M[u] = cnt++;
                a = cnt-1;
            }
//        	cout<<u<<" "<<a<<endl;
            if( A[i] == '*' )
            {
                guanji[a] = true;
                i += 1;
            }
            for( i = i+2; i < len; ++i )
            {
                v += A[i];
            }
            if( v.size() != 0 )
            {
                int b = M[v];
                if( b == 0 )
                {
                    M[v] = cnt++;
                    b = cnt-1;
                }

                addEdge( b, a );
                degree[a] += 1;
            }
        }
        ans = 0;
        solve();
        printf( "Case %d: %d\n", cases++, ans );
    }
    return 0;
}
