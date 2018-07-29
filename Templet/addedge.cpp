struct
{
    int to, next;
}edge[MAXN];

int head[MAXN];
memset(head, -1, sizeof(head));
int tol = 0;
void addedge(int u, int v)
{
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}

for(int i=head[u]; i!=-1; i=edge[i].next)


void addedge(int u, int v)
{
    edge[tol].to = v;
    edge[tol].next = head[u];
    head[u] = tol++;
}

for(int i= head[u]; i!=-1; i=edge[i].next)

void addedge(int u, int v)
{
    edge[tol].to = v;
    edge[tol].next = head[u];
    head[u] = tol++;
}
