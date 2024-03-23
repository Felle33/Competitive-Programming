#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <map>
#include <set>
#include <iomanip>
#include <bitset>
#include <assert.h>

#define all(x) (x).begin(), (x).end()
#define mp make_pair
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))

using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<unsigned long long> vull;
typedef vector<vector<int>> vvi;
typedef long long ll;
typedef pair<int,int> pii;

const ll MOD1 = 1e9 + 7;
const ll MOD2 = 998244353;
const ll MOD3 = 99999999999999997;
const ll DIM = 1e6;
const ll INF = 1e15;
const int INF_INT = 1e9;
const ll LL_MAX = 9223372036854775807;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

struct Edge { int to; ll flo, cap; };

struct Dinic {

	int N; vector<Edge> edges; vvi adj;

	Dinic(int _N) { N = _N; adj.resize(N), cur.resize(N); }

	void ae(int u, int v, ll capacity, ll reverseCapacity = 0) { 
        assert(min(capacity, reverseCapacity) >= 0); 
		adj[u].pb(edges.size());
        edges.pb({v, 0, capacity});
		
        adj[v].pb(edges.size());
        edges.pb({u, 0, reverseCapacity});
	}

	vi lev; vector<int> cur;
	bool bfs(int s, int t) { // level = shortest distance from source
		lev = vi(N, -1);
        for(int i = 0; i < N; i++) cur[i] = 0;

		queue<int> q({s});
        lev[s] = 0; 
		while (!q.empty()) { 
            int u = q.front();
            q.pop();
			for(int e : adj[u]) { 
                const Edge& edge = edges[e];
				int v = edge.to;

                if (lev[v] < 0 && edge.flo < edge.cap) {
                    q.push(v);
                    lev[v] = lev[u] + 1;
                }	
			}
		}
		return lev[t] >= 0;
	}

	ll dfs(int v, int t, ll flo) {
		if (v == t) return flo;

		for (; cur[v] < adj[v].size(); cur[v]++) {
            int id = adj[v][cur[v]];
			Edge& edge = edges[id];

			if (lev[edge.to] != lev[v] + 1 || edge.flo == edge.cap) continue;

			ll df = dfs(edge.to, t, min(flo, edge.cap - edge.flo));

			if (df) {
                edge.flo += df;
                edges[id ^ 1].flo -= df;
				return df;
            } // saturated >=1 one edge
		}
		return 0;
	}

	ll maxFlow(int s, int t) {
		ll tot = 0;
        while (bfs(s,t)) 
            while (ll df = dfs(s, t, 1e18)) 
                tot += df;
		return tot;
	}
};

void solve(){
    int n, m;
    cin >> n >> m;

    Dinic dinic(n);
    map<pair<ll, ll>, ll> edges;

    rep(i, m) {
        ll a, b, c; cin >> a >> b >> c;
        a--, b--;

        if(a == b) continue;
        edges[{a, b}] += c;
    }

    for(auto edge : edges) {
        dinic.ae(edge.first.first, edge.first.second, edge.second, edge.second);
    }

    cout << dinic.maxFlow(0, n - 1) << '\n';
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    solve();
}