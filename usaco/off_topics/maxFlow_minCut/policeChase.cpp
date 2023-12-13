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

vvi adj;
vvi cap;
vector<bool> visited;

int dfs(int node, int sink, int minCapacity, vector<bool>& visited) {
    if(node == sink) return minCapacity;
    visited[node] = 1;
    
    for(int to : adj[node]) {
        if(cap[node][to] > 0 && !visited[to]) {
            int res = dfs(to, sink, min(minCapacity, cap[node][to]), visited);
            if(res > 0) {
                cap[node][to] -= res;
                cap[to][node] += res;
                return res;
            }
        }
    }

    return 0;
}

int ford_fulkerson(int source, int sink) {
    int result = 0;
    while(1) {
        int currFlow  = dfs(source, sink, INF_INT, visited);
        result += currFlow;

        if(currFlow  == 0) break;
        fill(all(visited), 0);
    }

    return result;
}

void compute_s_group(int node, vi& source_group, vector<bool>& visited) {
    source_group.pb(node);
    visited[node] = 1;

    for(int to : adj[node]) {
        if(!visited[to] && cap[node][to] > 0) {
            compute_s_group(to, source_group, visited);
        }
    }
}

void solve(){
    cin >> n >> m;
    adj = vvi(n);
    cap = vvi(n, vi(n, 1));
    visited = vector<bool>(n);

    rep(i, m) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    cout << ford_fulkerson(0, n - 1) << '\n';

    vi source_group;
    fill(all(visited), 0);
    compute_s_group(0, source_group, visited);
    set<int> sink_group;

    for(int i = 1; i < n; i++) {
        if(!visited[i]) {
            sink_group.insert(i);
        }
    }

    for(int node : source_group) {
        for(int to : adj[node]) {
            if(sink_group.count(to)) {
                cout << node + 1 << " " << to + 1 << '\n';
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    solve();
}