#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<queue>
#define MAXN 50005
using namespace std;

char str[MAXN];
char maxstring[10][MAXN];
char temp[MAXN];
struct node
{
    int count;
    struct node *next[26];
    struct node *fail;
    void init()
    {
        int i;
        for(i=0;i<26;i++)
            next[i]=NULL;
        count=0;
        fail=NULL;
    }
}*root;
void insert()
{
    int len,k;
    node *p=root;
    len=strlen(str);
    for(k=0;k<len;k++)
    {
        int pos=str[k]-'a';
        if(p->next[pos]==NULL)
        {
            p->next[pos]=new node;
            p->next[pos]->init();
            p=p->next[pos];
        }
        else
            p=p->next[pos];
    }
    p->count++;
}
void getfail()
{
    int i;
       node *p=root,*son,*temp;
       queue<struct node *>que;
       que.push(p);
       while(!que.empty())
       {
           temp=que.front();
           que.pop();
           for(i=0;i<26;i++)
           {
               son=temp->next[i];
               if(son!=NULL)
               {
                   if(temp==root) {son->fail=root;}
                   else
                   {
                       p=temp->fail;
                       while(p)
                       {
                           if(p->next[i])
                           {
                               son->fail=p->next[i];
                               break;
                           }
                           p=p->fail;
                       }
                       if(!p)  son->fail=root;
                   }
                   que.push(son);
               }
           }
       }
}
int query()
{
    int len,i,cnt=0;
    len=strlen(str);
    node *p,*temp;
    p=root;
    for(i=0;i<len;i++)
    {
        int pos=str[i]-'a';
        while(!p->next[pos]&&p!=root)  p=p->fail;
        p=p->next[pos];//
        if(!p) p=root;//
        temp=p;
        /*不要用*temp=*p  因为*p表示一个node，而*temp也表示一个node 但是由于*temp没有分配空间 所以是不能进行赋值的 但是可以用temp指针去指向p*/
        while(temp!=root)
        {
            if(temp->count>=0)
            {
                cnt+=temp->count;
                temp->count=-1;
            }
            else break;
            temp=temp->fail;
        }
    }
    return cnt;
}
int main()
{
    int cas,n;
    scanf("%d",&cas);
    while(cas--)
    {
        bool flag = false;
        int maxlen = 0;
        int cnt = 0;
        int len = 0;
        root=new node;
        root->init();
        root->fail=NULL;
        scanf("%d",&n);
        int i;
        getchar();
        for(i=0;i<n;i++)
        {
            gets(str);
            len = strlen(str);
            if(len > maxlen)
            {
                strcpy(temp, str);
                for(int t=0; t<cnt; t++)
                {
                    strcpy(str, maxstring[t]);
                    insert();
                }
                cnt = 0;
                maxlen = len;
                strcpy(maxstring[0], temp);
                cnt++;
            }
            else if(len == maxlen)
            {
                strcpy(maxstring[cnt], str);
                cnt++;
            }
            else
                insert();
        }
        getfail();

        strcpy(str, maxstring[0]);

        if(query() == n-cnt && n-cnt!=0)
            puts(str);
        else
            puts("No");
//        for(i=0; i<cnt; i++)
//        {
//            strcpy(str, maxstring[i]);
//            if(query() == n)
//            {
//                puts(str);
//                flag = true;
//                break;
//            }
//        }
//        if(flag == false)
//            puts("No");
    }
    return 0;
}

