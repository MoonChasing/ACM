#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 1008;
vector<int>mp[maxn];
int color[maxn];

bool bfs(int s)
{
    color[s] = 0; //��ͨ��֧��������Ⱦ1Ҳ����Ⱦ0
    queue<int>q;
    q.push(s);
    while (!q.empty())
    {
        s = q.front();
        q.pop();
        for (int i = 0; i < (int)mp[s].size(); i ++) {
          int t = mp[s][i];
          if (color[t] == -1) color[t] = !color[s], q.push(t); //������ڶ���δ��Ⱦɫ�������
                                                   //���С�
          if (color[t] == color[s]) { //������ڶ���Ⱦ��ͬ��ɫ�����Ƕ���ͼ��
            return false;
          }
        }
    }
    return true;
}
int main()
{
    int T, n, m;
    scanf("%d", &T);

    while (T--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i ++) mp[i].clear();
        memset(color, -1, (n+1)*sizeof(color[0]));
        for (int i = 0; i < m; i ++) {
            int x, y;
            cin >> x>>y;
            mp[x].push_back(y); //����ͼ�洢������
            mp[y].push_back(x);
        }
        int flag = true; //��ʼ������ͼ�Ƕ���ͼ
        for (int i = 1; i <= n; i ++) {
            if (color[i] == -1 && !bfs(i)) { //��ÿ����ͨ��֧Ⱦɫ������������ڵĵ�
                    //��ɫ��ͬ�����Ƕ���ͼ��
                flag = false;
                break;
            }
        }
        if (!flag) cout <<"No"<<endl;
        else
            cout <<"Yes"<<endl;
    }
    return 0;
}
