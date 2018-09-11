#include<iostream>
#include<string.h>
#include<algorithm>
#include<string>
#include<map>
#include<cstdio>
using namespace std;

#define N 100005

int fa[N];
int num[N];
int n, m;
string a, b;
int number;

int Find(int x)
{
	if (x == fa[x])
		return x;

	fa[x] = Find(fa[x]);

	return fa[x];
}

int main()
{
	while (~scanf("%d", &n))
	{
		while (n--)
		{
			number = 1;
			fill(num, num + N, 1);
			for (int i = 1; i < N; i++) fa[i] = i;
			map<string, int> mp;

			scanf("%d", &m);

			while (m--)
			{
				cin >> a >> b;

				if (!mp[a])
					mp[a] = number++;
				if (!mp[b])
					mp[b] = number++;

				int aa = Find(mp[a]);
				int bb = Find(mp[b]);

				if (aa != bb)
				{
					fa[aa] = bb;
					num[bb] += num[aa];
				}

				printf("%d\n", num[bb]);
			}
		}
	}

	return 0;
}
