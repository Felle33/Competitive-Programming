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
const ll DIM = 1e5;
const int INF = 1e9;
const ll LLINF = 1e15;
const ll LL_MAX = 9223372036854775807;
const int LOG = 22;

vi adj[DIM + 1];
bool visited[DIM + 1];

int bfs(int start) {
    int ans = 1;
    visited[start] = 1;
    queue<int> q;
    q.push(start);

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for(int to : adj[node]) {
            if(!visited[to]) {
                q.push(to);
                visited[to] = 1;
                ans++;
            }
        }
    }

    return ans;
}

void solve(){
    int n, m; cin >> n >> m;
    rep(i, m) {
        int u, v; cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vi scc;
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            scc.push_back(bfs(i));
        }
    }

    ll ans = scc.front();

    for(int i = 1; i < (int)scc.size(); i++) {
        ans = ans * (ll)scc[i] % MOD1;
    }

    cout << ans << "\n";
}

int main(){
    FELLE
    solve();
}