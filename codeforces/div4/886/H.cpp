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

vector<ll> val;

void dfs(int node, vector<vector<pii>>& adj, vector<bool>& visited) {
    
    for(pii edge : adj[node]) {
        if(!visited[edge.first]) {
            visited[edge.first] = true;
            val[edge.first] = val[node] + (ll) edge.second;
            dfs(edge.first, adj, visited);
        }
    }
}

void solve(){
    int n, m;
    cin >> n >> m;
    
    val.resize(n + 1);
    vector<vector<pii>> adj(n + 1);
    vector<vector<int>> orders;
    rep(i, m) {
        int a, b, d;
        cin >> a >> b >> d;
        adj[a].push_back({b, d});
        adj[b].push_back({a, -d});
        orders.push_back({a, b, d});
    }

    vector<bool> visited(n + 1);
    for(int i = 1; i <= n; i++) {
        if(!visited[i]){
            visited[i] = true;
            val[i] = 0;
            dfs(i, adj, visited);
        }
    }

    for(int i = 0; i < m; i++) {
        int a = orders[i][0], b = orders[i][1], d = orders[i][2];

        if(val[a] + d != val[b]) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        solve();
    }
}