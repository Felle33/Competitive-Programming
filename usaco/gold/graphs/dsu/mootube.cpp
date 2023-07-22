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
typedef pair<int,int> pii;

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e9;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

struct DSU {
	vector<int> p;
    vector<unsigned int> r;
	vector<unsigned int> size;

    DSU(int N) {
        p = vector<int>(N);
        r = vector<unsigned int>(N, 1);
        size = vector<unsigned int>(N, 1);

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
        
        if(r[x] > r[y]){
			p[y] = x;
			size[x] += size[y];
		}
        else {
			p[x] = y;
			size[y] += size[x];
		}  
        return true;
    }
};

struct Edge {
	int src, dest, cost;
};

bool cmp(const Edge& e1, const Edge& e2){
	return e1.cost > e2.cost;
}

void solve(){
    int n, m;
	cin >> n >> m;

	vector<Edge> edges;
	for (int i = 0; i < n - 1; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		u--;
		v--;
		edges.push_back({u, v, c});
	}

	sort(all(edges), cmp);

	vector<tuple<int, int, int>> q(m);
	for(int i = 0; i < m; i++){
		int k, v;
		cin >> k >> v;
		v--;
		q[i] = {k, v, i};
	}

	sort(q.rbegin(), q.rend());

	int i = 0;
	DSU dsu = DSU(n);
	vector<int> res(m);
	for(auto query : q){
		for(; i < n && get<0>(query) <= edges[i].cost; i++) {
			dsu.unite(edges[i].src, edges[i].dest);
		}

		res[get<2>(query)] = dsu.size[dsu.get(get<1>(query))] - 1;
	}

	for(int x : res) {
		cout << x << '\n';
	}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("mootube.in", "r", stdin);
	freopen("mootube.out", "w", stdout);

    solve();
}