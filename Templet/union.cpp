#define MAXN 1000
int par[MAXN];
int u_rank[MAXN];

int n = 500;
void init()
{
    for(int i=0; i<n; i++)
    {
        par[i] = i;
        u_rank[i] = 0;
    }
}

int u_find(int x)
{
    if(par[x] == x)
        return x;
    else
        return par[x] = u_find(par[x]);
}

void unite(int x, int y)
{
    x = u_find(x);
    y = u_find(y);
    if(x == y)
        return;
    if(u_rank[x] < u_rank[y])
        par[x] = y;
    else
    {
        par[y] = x;
        u_rank[x]++;
    }
}

bool same(int x, int y)
{
    return u_find(x) == u_find(y);
}



void init()
{
    for(int i=0; i<n; i++)
    {
        par[i] = i;
        u_rank[i] = 0;
    }
}

int u_find(int x)
{
    if(par[x] == x)
        return x;
    return par[x] = u_find(par[x]);
}

void unite(int x, int y)
{
    x = par[x];
    y = par[y];

    if(x == y)
        return;
    if(u_rank[x] < u_rank[y])
        par[x] = y;
    else
    {
        par[y] = x;
        u_rank[x]++;
    }
}

bool same(int x, int y)
{
    return par[x] == par[y];
}
