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
const ll INF = 1e15;
const int INF_INT = 1e9;
const ll LL_MAX = 9223372036854775807;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

int n, m;
vector<ll> dist;
vector<vector<pii>> adj;

void bfs(int start, ll s_min, ll starting_distance) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
    q.push({starting_distance, start});
    vector<bool> visited(n);

    while(!q.empty()) {
        int node = q.top().second;
        ll dis = q.top().first;
        q.pop();

        if(visited[node]) continue;
        visited[node] = 1;

        for(pii p : adj[node]) {
            int to = p.first;
            ll w = p.second;

            if(!visited[to]) {
                dist[to] = min(dist[to], dis + w * s_min);
                q.push({dis + w * s_min, to});
            }
        }
    }
}

void solve(){
    cin >> n >> m;
    adj = vector<vector<pii>>(n);
    dist = vector<ll>(n, INF);
    vector<ll> s(n);

    rep(i, m) {
        int a, b, w; cin >> a >> b >> w;
        a--, b--;
        adj[a].pb({b, w});
        adj[b].pb({a, w});
    }

    rep(i, n) {
        cin >> s[i];
    }

    vector<bool> started(n);
    ll s_min = s[0];
    dist[0] = 0;
    started[0] = 1;
    bfs(0, s_min, 0);
    
    for(int i = 0; i < n - 1; i++) {
        // take the minimum not visited
        int mn = -1;
        ll dis = INF;
        for(int j = 0; j < n; j++) {
            if(!started[j] && dist[j] < dis) {
                dis = dist[j];
                mn = j;
            }
        }

        started[mn] = 1;
        s_min = min(s_min, s[mn]);
        bfs(mn, s_min, dis);
    }

    cout << dist[n - 1] << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    int t;
    cin >> t;

    while(t--){
        solve();
    }
}