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
const ll MAX_N = 200001;
const ll LOG = 25;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

vector<int> adj[MAX_N];
int up[MAX_N][LOG];
int depth[MAX_N];

void dfs(int node, int parent) {
    for(int child : adj[node]) {
        if(child != parent) {
            up[child][0] = node;
            depth[child] = depth[node] + 1;

            for(int k = 1; k < LOG; k++) {
                up[child][k] = up[up[child][k - 1]][k - 1];
            }

            dfs(child, node);
        }
    }
}

int get_boss(int x, int k) {
    if(k > depth[x]) return -1;
    
    for(int j = LOG - 1; j >= 0; j--) {
        if(k & (1 << j)) x = up[x][j];
    }

    return x;
}

void solve(){
    int n, q; cin >> n >> q;
    rep(i, n - 1) {
        int b;
        cin >> b;
        b--;
        adj[b].push_back(i + 1);
    }
    
    dfs(0, -1);

    rep(i, q) {
        int x, k; cin >> x >> k;
        x--;
        int boss = get_boss(x, k);
        cout << (boss == -1 ? -1 : boss + 1) << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    solve();
}