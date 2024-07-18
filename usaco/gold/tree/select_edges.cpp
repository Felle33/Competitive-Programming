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
const ll INF = 1e11;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

vector<vector<pair<int, int>>> adj;
vector<int> di;
vector<ll> dp1, dp2;

bool leaf(int u, int p) {
    return adj[u].size() == 1 && adj[u][0].first == p;
}

void dfs(int u, int p) {
    ll atMost = 0;
    if(di[u] == 0) {
        dp2[u] = -INF;
        for(pair<int, int>& pa : adj[u]) {
            int to = pa.first;

            if(to == p) continue;
            dfs(to, u);

            atMost += dp1[to];
        }
        dp1[u] = atMost;
        return;
    }
    
    priority_queue<ll> pq;
    for(pair<int, int>& pa : adj[u]) {
        int to = pa.first;

        if(to == p) continue;
        dfs(to, u);

        atMost += dp1[to];
        pq.push(dp2[to] + pa.second - dp1[to]);
    }

    int edgesChosen = 0;
    ll delta = 0;
    ll less_value = INF;
    while(edgesChosen < di[u] && !pq.empty() && pq.top() > 0) {
        ll top = pq.top(); pq.pop();
        delta += top;
        edgesChosen++;
        less_value = min(less_value, top);
    }

    if(edgesChosen == di[u]) {
        dp1[u] = atMost + delta;
        dp2[u] = atMost + delta - less_value;
    } else {
        dp1[u] = dp2[u] = atMost + delta;
    }
}

void solve(){
    int n;
    cin >> n;

    di.resize(n);
    adj.resize(n);
    dp1.resize(n);
    dp2.resize(n);

    rep(i, n) cin >> di[i];
    rep(i, n - 1) {
        int a, b, w; cin >> a >> b >> w;
        a--, b--;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    dfs(0, -1);
    
    cout << max(dp1[0], dp2[0]) << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
}