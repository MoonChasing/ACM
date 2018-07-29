#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#define MAXN 100010
#define INF 0x3f3f3f3f
#define eps 1e-8
#define rep(i,a,b) for(int i=a;i<(b);i++)
#define DEBUG
#define DataIn

typedef long long LL;

using namespace std;

map<string, pair<int,int> > mp;

struct Node
{
    int v,t;
    string nam;
    Node(int v,int t,string nam):v(v),t(t),nam(nam) {}
    Node() {}
    bool operator <(const Node& tmp)const
    {
        return v>tmp.v||v==tmp.v&&t>tmp.t;
    }
};

struct Node2
{
    int v,t;
    string nam;
    Node2(int v,int t,string nam):v(v),t(t),nam(nam) {}
    Node2() {}
    bool operator <(const Node2& tmp)const
    {
        return v<tmp.v||v==tmp.v&&t<tmp.t;
    }
};

int main()
{
    int n;
    set<Node> notwork;
    set<Node2> work;
    int clk=0,tot=0;
    scanf("%d",&n);
    const char msg[2][33]= {"is not working now.", "is working hard now."};
    rep(i,0,n)
    {
        char nam[33];
        int v;
        scanf("%s%d",nam,&v);

        mp[nam]=make_pair(v,++clk);

        if(notwork.size()==0||*notwork.begin()<Node(v,clk,nam))
        {
            notwork.insert(Node(v,clk,nam));
        }
        else
        {
            work.insert(Node2(v,clk,nam));
        }
        tot++;

        int cnt=(int)(tot*0.2+eps);

        while(work.size()>cnt)
        {
            Node2 x=*work.begin();
            notwork.insert(Node(x.v,x.t,x.nam));
            work.erase(work.begin());
        }
        while(work.size()<cnt)
        {
            Node x=*notwork.begin();
            work.insert(Node2(x.v,x.t,x.nam));
            notwork.erase(notwork.begin());
        }

    }
    int m;
    scanf("%d",&m);

    while(m--)
    {
        char nam[33],cmd[2];
        int v;
        scanf("%s%s",cmd,nam);
        if(cmd[0]=='+')
        {
            scanf("%d",&v);
            mp[nam]=make_pair(v,++clk);

            int flag,flag2=-1;
            string buf;
            if(notwork.size()==0||*notwork.begin()<Node(v,clk,nam))
            {
                notwork.insert(Node(v,clk,nam));
                flag=0;
            }
            else
            {
                work.insert(Node2(v,clk,nam));
                flag=1;
            }
            tot++;

            int cnt=(int)(tot*0.2+eps);
            while(work.size()>cnt)
            {
                Node2 x=*work.begin();
                if(x.v==v&&x.t==clk) flag=0;
                else
                {
                    flag2=0;
                    buf=x.nam;
                }
                notwork.insert(Node(x.v,x.t,x.nam));
                work.erase(work.begin());
            }
            while(work.size()<cnt)
            {
                Node x=*notwork.begin();
                if(x.v==v&&x.t==clk) flag=1;
                else
                {
                    flag2=1;
                    buf=x.nam;
                }
                work.insert(Node2(x.v,x.t,x.nam));
                notwork.erase(notwork.begin());
            }
            printf("%s %s\n",nam,msg[flag]);
            if(flag2>=0) printf("%s %s\n",buf.c_str(),msg[flag2]);
        }
        else
        {
            pair<int,int> x=mp[nam];
            Node nd=*notwork.begin();
            if(x.first<nd.v||x.first==nd.v&&x.second<=nd.t)
            {
                set<Node>::iterator it=notwork.lower_bound(Node(x.first,x.second,nam));
                if(it!=notwork.end()) notwork.erase(it);
            }
            else
            {
                set<Node2>::iterator it=work.lower_bound(Node2(x.first,x.second,nam));
                if(it!=work.end()) work.erase(it);
            }

            tot--;
            int cnt=(int)(tot*0.2+eps);

            while(work.size()>cnt)
            {
                Node2 x=*work.begin();
                printf("%s %s\n",x.nam.c_str(),msg[0]);
                notwork.insert(Node(x.v,x.t,x.nam));
                work.erase(work.begin());
            }
            while(work.size()<cnt)
            {
                Node x=*notwork.begin();
                printf("%s %s\n",x.nam.c_str(),msg[1]);
                work.insert(Node2(x.v,x.t,x.nam));
                notwork.erase(notwork.begin());
            }
        }
    }

    return 0;
}


