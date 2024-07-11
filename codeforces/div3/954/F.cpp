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

#define all(x) (x).begin(), (x).end()
#define mp make_pair
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))
#define FELLE ios_base::sync_with_stdio(false); cin.tie(NULL); std::cout.precision(10); cout << std::fixed;

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
const int INF = 1e9;
const ll LLINF = 1e15;
const ll LL_MAX = 9223372036854775807;
const int LOG = 22;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};

ll n, m;
vvi adj;
vi visited, tin, low;
vll sz;
int times;
ll edgesCut;

void dfs1(int u, int p) {
    visited[u] = 1;
    sz[u] = 1;
    tin[u] = low[u] = times;
    times++;

    for(int to : adj[u]) {
        if(to == p) continue;
        if(!visited[to]) {
            dfs1(to, u);
            low[u] = min(low[u], low[to]);
            sz[u] += sz[to];

            // BRIDGE
            if(tin[u] < low[to]) {
                edgesCut = max(edgesCut, sz[to] * (n - sz[to]));
            }
        } else {
            low[u] = min(low[u], low[to]);
        }
    }
}

void solve(){
    cin >> n >> m;
    times = 0;
    edgesCut = 0;
    adj = vvi(n);
    visited = vi(n);
    tin = vi(n);
    low = vi(n);
    sz = vll(n);

    rep(i, m) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    dfs1(0, 0);

    int ans = n * (n - 1) / 2 - edgesCut;
    cout << ans << "\n";
}

int main(){
    FELLE
    int t; cin >> t;
    while(t--){
        solve();
    }
}