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
const ll INF = 1e18;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

int n;
vector<vector<int>> adj;
vector<ll> a;
vector<vector<ll>> dp, pref_dp, suff_dp;

bool leaf(int u, int p) {
    return adj[u].size() == 1 && adj[u][0] == p;
}

// O(n^2)
void dfs(int u, int p) {
    for(int to : adj[u]) {
        if(to == p) continue;
        dfs(to, u);
    }

    for(int pr = 1; pr <= n; pr++) {
        ll ans = pr * a[u];

        for(int to : adj[u]) {
            if(to == p) continue;

            ll mn = min(pref_dp[to][pr - 1], suff_dp[to][pr + 1]);
            ans += mn;
        }

        dp[u][pr] = min(dp[u][pr], ans);
    }

    for(int pr = 1; pr <= n; pr++) {
        pref_dp[u][pr] = min(pref_dp[u][pr - 1], dp[u][pr]);
    }

    for(int pr = n; pr >= 1; pr--) {
        suff_dp[u][pr] = min(suff_dp[u][pr + 1], dp[u][pr]);
    }
}

void solve(){
    cin >> n;

    a = vector<ll>(n);
    adj = vector<vector<int>>(n);
    dp = vector<vector<ll>>(n, vector<ll>(n + 2, INF));
    pref_dp = vector<vector<ll>>(n, vector<ll>(n + 2, INF));
    suff_dp = vector<vector<ll>>(n, vector<ll>(n + 2, INF));

    rep(i, n) cin >> a[i];

    rep(i, n - 1) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0, -1);

    ll ans = dp[0][1];
    for(int i = 1; i <= n; i++) ans = min(ans, dp[0][i]);
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin >> t;
    while(t--) solve();
}