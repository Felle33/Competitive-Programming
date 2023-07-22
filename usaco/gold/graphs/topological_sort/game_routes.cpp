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
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e9;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

int n, m;

ll dfs(int node, vector<vector<int>>& adj, vector<ll>& dp) {
    if(node == n - 1) {
        return 1;
    }

    ll mods = 0;
    for(int e : adj[node]) {
        ll res;
        if(dp[e] == -1) {
            res = dfs(e, adj, dp) % MOD;
        } else {
            res = dp[e];
        }
        mods = (mods + res) % MOD;
    }

    dp[node] = mods;
    return mods;
}

void solve(){
    cin >> n >> m;

    vector<vector<int>> adj(n);
    vector<ll> dp(n, -1);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
    }

    dp[n - 1] = 1;
    ll ans = dfs(0, adj, dp) % MOD;

    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}