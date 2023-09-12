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
const ll LOG = 18;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

vvi adj;
vi euler_tour;
vll ent;
vll pathXor;
vi start;
vi finish;
int timer;
// LCA
vi depth;
//up
vvi up;

struct SegmentTree {
    int size;
    vector<ll> tree;

    ll NEUTRAL_ELEMENT = 0LL;

    SegmentTree(int n) {
        size = 1;
        while(size < n) size *= 2;
        tree.resize(2 * size, NEUTRAL_ELEMENT);
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
    }

    void set_range(int l_range, int r_range, int x, int lx, int rx, ll new_value, ll old_value) {
        if(l_range >= rx || r_range <= lx) return;
        if(l_range <= lx && rx <= r_range) {
            tree[x] = tree[x] ^ old_value ^ new_value;
            return;
        }

        int mid = (lx + rx) / 2;
        set_range(l_range, r_range, 2 * x + 1, lx, mid, new_value, old_value);
        set_range(l_range, r_range, 2 * x + 2, mid, rx, new_value, old_value);
    }

    void set_range(int l_range, int r_range, ll new_value, ll old_value) {
        set_range(l_range, r_range, 0, 0, size, new_value, old_value);
    }

    ll retrieve(int i, int x, int lx, int rx) {
        if(rx - lx == 1) {
            return tree[x];
        }

        int m = (lx + rx) / 2;
        if(i < m) {
           return tree[x] ^ retrieve(i, 2 * x + 1, lx, m);
        } 
        
        return tree[x] ^ retrieve(i, 2 * x + 2, m, rx);
    }

    ll retrieve(int i) {
        return retrieve(i, 0, 0, size);
    }
};

void dfs(int node, int parent, ll xorCur) {
    euler_tour.pb(node);
    start[node] = timer++;
    xorCur ^= ent[node];
    pathXor[node] = xorCur;

    for(int child : adj[node]) {
        if(child != parent) {
            depth[child] = depth[node] + 1;

            up[child][0] = node;
            for(int i = 1; i < LOG; i++) {
                up[child][i] = up[up[child][i - 1]][i - 1];
            }

            dfs(child, node, xorCur);
        }
    }

    finish[node] = timer;
}

// get the node corresponding to lca of a and b
int get_lca(int a, int b) {
    if(depth[a] < depth[b]) swap(a, b);

    ll k = depth[a] - depth[b];
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
    ll n, q; cin >> n >> q;
    adj = vvi(n);
    ent = vll(n);
    pathXor = vll(n);
    start = vi(n), finish = vi(n);
    depth = vi(n);
    up = vvi(n, vi(LOG));

    rep(i, n) cin >> ent[i];
    rep(i, n - 1) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    dfs(0, -1, 0);

    vll pathXorEuler;
    for(int i = 0; i < n; i++) {
        pathXorEuler.pb(pathXor[euler_tour[i]]);
    }

    SegmentTree sgt(n);
    sgt.build(pathXorEuler);

    rep(i, q) {
        int op; cin >> op;
        if(op == 1) {
            ll node, newe; cin >> node >> newe;
            node--;

            ll s = start[node];
            ll e = finish[node];
            sgt.set_range(s, s + (e - s), newe, ent[node]);
            ent[node] = newe;
        } else {
            ll a, b; cin >> a >> b;
            a--, b--;

            ll lca = get_lca(a, b);
            ll ea = sgt.retrieve(start[a]), eb = sgt.retrieve(start[b]), elca = ent[lca];
            ll ans = ea ^ eb ^ elca;
            cout << ans << '\n';
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("cowland.in", "r", stdin);
	freopen("cowland.out", "w", stdout);
    solve();
}