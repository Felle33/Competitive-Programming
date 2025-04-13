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
const ll DIM = 1e6;
const int INF = 1e9;
const ll LLINF = 1e15;
const ll LL_MAX = 9223372036854775807;
const int LOG = 22;
vector<int> DI = {0, 1, -1, 0};
vector<int> DJ = {1, 0, 0, -1};

int n, m;
vector<vector<int>> adj;
vector<int> times;

void bfs() {
    vector<bool> visited(n + 1);
    queue<int> q;
    q.push(1);
    visited[1] = 1;
    times[1] = 0;

    while(!q.empty()) {
        int node = q.front(); q.pop();

        for(int to : adj[node]) {
            if(visited[to]) continue;
            times[to] = times[node] + 1;
            q.push(to);
            visited[to] = 1;
        }
    }
}

void solve(){
    cin >> n >> m;
    adj = vvi(n + 1);
    times = vi(n + 1);
    vector<pii> bridges(m);
    vector<int> pref(n + 10);
    for(int i = 1; i < n; i++) adj[i].push_back(i + 1);
    rep(i, m) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        bridges[i] = {a, b};
    }

    bfs();

    for(pii& bridge : bridges) {
        int start = bridge.first + 1;
        int end = bridge.second - times[bridge.first] - 1;

        if(start < end) {
            pref[start]++;
            if(pref[end] < n + 5) pref[end]--;
        }
    }

    for(int i = 1; i <= n - 1; i++) {
        pref[i] += pref[i - 1];
        if(pref[i] > 0) {
            cout << 0;
        } else {
            cout << 1;
        }
    }

    cout << "\n";
}

int main(){
    FELLE
    int t; cin >> t;
    while(t--){
        solve();
    }
}