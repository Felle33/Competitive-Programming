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
#include <bitset>

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

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e15;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

vvi adj;
vvi up;
vi depth;
const int LOG = 20;

// jump(i, j) returns jth ancestor of node i
int jump(int node, int level) {
	for (int i = 0; i < LOG; i++) {
		if (level & (1 << i)) { node = up[node][i]; }
	}
	return node;
}

void dfs(int node, int parent) {
    for(int to : adj[node]) {
        if(to != parent) {
            depth[to] = depth[node] + 1;
            up[to][0] = node;
            for(int i = 1; i < LOG; i++) {
                up[to][i] = up[up[to][i - 1]][i - 1];
            }
            dfs(to, node);
        }
    }
}

int get_lca(int a, int b) {
    if(depth[a] < depth[b]) swap(a, b);

    int diff = depth[a] - depth[b];
    a = jump(a, diff);

    if(a == b) return a;

    for(int i = LOG - 1; i >= 0; i--) {
        if(up[a][i] != up[b][i]) {
            a = up[a][i];
            b = up[b][i];
        }
    }

    return up[a][0];
}

void solve(){
    int n; cin >> n;
    adj = vvi(n);
    up = vvi(n, vi(LOG));
    depth = vi(n);

    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0, -1);

    int q; cin >> q;
    while(q--) {
        int start, end, c;
        cin >> start >> end >> c;
        start--, end--;

        int lca = get_lca(start, end);
        int path1 = depth[start] - depth[lca];
		int path2 = depth[end] - depth[lca];

		int result;
		if (c <= path1) {
			// moves up from start towards the lca.
			result = jump(start, c) + 1;
		} else if (c <= path1 + path2) {
			// moves up from start to the lca, then goes down towards end.
			result = jump(end, path2 - (c - path1)) + 1;
		} else {
			// reaches the end.
			result = end + 1;
		}
		cout << result << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    solve();
}