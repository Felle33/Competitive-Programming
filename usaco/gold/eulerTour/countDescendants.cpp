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
typedef long double ld;

const ll MOD1 = 1e9 + 7;
const ll MOD2 = 998244353;
const ll MOD3 = 99999999999999997;
const ll DIM = 1e6;
const ll INF = 1e15;
const int INF_INT = 1e9;
const ll LL_MAX = 9223372036854775807;
const int LOG = 22;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

vvi adj;
vi depths;
vector<map<int, int>> maps;

void dfs(int node, int p, int lev = 0) {
    depths[node] = lev;
    maps[node][0] = 1;
    for(int to : adj[node]) {
        if(to != p) {
            dfs(to, node, lev + 1);
            //if(maps[node].size() < maps[to].size()) swap(maps[node], maps[to]);
            for(auto it = maps[to].begin(); it != maps[to].end(); it++) {
                maps[node][it->first + 1] += it->second;
            }
        }
    }
}

// TLE
void solve(){
    int n; cin >> n;
    adj = vvi(n);
    depths = vi(n);
    maps = vector<map<int, int>>(n);

    rep(i, n - 1) {
        int a; cin >> a;
        a--;
        adj[i + 1].pb(a);
        adj[a].pb(i + 1);
    }

    dfs(0, -1);

    int q; cin >> q;
    rep(i, q) {
        int u, d; cin >> u >> d;
        u--;

        if(d < depths[u]) {
            cout << 0 << '\n';
        } else {
            cout << maps[u][d - depths[u]] << '\n';
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