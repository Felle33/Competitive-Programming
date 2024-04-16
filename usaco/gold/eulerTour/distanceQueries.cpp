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
#include <climits>

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

struct Edge {
    int from, to, w;
};

struct SegmentTree {
    int size;
    vector<ll> tree, op;

    ll NEUTRAL_ELEMENT = 0;
    ll NOP = LLONG_MAX;

    SegmentTree(int n) {
        size = 1;
        while(size < n) size *= 2;
        tree.resize(2 * size, NEUTRAL_ELEMENT); op.resize(2 * size, NOP);
    }

    void build(vector<ll>& numbers){
        build(numbers, 0, 0, size);
    }

    void build(vector<ll>& numbers, int x, int lx, int rx) {
        if(rx - lx == 1) {
            if(lx < (int) numbers.size()) {
                tree[x] = numbers[lx];
            }
            return;
        }

        int mid = (lx + rx) / 2;
        build(numbers, 2 * x + 1, lx, mid);
        build(numbers, 2 * x + 2, mid, rx);
        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }

    void propagate(int x, int lx, int rx) {
        if(op[x] == NOP || rx - lx == 1) return;
        int mid = (rx + lx) / 2;
        tree[2 * x + 1] += op[x] * (mid - lx);
        tree[2 * x + 2] += op[x] * (rx - mid);
        op[2 * x + 1] = (op[2 * x + 1] == NOP ? op[x] : op[2 * x + 1] + op[x]);
        op[2 * x + 2] = (op[2 * x + 2] == NOP ? op[x] : op[2 * x + 2] + op[x]);
        op[x] = NOP;
    }

    void add(int l_query, int r_query, ll v, int x, int lx, int rx) {
        propagate(x, lx, rx);
        if(l_query >= rx || r_query <= lx) return;
        if(l_query <= lx && rx <= r_query){
            tree[x] += (rx - lx) * v;
            op[x] = (op[x] == NOP ? v : op[x] + v);
            return;
        }

        int m = (lx + rx) / 2;
        add(l_query, r_query, v, 2 * x + 1, lx, m);
        add(l_query, r_query, v, 2 * x + 2, m, rx);
        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }

    void add(int l_query, int r_query, ll v) {
        add(l_query, r_query, v, 0, 0, size);
    }

    ll sum(int l_query, int r_query, int x, int lx, int rx) {
        propagate(x, lx, rx);
        if(l_query >= rx || r_query <= lx) return NEUTRAL_ELEMENT;
        if(l_query <= lx && rx <= r_query) return tree[x];
        int mid = (lx + rx) / 2;
        ll s1 = sum(l_query, r_query, 2 * x + 1, lx, mid);
        ll s2 = sum(l_query, r_query, 2 * x + 2, mid, rx);
        return s1 + s2;
    }

    ll sum(int l, int r) {
        return sum(l, r, 0, 0, size);
    }
};

vector<vector<pii>> adj;
vi depths;
vll sums;
vector<Edge> edges;
vvi up;
int timer;
vi start, finish;
vll buildVector;

void dfs(int node, int p, int lev = 0) {
    depths[node] = lev;
    start[node] = timer++;
    buildVector.push_back(sums[node]);

    for(pii& pa : adj[node]) {
        int to = pa.first;
        int w = pa.second;
        if(to != p) {
            sums[to] = sums[node] + w;
            up[to][0] = node;
            for(int i = 1; i < LOG; i++) {
                up[to][i] = up[up[to][i - 1]][i - 1];
            }
            dfs(to, node, lev + 1);
        }
    }
    finish[node] = timer;
}

int get_lca(int a, int b) {
    if(depths[a] < depths[b]) swap(a, b);
    int k = depths[a] - depths[b];

    for(int j = 0; j < LOG; j++) {
        if(k & (1 << j)) { a = up[a][j]; }
    }

    if(a == b) return a;

    for(int j = LOG - 1; j >= 0; j--) {
        if(up[a][j] != up[b][j]) {
            a = up[a][j];
            b = up[b][j];
        }
    }

    return up[a][0];
}

void solve(){
    int n;
    cin >> n;

    adj.resize(n);
    depths.resize(n);
    start.resize(n);
    finish.resize(n);
    sums.resize(n);
    edges.resize(n);
    up = vvi(n, vi(LOG));

    rep(i, n - 1) {
        int a, b, w;
        cin >> a >> b >> w;
        a--, b--;
        adj[b].push_back({a, w});
        adj[a].push_back({b, w});
        edges[i] = {a, b, w};
    }

    dfs(0, -1);
    SegmentTree sgt(n);
    sgt.build(buildVector);
    int q; cin >> q;

    rep(i, q) {
        int t; cin >> t;

        if(t == 1) {
            // set with a segment tree with lazy propagation to a continuous set of indeces
            int edgeId, newWeight; cin >> edgeId >> newWeight;
            edgeId--;
            int a = edges[edgeId].from;
            int b = edges[edgeId].to;
            int oldWeigth = edges[edgeId].w;

            if(depths[a] > depths[b]) swap(a, b);
            // b is the deepest
            sgt.add(start[b], finish[b], newWeight - oldWeigth);
            edges[edgeId].w = newWeight;
        } else {
            // find the lca
            // calc the sum from root to first node, from root to second node, from root to lca
            // the res = first + second - 2 * third
            int u, v; cin >> u >> v;
            u--, v--;
            int lca = get_lca(u, v);

            ll first = sgt.sum(start[u], start[u] + 1);
            ll second = sgt.sum(start[v], start[v] + 1);
            ll third = sgt.sum(start[lca], start[lca] + 1);

            cout << first + second - 2 * third << '\n';
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}