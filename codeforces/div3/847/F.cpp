#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <cstring>

using namespace std;

const int MAXN = 200200;
const int INF = 1e9;

int n, ANS = INF;
int blackNodes[MAXN], dist[MAXN], res[MAXN];
bool clr[MAXN];
vector<int> graph[MAXN];

void init() {
	ANS = INF;
	for (int v = 0; v < n; ++v)
		graph[v].clear();
	fill(dist, dist + n, INF);
	memset(clr, 0, n);
}

void dfs(int v, int p) {
	if (dist[v] >= ANS) return;
	if (clr[v]) ANS = min(ANS, dist[v]);
	for (int u: graph[v]) {
		if (u == p) continue;
		if (dist[v] + 1 < dist[u]) {
			dist[u] = dist[v] + 1;
			dfs(u, v);
		} else ANS = min(ANS, dist[v] + 1 + dist[u]);
	}
}

void solve() {
	dist[*blackNodes] = 0;
	dfs(*blackNodes, -1);
	clr[*blackNodes] = true;
	for (int i = 1; i < n; ++i) {
		dist[blackNodes[i]] = 0;
		dfs(blackNodes[i], -1);
		clr[blackNodes[i]] = true;
		res[i] = ANS;
	}
}

int main() {
	int gorilla; cin >> gorilla;
	while (gorilla--) {
		cin >> n >> *blackNodes, --(*blackNodes);
		init();
		for (int i = 1; i < n; ++i)
			cin >> blackNodes[i], --blackNodes[i];
		for (int i = 1; i < n; ++i) {
			int v, u; cin >> v >> u, --v, --u;
			graph[v].push_back(u);
			graph[u].push_back(v);
		}
		solve();
		for (int i = 1; i < n; ++i)
			cout << res[i] << ' ';
		cout << '\n';
	}
}