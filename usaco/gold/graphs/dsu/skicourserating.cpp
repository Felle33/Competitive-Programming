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

using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e9;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

struct DSU {
	vector<int> p;
    vector<unsigned int> r;
	vector<int> min_weight;
	vector<int> size;

    DSU(int N) {
        p = vector<int>(N);
        r = vector<unsigned int>(N, 1);
        min_weight = vector<int>(N, -1);
        size = vector<int>(N, 1);

        for(int i = 0; i < N; i++){
            p[i] = i;
        }
    }

    int get(int x) {
		if(p[x] == x) return x;
		return get(p[x]);
	}

    bool unite(int x, int y) {
        if(r[x] == r[y]) 
            r[x]++;
        
        if(r[x] > r[y]) {
			p[y] = x;
			size[x] += size[y];
		}  
        else {
			p[x] = y;
			size[y] += size[x];
		}
            
        return true;
    }

	ll get_min_weight(int x) {
		while(min_weight[x] == -1) {
			x = p[x];
		}
		return min_weight[x];
	}
};

struct Edge {
	int a, b, w;
};

int transform(int i, int j, int n) {
	return i * n + j;
}

bool cmp(const Edge& e1, const Edge& e2) {
	return e1.w < e2.w;
}

void solve(){
    int n, m, t;
	cin >> n >> m >> t;

	vector<vector<int>> grid(n, vector<int>(m));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}

	vector<Edge> edges;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(i < n - 1) {
				edges.push_back({transform(i, j, m),
					transform(i + 1, j, m),
					abs(grid[i][j] - grid[i + 1][j])}
				);
			}

			if(j < m - 1) {
				edges.push_back({transform(i, j, m),
					transform(i, j + 1, m),
					abs(grid[i][j] - grid[i][j + 1])}
				);
			}
		}
	}

	sort(all(edges), cmp);
	DSU dsu = DSU(n * m);
	for(const Edge& edge : edges) {
		int pa = dsu.get(edge.a);
		int pb = dsu.get(edge.b);

		if(pa != pb) {
			if(dsu.size[pa] + dsu.size[pb] >= t) {
				if(dsu.min_weight[pa] == -1) {
					dsu.min_weight[pa] = edge.w;
				}

				if(dsu.min_weight[pb] == -1) {
					dsu.min_weight[pb] = edge.w;
				}
			}
			dsu.unite(pa, pb);
		}
	}

	ll ans = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			int x;
			cin >> x;
			if(x == 1) {
				ans += dsu.get_min_weight(transform(i, j, m));
			}
		}
	}

	cout << ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("skilevel.in", "r", stdin);
	freopen("skilevel.out", "w", stdout);

    solve();
}