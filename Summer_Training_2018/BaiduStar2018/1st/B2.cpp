#include<bits/stdc++.h>
using namespace std;
const int MAXN=150000+7;
list<int> baidulaji[MAXN];

void read(int &x){
	char ch = getchar();x = 0;
	for (; ch < '0' || ch > '9'; ch = getchar());
	for (; ch >='0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
}
int main()
{
    int n,q;
    while(~scanf("%d%d",&n,&q))
    {
        for(int i=0;i<=n;i++)
            baidulaji[i].clear();
        int s,u,v,w,val;
        for(int i=1;i<=q;i++)
        {
            read(s);
            if(s==1)
            {
                read(u);
                read(w);
                read(val);
                if(w==0)
                    baidulaji[u].push_front(val);
                else
                    baidulaji[u].push_back(val);
            }
            else if(s==2)
            {
                read(u);
                read(w);
                if(baidulaji[u].empty()){
                    printf("-1\n");
                    continue;
                }
                if(w==0){
                    printf("%d\n",baidulaji[u].front());
                    baidulaji[u].pop_front();
                }
                else{
                    printf("%d\n",baidulaji[u].back());
                    baidulaji[u].pop_back();
                }
            }
            else
            {
                read(u);
                read(v);
                read(w);
                if(w==0)
                {
                    baidulaji[u].splice(baidulaji[u].end(),baidulaji[v]);
                }
                else
                {
                    baidulaji[v].reverse();
                    baidulaji[u].splice(baidulaji[u].end(),baidulaji[v]);
                }
            }
        }
    }
    return 0;
}
