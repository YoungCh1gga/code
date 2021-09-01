#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
#define endl "\n"
using namespace std;
const int maxn = 105;
vector<int> g[maxn];
int n, m;
int in[maxn];
int tpp[maxn];
void init()
{
	for (int i = 0; i < maxn; i++)
		g[i].clear();
	memset(in, 0, sizeof(in));
	memset(tpp, 0, sizeof(tpp));
}
void add(int u, int v)
{
	g[u].push_back(v);
}
void topo()
{
	queue<int> q;
	deque<int> tp;
	int t = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!in[i])
		{
			q.push(i);
			tpp[i] = ++t;
			tp.push_back(i);
		}
	}
	while (q.size())
	{
		int now = q.front();
		q.pop();
		for (int i = 0; i < g[now].size(); i++)
		{
			int y = g[now][i];
			in[y]--;
			if (!in[y])
			{
				q.push(y);
				tpp[y] = ++t;
				tp.push_back(y);
			}
		}
	}
	bool flag = true;
	while (tp.size())
	{
		if (flag)
		{
			cout << tp.front();
			flag = false;
		}
		else
			cout << " " << tp.front();
		tp.pop_front();
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	while (cin >> n >> m && (n != 0 || m != 0))
	{
		init();
		while (m--)
		{
			int u, v;
			cin >> u >> v;
			in[v]++;
			add(u, v);
		}
		topo();
		cout << endl;
	}
	return 0;
}
