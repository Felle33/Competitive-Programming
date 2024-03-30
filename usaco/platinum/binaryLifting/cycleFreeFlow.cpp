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
const ll LLINF = 1e15;
const int INF = 1e9;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

struct Edge {
    int to, weight;
};

vector<vector<Edge>> adj;
vvi up;
vvi maxFlow;
vi depth;
const int LOG = 20;

void dfs(int node, int parent) {
    for(Edge& e : adj[node]) {
        int to = e.to;
        int weight = e.weight;
        if(to != parent) {
            depth[to] = depth[node] + 1;
            up[to][0] = node;
            maxFlow[to][0] = weight;

            for(int i = 1; i < LOG; i++) {
                up[to][i] = up[up[to][i - 1]][i - 1];
                maxFlow[to][i] = min(maxFlow[to][i - 1], maxFlow[up[to][i - 1]][i - 1]);
            }
            dfs(to, node);
        }
    }
}

int flow(int a, int b) {
    // get max flow between a and lca
    // get max flow between b and lca
    int maxFlowA = INF, maxFlowB = INF;
    if(depth[a] < depth[b]) swap(a, b);

    int diff = depth[a] - depth[b];
    for (int i = 0; i < LOG; i++) {
		if (diff & (1 << i)) {
            maxFlowA = min(maxFlowA, maxFlow[a][i]);
            a = up[a][i];
        }
	}

    if(a == b) return maxFlowA;

    for(int i = LOG - 1; i >= 0; i--) {
        if(up[a][i] != up[b][i]) {
            maxFlowA = min(maxFlowA, maxFlow[a][i]);
            maxFlowB = min(maxFlowB, maxFlow[b][i]);
            a = up[a][i];
            b = up[b][i];
        }
    }

    maxFlowA = min(maxFlowA, maxFlow[a][0]);
    maxFlowB = min(maxFlowB, maxFlow[b][0]);

    // return the min
    return min(maxFlowA, maxFlowB);
}

void solve(){
    int n, m; cin >> n >> m;
    adj = vector<vector<Edge>>(n);
    up = vvi(n, vi(LOG));
    maxFlow = vvi(n, vi(LOG, INF));
    depth = vi(n);

    rep(i, m) {
        int a, b, w;
        cin >> a >> b >> w;
        a--, b--;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    dfs(0, -1);

    int q; cin >> q;
    while(q--) {
        int a, b; cin >> a >> b;
        a--, b--;

        cout << flow(a, b) << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    solve();
}