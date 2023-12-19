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
vector<bool> visited;

void dfs_con(int node) {
    visited[node] = 1;

    for(int to : adj[node]) {
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
    visited = vector<bool>(n);

    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    ll arcs = m;
    ll cost = 0;

    dfs_con(0);
    for(int i = 1; i < n; i++) {
        if(!visited[i]) {
            cost += cplus;
            arcs++;
            dfs_con(i);
        }
    }

    cost += (arcs - (n - 1)) * cminus;
    
    cout << cost << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    solve();
}