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

vector<vector<int>> adj;
// dp1[i] = # ways if i is black
// dp2[i] = # ways if i is white
vector<ll> dp1, dp2;

void maxWays(int v, int pv) {
    ll res1 = 1, res2 = 1;
    for(int child : adj[v]) {
        if(child == pv) continue;
        maxWays(child, v);
        res1 = (res1 * dp2[child]) % MOD;
        res2 = (res2 * ((dp1[child] + dp2[child]) % MOD)) % MOD;
    }
    dp1[v] = res1;
    dp2[v] = res2;
}

void solve(){
    int n;
    cin >> n;

    adj.resize(n + 1);
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dp1.resize(n + 1), dp2.resize(n + 1);
    maxWays(1, 0);

    cout << (dp1[1] + dp2[1]) % MOD;
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}