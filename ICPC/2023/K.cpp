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

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e15;
const ll LL_MAX = 9223372036854775807;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

vvi adj;
vvi adj_con;
vector<int> visited;
vi allNodes;

void dfs(int node, ll& nodes, ll& edges, ll& edgesToInvert) {
    allNodes.pb(node);

    visited[node] = 1;
    nodes++;
    edges += adj[node].size();

    for(int& to : adj[node]) {
        if(visited[to] == 0) {
            dfs(to, nodes, edges, edgesToInvert);
        } else if(visited[to] == 2) {
            edgesToInvert++;
        }
    }
}

void dfs_con(int node) {
    visited[node] = 1;

    for(int& to : adj_con[node]) {
        if(visited[to] == 0) {
            dfs_con(to);
        }
    }
}

void solve(){
    int n, m;
    cin >> n >> m;

    ll cplus, cminus;
    cin >> cplus >> cminus;

    adj = vvi(n);
    adj_con = vvi(n);
    visited = vector<int>(n);
    vll arcIn(n);

    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        arcIn[b]++;


        adj_con[a].pb(b);
        adj_con[b].pb(a);
    }

    ll discon_comp = 0;

    for(int i = 0; i < n; i++) {
        if(visited[i] == 0) {
            discon_comp++;
            dfs_con(i);
        }
    }

    ll cost = 0;
    cost += cplus * (discon_comp - 1);

    fill(all(visited), 0);

    for(int i = 0; i < n; i++) {
        ll nodes = 0, edges = 0, edgesToInvert = 0;
        if(visited[i] == 0 && arcIn[i] == 0) {
            dfs(i, nodes, edges, edgesToInvert);

            edges -= edgesToInvert;
            cost += cminus * (edges - (nodes - 1));

            // 1 to invert
            if(edgesToInvert > 0) {
                cost += (cplus + cminus);
                cost += (edgesToInvert - 1) * cminus;
            }

            for(int node : allNodes) visited[node] = 2;
            allNodes.clear();
        }
    }
    

    cout << cost << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    solve();
}