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
const ll LOG = 20;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

int n, q, r;
vector<int> oranges;
vector<vector<int>> adj;
vector<int> euler_tour;
vector<int> start;
vector<int> finish;
vector<vector<int>> up;
vi depth;

int timer;

struct SegmentTree {
    int size;
    vector<bitset<251>> tree;

    bitset<251> NEUTRAL_ELEMENT;

    SegmentTree(int n) {
        size = 1;
        while(size < n) size *= 2;
        tree.resize(2 * size, NEUTRAL_ELEMENT);
    }

    void build(vector<ll>& numbers){
        build(numbers, 0, 0, size);
    }

    bitset<251> merge(bitset<251>& b1, bitset<251>& b2) {
        return b1 | b2;
    }

    void build(vector<ll>& numbers, int x, int lx, int rx) {
        if(rx - lx == 1) {
            if(lx < (int) numbers.size()) {
                tree[x] = NEUTRAL_ELEMENT;
                tree[x][numbers[lx]] = 1;
            }
            return;
        }

        int mid = (lx + rx) / 2;
        build(numbers, 2 * x + 1, lx, mid);
        build(numbers, 2 * x + 2, mid, rx);
        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
    }

    // l_query = da dove inizia la query
    // r_query = dove finisce la query non compresa
    // x = nodo
    // lx = dove inizia la zona di competenza del nodo
    // rx = dove finisce la zona di competenza del nodo non compreso
    // [l_query, r_query)    [lx, rx)
    bitset<251> get_oranges(int l_query, int r_query, int x, int lx, int rx) {
        if(l_query >= rx || r_query <= lx) return NEUTRAL_ELEMENT;
        if(l_query <= lx && rx <= r_query) return tree[x];
        int mid = (lx + rx) / 2;
        bitset<251> s1 = get_oranges(l_query, r_query, 2 * x + 1, lx, mid);
        bitset<251> s2 = get_oranges(l_query, r_query, 2 * x + 2, mid, rx);
        return merge(s1, s2);
    }

    ll get_oranges(int l, int r) {
        return get_oranges(l, r, 0, 0, size).count();
    }
};

void dfs(int node, int parent) {
    euler_tour.pb(node);
    start[node] = timer++;
    for(int child : adj[node]) {
        if(child != parent) {
            depth[child] = depth[node] + 1;
            up[child][0] = node;
            for(int i = 1; i < LOG; i++) {
                up[child][i] = up[up[child][i - 1]][i - 1];
            }
            dfs(child, node);
        }
    }
    finish[node] = timer;
}

int get_lca(int a, int b) {
    if(depth[a] < depth[b]) swap(a, b);
    int k = depth[a] - depth[b];

    for(int i = LOG - 1; i >= 0; i--) {
        if(k & (1 << i)) a = up[a][i];
    }

    if(a == b) return a;

    for(int i = LOG - 1; i >= 0; i--) {
        if(up[a][i] != up[b][i]) {
            a = up[a][i];
            b = up[b][i];
        }
    }

    return up[a][0];
}

void solve(){
    cin >> n >> q >> r;
    oranges = vi(n);
    rep(i, n) cin >> oranges[i];
    adj = vvi(n);
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    euler_tour.clear();
    start = vi(n);
    finish = vi(n);
    depth = vi(n);
    up = vvi(n, vi(LOG));
    timer = 0;

    for(int i = 0; i < LOG; i++) {
        up[r][i] = r;
    }

    dfs(r, -1);
    vector<ll> newOranges(n);
    for(int i = 0; i < n; i++) {
        newOranges[i] = oranges[euler_tour[i]];
    }

    SegmentTree st(n);
    st.build(newOranges);

    rep(i, q) {
        int a, b;
        cin >> a >> b;
        int lca = get_lca(a, b);
        int index = start[lca];
        int diff = finish[lca] - start[lca];
        cout << st.get_oranges(index, index + diff) << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    int t;
    cin >> t;

    while(t--){
        solve();
    }
}