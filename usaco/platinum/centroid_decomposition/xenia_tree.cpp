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

const int MAX_N = 2e5;
int n;

vi adj[MAX_N];
int subtreeSize[MAX_N];
bool removed[MAX_N];
int parent[MAX_N];

// ancestors[node] ; first = id_ancestor ; second = distance_ancestor
vector<pii> ancestors[MAX_N];

int minDistance[MAX_N];
queue<int> q;

void calc_subtree_size(int u, int p) {
    parent[u] = p;
    subtreeSize[u] = 1;
    for(int to : adj[u]) {
        if(to != p && !removed[to]) {
            calc_subtree_size(to, u);
            subtreeSize[u] += subtreeSize[to];
        }
    }
}

void calc_distance(int u, int centroid, int p, int cur_distance) {
    ancestors[u].pb({centroid, cur_distance});
    for(int child : adj[u]) {
        if(child != p && !removed[child]) {
            calc_distance(child, centroid, u, cur_distance + 1);
        }
    }
}

void find_centroid(int entryPoint) {
    calc_subtree_size(entryPoint, entryPoint);

    int centroid = entryPoint;
    int bestSize = subtreeSize[entryPoint];
    q.push(entryPoint);

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        int size = subtreeSize[entryPoint] - subtreeSize[u];
        for(int to : adj[u]) {
            if(to != parent[u] && !removed[to]) {
                q.push(to);
                size = max(size, subtreeSize[to]);
            }
        }

        if(bestSize > size) {
            bestSize = size;
            centroid = u;
        }
    }

    for(int u : adj[centroid]) {
        if(!removed[u]) {
            calc_distance(u, centroid, centroid, 1);
        }
    }

    /*printf("After having as centroid %d, the vector ancestor is built in this way:\n", centroid);
    for(int node = 0; node < n; node++) {
        printf("Node %d: ", node);
        for(auto& [anc, dis] : ancestors[node]) {
            printf("Ancestor %d, distance %d ; ", anc, dis);
        }
        printf("\n");
    }
    printf("\n\n");*/

    removed[centroid] = 1;
    for(int to : adj[centroid]) {
        if(!removed[to]) {
            find_centroid(to);
        }
    }
}

void paint(int v) {
    for(auto& [anc, dis] : ancestors[v]) {
        minDistance[anc] = min(minDistance[anc], dis);
    }
    minDistance[v] = 0;
}

void query(int v) {
    int ans = minDistance[v];
    for(auto& [anc, dis] : ancestors[v]) {
        ans = min(ans, dis + minDistance[anc]);
    }
    cout << ans << '\n';
}

void solve(){
    int q;
    cin >> n >> q;
    rep(i, n - 1) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    for(int i = 0; i < n; i++) minDistance[i] = 1e9;

    find_centroid(0);
    paint(0);

    rep(i, q) {
        int op, v;
        cin >> op >> v;
        v--;
        if(op == 1) {
            paint(v);
        } else {
            query(v);
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