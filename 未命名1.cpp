#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
#include<utility>
#include<queue>
#define ll long long
#define endl "\n"
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100010;
const int maxw = 100010;
int n, m;
vector<int> a[maxn];
vector<int> b[maxn];
int dp[maxn];
int in[maxn];
int tpp[maxn];
int tpx[maxn];
void add(int u, int v)
{
	a[u].push_back(v);
	b[v].push_back(u);
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
		for (int i = 0; i < a[now].size(); i++)
		{
			int y = a[now][i];
			in[y]--;
			if (!in[y])
			{
				q.push(y);
				tpp[y] = ++t;
				tp.push_back(y);
			}
		}
	}
	int vv = 0;
	while (tp.size())
	{
		tpx[vv++] = tp.front();
		tp.pop_front();
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	int u, v;
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v;
		in[v]++;
		add(u, v);
	}
	topo();
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < b[tpx[i]].size(); j++)
		{
			int xx = dp[b[tpx[i]][j]] + 1;
			dp[tpx[i]] = max(xx, dp[tpx[i]]);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans = max(dp[i], ans);
	cout << ans << endl;
	return 0;
}
