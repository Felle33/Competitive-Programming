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
const int LOG = 20;

int n;

vi adj[MAX_N];
int num_in_node[MAX_N];
int up[MAX_N][LOG];
int parent[MAX_N];
int subtreeSize[MAX_N];
int depths[MAX_N];
// bigchild[i] = who is the bigchild of i
int bigChild[MAX_N];
// where a node is labeled in the segment tree
int label[MAX_N];
// where the heavy chain starts for each node
int chain[MAX_N];
vi build_array_sgt;

int label_time = 0;

template <typename T, int n>
struct SegmentTree {
    int size;
    vector<T> tree;

    T NEUTRAL_ELEMENT = 0;

    SegmentTree() {
        size = 1;
        while(size < n) size *= 2;
        tree.resize(2 * size, NEUTRAL_ELEMENT);
    }

    void build(vector<T>& numbers){
        build(numbers, 0, 0, size);
    }

    void build(vector<T>& numbers, int x, int lx, int rx) {
        if(rx - lx == 1) {
            if(lx < (int) numbers.size()) {
                tree[x] = numbers[lx];
            }
            return;
        }

        int mid = (lx + rx) / 2;
        build(numbers, 2 * x + 1, lx, mid);
        build(numbers, 2 * x + 2, mid, rx);
        tree[x] = max(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void set(int i, int v, int x, int lx, int rx) {
        if(rx - lx == 1) {
            tree[x] = v;
            return;
        }

        int m = (lx + rx) / 2;
        if(i < m) {
            set(i, v, 2 * x + 1, lx, m);
        } else {
            set(i, v, 2 * x + 2, m, rx);
        }
        tree[x] = max(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    // l_query = da dove inizia la query
    // r_query = dove finisce la query non compresa
    // x = nodo
    // lx = dove inizia la zona di competenza del nodo
    // rx = dove finisce la zona di competenza del nodo non compreso
    T maxi(int l_query, int r_query, int x, int lx, int rx) {
        if(l_query >= rx || r_query <= lx) return NEUTRAL_ELEMENT;
        if(l_query <= lx && rx <= r_query) return tree[x];
        int mid = (lx + rx) / 2;
        T s1 = maxi(l_query, r_query, 2 * x + 1, lx, mid);
        T s2 = maxi(l_query, r_query, 2 * x + 2, mid, rx);
        return max(s1, s2);
    }

    T maxi(int l, int r) {
        return maxi(l, r, 0, 0, size);
    }
};

void compute_subtree_size(int u, int p) {
    parent[u] = p;
    subtreeSize[u] = 1;
    int bChild = -1, bSize = -1;

    for(int to : adj[u]) {
        if(to != p) {
            depths[to] = depths[u] + 1;
            up[to][0] = u;

            for(int i = 1; i < LOG; i++) {
                up[to][i] = up[up[to][i - 1]][i - 1];
            }

            compute_subtree_size(to, u);
            subtreeSize[u] += subtreeSize[to];
            if(subtreeSize[to] > bSize) {
                bSize = subtreeSize[to];
                bChild = to;
            }
        }
    }
    bigChild[u] = bChild;
}

void dfs_label(int u, int p) {
    label[u] = label_time++;
    // update of the segment tree
    build_array_sgt.pb(num_in_node[u]);

    if(bigChild[u] != -1) {
        dfs_label(bigChild[u], u);
    }

    for(int to : adj[u]) {
        if(to != p && to != bigChild[u]) {
            dfs_label(to, u);
        }
    }
}

void dfs_chain(int u, int p) {
    if(bigChild[u] != -1) {
        chain[bigChild[u]] = chain[u];
    }

    for(int to : adj[u]) {
        if(to != p) {
            dfs_chain(to, u);
        }
    }
}

int get_lca(int a, int b) {
    if(depths[a] < depths[b]) swap(a, b);

    int dif = depths[a] - depths[b];
    for(int k = 0; k < LOG; k++) {
        if(dif & (1 << k)) {
            a = up[a][k];
        }
    }

    if(a == b) return a;

    for(int k = 0; k < LOG; k++) {
        if(up[a][k] != up[b][k]) {
            a = up[a][k];
            b = up[b][k];
        }
    }
    return up[a][0];
}

int query_chain(int u, int lca, SegmentTree<int, MAX_N>& sgt) {
    int ans = 0;
    while(depths[lca] < depths[u]) {
        int top = chain[u];
        int dif = depths[u] - depths[top];
        if(depths[top] <= depths[lca]) {
            // posso farlo perchè le labels di sequenze di heavy paths sono numeri
            // consecutivi, in questo caso prendo anche l'lca
            dif = depths[u] - depths[lca];
        }
        // sgt funziona al contrario, prima top e poi u
        ans = max(ans, sgt.maxi(label[u] - dif, label[u] + 1));
        u = parent[top];
    }
    return ans;
}

void hdl(int root = 0) {
    depths[root] = 0;
    compute_subtree_size(root, root);
    #ifdef DEBUG
    printf("BIGCHILDS\n");
    for(int i = 0; i < n; i++) {
        printf("The bigchild of %d is %d\n", i, bigChild[i]);
    }
    printf("-----------------------------------------------\n");
    #endif

    dfs_label(root, root);
    #ifdef DEBUG
    printf("LABELS\n");
    for(int i = 0; i < n; i++) {
        printf("The label of %d is %d\n", i, label[i]);
    }
    printf("-----------------------------------------------\n");
    #endif

    dfs_chain(root, root);
    #ifdef DEBUG
    printf("CHAINS\n");
    for(int i = 0; i < n; i++) {
        printf("The beginning of the chain of %d is %d\n", i, chain[i]);
    }
    printf("-----------------------------------------------\n");
    #endif
}

void solve(){
    int q;
    cin >> n >> q;
    rep(i, n) cin >> num_in_node[i];

    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    for(int i = 0; i < n; i++) {
        bigChild[i] = -1;
        chain[i] = i;
    }
    build_array_sgt.reserve(MAX_N);

    hdl();
    SegmentTree<int, MAX_N> sgt;
    sgt.build(build_array_sgt);

    rep(i, q) {
        int op, a, b;
        cin >> op >> a >> b;

        if(op == 1) {
            // change the value of the node
            // change on the segment tree with label
            a--;
            sgt.set(label[a], b);
        } else {
            // compute max in the path from a to b
            a--, b--;
            int lca = get_lca(a, b);
            // query on segment tree
            // NON FUNZIONA QUA (SECONDO ME)
            int ans1 = query_chain(a, lca, sgt);
            int ans2 = query_chain(b, lca, sgt);
            int ans = max({ans1, ans2, num_in_node[lca]});
            cout << ans << ' ';
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

/*
10 10
9 2 1 1 1 4 2 10 7 4
2 1
3 2
4 2
5 4
6 5
7 6
8 4
9 8
10 2
2 5 4
1 10 4
1 5 9
2 5 4
2 9 5
2 1 10
2 1 6
1 8 4
1 3 5
2 6 1
*/