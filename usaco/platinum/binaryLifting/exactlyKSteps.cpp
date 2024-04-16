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
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

int n;
vvi adj;
vvi up1, up2;
vi depth1, depth2;
const int LOG = 20;

void dfs(int node, int parent, vi& depth, vvi& up, int lev = 0) {
    for(int to : adj[node]) {
        if(to != parent) {
            depth[to] = lev + 1;
            up[to][0] = node;
            for(int i = 1; i < LOG; i++) {
                up[to][i] = up[up[to][i - 1]][i - 1];
            }
            dfs(to, node, depth, up, lev + 1);
        }
    }
}

int binaryLiftingK(int u, int k, vvi& up, vi& depth) {
    if(k > depth[u]) return -2;

    for(int i = 0; i < LOG; i++) {
        if(k & (1 << i)) u = up[u][i];
    }

    return u;
}

int mostDistant(int start) {
    int mostDistant = -1;
    queue<int> q;
    vector<bool> visited(n);

    q.push(start);
    visited[start] = 1;

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        mostDistant = node;

        for(int to : adj[node]) {
            if(!visited[to]) {
                visited[to] = 1;
                q.push(to);
            }
        }
    }
    return mostDistant;
}

void solve(){
    cin >> n;
    adj = vvi(n);
    up1 = vvi(n, vi(LOG));
    up2 = vvi(n, vi(LOG));
    depth1 = vi(n);
    depth2 = vi(n);

    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int root1 = mostDistant(0);
    int root2 = mostDistant(root1);

    dfs(root1, -1, depth1, up1);
    dfs(root2, -1, depth2, up2);

    int q; cin >> q;
    rep(i, q) {
        int u, k; cin >> u >> k;
        u--;

        int res = binaryLiftingK(u, k, up1, depth1);

        if(res != -2) cout << res + 1 << '\n';
        else cout << binaryLiftingK(u, k, up2, depth2) + 1 << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    solve();
}