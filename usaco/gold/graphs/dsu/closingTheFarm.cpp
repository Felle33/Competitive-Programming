#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>
#include <map>
#include <set>
#include <iomanip>

#define all(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e9;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

struct DSU {
	vector<int> p;
    vector<unsigned int> r;

    DSU(int N) {
        p = vector<int>(N);
        r = vector<unsigned int>(N, 1);

        for(int i = 0; i < N; i++){
            p[i] = i;
        }
    }

    int get(int x) { return p[x] == x ? x : p[x] = get(p[x]); }

    bool unite(int x, int y) {
        x = get(x), y = get(y);
        if(x == y) return false;
        if(r[x] == r[y]) 
            r[x]++;
        
        if(r[x] > r[y])
            p[y] = x;
        else 
            p[x] = y;
        return true;
    }
};

void solve(){
    int n, m;
	cin >> n >> m;

	vector<vector<int>> adj(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	// open[i] = whether the ith farm is open
	vector<bool> open(n);
	vector<int> rev(n);
	for (int i = 0; i < n; i++) {
		cin >> rev[i];
		rev[i]--;
	}

	DSU dsu(n);
	reverse(rev.begin(), rev.end());

	open[rev[0]] = true;
	// one node is always connected
	vector<string> ans = {"YES"};

	// connected components
	int cc = 1;
	for (int i = 1; i < n; i++) {
		cc++;
		open[rev[i]] = true;
		for (int j : adj[rev[i]]) {
			if (open[j]) {
				if (dsu.unite(j, rev[i])) { cc--; }
			}
		}
		ans.push_back(cc == 1 ? "YES" : "NO");
	}
	reverse(ans.begin(), ans.end());

	for (const string &i : ans) { cout << i << '\n'; }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("closing.in", "r", stdin);
	freopen("closing.out", "w", stdout);

    solve();
}