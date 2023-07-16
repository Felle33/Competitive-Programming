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

int max_path(int node, vector<vector<int>>& adj, vector<int>& dp) {
    if(adj[node].empty()) {
        dp[node] = 0;
        return 0;
    }

    if(dp[node] != -1) return dp[node];

    int max_p = 0;
    for(int neigh : adj[node]) {
        max_p = max(max_p, max_path(neigh, adj, dp));
    }
    dp[node] = max_p + 1;
    return dp[node];
}

void solve(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    vector<int> dp(n, -1);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
    }

    int ans = 0;

    for(int node = 0; node < n; node++) {
        ans = max(ans, max_path(node, adj, dp));
    }
    
    cout << ans << '\n';
}

int main(){
    freopen("longpath.in", "r", stdin);
	freopen("longpath.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}

/*
5 5
1 2
2 3
3 4
3 5
1 5
*/
