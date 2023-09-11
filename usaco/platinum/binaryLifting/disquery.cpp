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
const ll INF = 1e8;
const ll MAX_N = 100001;
const ll LOG = 30;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

struct Edge {
    int dest, weight;
};

int n;
int up[MAX_N][LOG];
int mini[MAX_N][LOG];
int maxi[MAX_N][LOG];
int depth[MAX_N];
vector<Edge> adj[MAX_N];

void dfs(int node, int parent) {
    for(Edge edge : adj[node]) {
        int child = edge.dest;
        if(child != parent) {
            depth[child] = depth[node] + 1;
            up[child][0] = node;
            mini[child][0] = edge.weight;
            maxi[child][0] = edge.weight;

            for(int i = 1; i < LOG; i++) {
                up[child][i] = up[up[child][i - 1]][i - 1];
                maxi[child][i] = max(maxi[child][i - 1], maxi[up[child][i - 1]][i - 1]);
                mini[child][i] = min(mini[child][i - 1], mini[up[child][i - 1]][i - 1]);
            }
            dfs(child, node);
        }
    }
}

pair<int, int> query(int a, int b) {
    if(depth[a] < depth[b]) swap(a, b);

    int k = depth[a] - depth[b];
    int ansMin = INF, ansMax = -1;
    for(int j = LOG - 1; j >= 0; j--) {
        if(k & (1 << j)) {
            ansMin = min(ansMin, mini[a][j]);
            ansMax = max(ansMax, maxi[a][j]);
            a = up[a][j];
        }
    }

    if(a == b) return mp(ansMin, ansMax);

    for(int j = LOG - 1; j >= 0; j--) {
        if(up[a][j] != up[b][j]) {
            ansMin = min({ansMin, mini[a][j], mini[b][j]});
            ansMax = max({ansMax, maxi[a][j], maxi[b][j]});
            a = up[a][j];
            b = up[b][j];
        }
    }

    ansMin = min({ansMin, mini[a][0], mini[b][0]});
    ansMax = max({ansMax, maxi[a][0], maxi[b][0]});

    return mp(ansMin, ansMax);
}

void solve(){
    cin >> n;
    rep(i, n - 1) {
        int a, b, w;
        cin >> a >> b >> w;
        a--, b--;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    rep(i, MAX_N) {
        rep(j, LOG) {
            maxi[i][j] = -1;
            mini[i][j] = INF;
        }
    }

    dfs(0, -1);

    int q; cin >> q;
    rep(i, q) {
        int a, b; cin >> a >> b;
        a--, b--;

        pii res = query(a, b);
        cout << res.first << " " << res.second << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    solve();
}