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

const int MAX_N = 10;

int n, m;
int source;
int sink;

vi adj[MAX_N];
ll cap[MAX_N][MAX_N];
bool visited[MAX_N];

ll dfs(int node, int sink, ll minCapacity) {
    if(node == sink) return minCapacity;
    visited[node] = 1;
    
    for(int to : adj[node]) {
        if(cap[node][to] > 0 && !visited[to]) {
            ll res = dfs(to, sink, min(minCapacity, cap[node][to]));
            if(res > 0) {
                cap[node][to] -= res;
                cap[to][node] += res;
                return res;
            }
        }
    }

    return 0;
}

ll ford_fulkerson(int source, int sink) {
    ll result = 0;
    while(1) {
        ll currFlow  = dfs(source, sink, INF);
        result += currFlow;

        if(currFlow  == 0) break;
        for(int i = 0; i < MAX_N; i++) visited[i] = 0;
    }

    return result;
}

void dfs_print(int node, int num) {
    if(node == 0) {
        cout << num << '\n' << node + 1 << ' ';
        return;
    }

    for(int to : adj[node]) {
        if(cap[node][to] > 0) {
            dfs_print(to, num + 1);
            if(node == n - 1) {
                cout << node + 1 << '\n';
            } else {
                cout << node + 1 << ' ';
            }
        }
    }
}

void solve(){
    cin >> n >> m;

    rep(i, m) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].pb(b);
        adj[b].pb(a);
        cap[a][b] += 1;
    }

    source = 0, sink = n - 1;

    cout << ford_fulkerson(source, sink) << '\n';
    dfs_print(n - 1, 1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    solve();
}