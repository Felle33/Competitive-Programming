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
#include <sstream>

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
const int INF = 1e9;
const ll LLINF = 1e15;
const int INF_INT = 1e9;
const ll LL_MAX = 9223372036854775807;
const int LOG = 22;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};

vi dfs_low, dfs_num, visited, st;
vvi adj;
int dtime = 0;
map<string, int> mapp;
map<int, string> mappInv;

void tarjanSCC(int u) {
    dfs_num[u] = dfs_low[u] = dtime++;
    visited[u] = 1;
    st.push_back(u);
    for(int to : adj[u]) {
        if(dfs_num[to] == -1) tarjanSCC(to);
        if(visited[to]) dfs_low[u] = min(dfs_low[u], dfs_low[to]);
    }

    if(dfs_low[u] == dfs_num[u]) {
        // Create the connected component
        int v = st.back(); st.pop_back();
        visited[v] = 0;
        if(u == v) {
            cout << "\n" << mappInv[v];
        } else {
            cout << "\n" << mappInv[v];
            while(1) {
                v = st.back(); st.pop_back(); visited[v] = 0;
                cout << ", " << mappInv[v];
                if(v == u) break;
            }
        }
    }
}

void solve() {
    int t = 0;
    while(1) {
        int n, m; cin >> n >> m;
        if(n == 0 && m == 0) break;
        if(t > 0) cout << "\n";

        mapp.erase(all(mapp)); mappInv.erase(all(mappInv));
        dfs_low = vi(n); dfs_num = vi(n, -1); visited = vi(n, 0);
        int k = 0;
        adj = vvi(n);
        rep(i, m) {
            string a, b; cin >> a >> b;

            if(!mapp.count(a)) {mapp[a] = k; mappInv[k++] = a;}
            if(!mapp.count(b)) {mapp[b] = k; mappInv[k++] = b;}
            adj[mapp[a]].pb(mapp[b]);
        }

        cout << "Calling circles for data set " << ++t << ":";
        rep(i, n) {
            if(dfs_num[i] == -1) {
                tarjanSCC(i);
            }
        }
        cout << "\n";
    }
}

int main(){
    //freopen("catch.in", "r", stdin);
	//freopen("catch.out", "w", stdout);
    solve();
}