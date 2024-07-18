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
#define RED 0
#define GREEN 1
#define BLUE 2

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e9;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

vector<vector<int>> adj;
vector<vector<ll>> dp;
vector<int> colors;

bool leaf(int u, int p) {
    return adj[u].size() == 1 && adj[u][0] == p;
}

void ways(int u, int p) {
    if(leaf(u, p)) {
        if(colors[u] == -1) {
            dp[u][RED] = dp[u][GREEN] = dp[u][BLUE] = 1;
        } else {
            dp[u][colors[u]] = 1;
        }
        return;
    }

    for(int to : adj[u]) {
        if(to != p) ways(to, u);
    }

    if(colors[u] == -1) {
        for(int i = 0; i < 3; i++) {
            dp[u][i] = 1;
            for(int to : adj[u]) {
                if(to == p) continue;

                if(i == 0) dp[u][0] = (dp[u][0] * ((dp[to][1] + dp[to][2]) % MOD)) % MOD;
                else if(i == 1) dp[u][1] = (dp[u][1] * ((dp[to][0] + dp[to][2]) % MOD)) % MOD;
                else dp[u][2] = (dp[u][2] * ((dp[to][0] + dp[to][1]) % MOD)) % MOD;
            }
        }
        
        return;
    }

    dp[u][colors[u]] = 1;
    for(int to : adj[u]) {
        if(to == p) continue;

        if(colors[u] == 0) dp[u][0] = (dp[u][0] * ((dp[to][1] + dp[to][2]) % MOD)) % MOD;
        else if(colors[u] == 1) dp[u][1] = (dp[u][1] * ((dp[to][0] + dp[to][2]) % MOD)) % MOD;
        else dp[u][2] = (dp[u][2] * ((dp[to][0] + dp[to][1]) % MOD)) % MOD;
    }
}

void solve(){
    int n, k;
    cin >> n >> k;

    adj.resize(n + 1);
    colors.resize(n + 1, -1);
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    rep(i, k) {
        int a, c; cin >> a >> c;
        c--;
        colors[a] = c;
    }

    dp = vector<vector<ll>>(n + 1, vector<ll>(3));
    ways(1, 0);
    cout << (dp[1][0] + dp[1][1] + dp[1][2]) % MOD << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("barnpainting.in", "r", stdin);
	freopen("barnpainting.out", "w", stdout);
    solve();
}