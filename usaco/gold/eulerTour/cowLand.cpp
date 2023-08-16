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
#define f first
#define s second
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e9;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

vector<vector<int>> adj;
vector<ll> pathXor;
vector<ll> vals;
vector<ll> subtreeSize;
int nNodeVisited = 0;
vector<int> trans;
vector<int> depths;
vector<int> first;
vector<int> nodes;

struct SegmentTree {
    int size;
    vector<ll> tree;

    SegmentTree(int n) {
        size = 1;
        while(size < n) size *= 2;
        tree.resize(2 * size, 0LL);
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

    void set(int l_query, int r_query, int v, int x, int lx, int rx) {
        if(l_query >= rx || r_query <= lx) return;
        if(l_query <= lx && rx <= r_query){
            tree[x] ^= v;
            return;
        } 

        int mid = (lx + rx) / 2;
        set(l_query, r_query, v, 2 * x + 1, lx, mid);
        set(l_query, r_query, v, 2 * x + 2, mid, rx);
    }

    void set(int l, int r, int v) {
        set(l, r, v, 0, 0, size);
    }

    // l_query = da dove inizia la query
    // r_query = dove finisce la query non compresa
    // x = nodo
    // lx = dove inizia la zona di competenza del nodo
    // rx = dove finisce la zona di competenza del nodo non compreso
    ll retrieve(int i, int x, int lx, int rx) {
        if(rx - lx == 1) return tree[x];
        int mid = (lx + rx) / 2;
        ll s1;
        if(i < mid) {
            s1 = retrieve(i, 2 * x + 1, lx, mid);
        } else {
            s1 = retrieve(i, 2 * x + 2, mid, rx);
        }
        return s1 ^ tree[x];
    }

    ll retrieve(int i) {
        return retrieve(i, 0, 0, size);
    }
};

struct SegmentTreeLCA {
    int size;
    // pair in which first is the min depth and second is the index
    vector<pair<int, int>> tree;

    SegmentTreeLCA(int n) {
        size = 1;
        while(size < n) size *= 2;
        tree.resize(2 * size, make_pair(INF, -1));
    }

    void build(vector<int>& depths, vector<int>& nodes){
        build(depths, nodes, 0, 0, size);
    }

    void build(vector<int>& depths, vector<int>& nodes, int x, int lx, int rx) {
        if(rx - lx == 1) {
            if(lx < (int) depths.size()) {
                tree[x] = {depths[lx], nodes[lx]};
            }
            return;
        }

        int mid = (lx + rx) / 2;
        build(depths, nodes, 2 * x + 1, lx, mid);
        build(depths, nodes, 2 * x + 2, mid, rx);
        if(tree[2 * x + 1].first <= tree[2 * x + 2].first) {
            tree[x] = tree[2 * x + 1];
        } else {
            tree[x] = tree[2 * x + 2];
        }
    }

    // l_query = da dove inizia la query
    // r_query = dove finisce la query non compresa
    // x = nodo
    // lx = dove inizia la zona di competenza del nodo
    // rx = dove finisce la zona di competenza del nodo non compreso
    pair<int, int> LCA(int l_query, int r_query, int x, int lx, int rx) {
        if(r_query <= lx || l_query >= rx) return {INF, -1};
        if(l_query <= lx && rx <= r_query) return tree[x];

        int mid = (lx + rx) / 2;
        pii s1 = LCA(l_query, r_query, 2 * x + 1, lx, mid);
        pii s2 = LCA(l_query, r_query, 2 * x + 2, mid, rx);

        if(s1.first <= s2.first) {
            return s1;
        } else {
            return s2;
        }
    }

    pair<int, int> LCA(int a, int b) {
        int l = min(first[a], first[b]);
        int r = max(first[a], first[b]);
        return LCA(l, r + 1, 0, 0, size);
    }
};

int dfs(int node, int parent, ll sum, int depth) {
    nodes.push_back(node);
    depths.push_back(depth);
    first[node] = nodes.size() - 1;
    trans[node] = nNodeVisited;
    nNodeVisited++;
    ll size = 1;
    ll newSum = sum ^ vals[node];
    pathXor.push_back(newSum);

    for(int son : adj[node]) {
        if(son != parent) {
            size += dfs(son, node, newSum, depth + 1);
            nodes.push_back(node);
            depths.push_back(depth);
        }
    }

    subtreeSize[node] = size;
    return size;
}

void solve(){
    int n, q;
    cin >> n >> q;

    adj.resize(n);
    vals.resize(n);
    subtreeSize.resize(n);
    first.resize(n);
    trans.resize(n);
    rep(i, n) {
        cin >> vals[i];
    }

    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[b].push_back(a);
        adj[a].push_back(b);
    }

    dfs(0, -1, 0, 0);
    SegmentTreeLCA sgtLCA(n);
    sgtLCA.build(depths, nodes);

    SegmentTree sgtXor(n);
    sgtXor.build(pathXor);
    rep(i, q) {
        int op;
        cin >> op;

        if(op == 1) {
            int u, x;
            cin >> u >> x;
            u--;
            int nodeInPath = trans[u];
            sgtXor.set(nodeInPath, nodeInPath + subtreeSize[u], x ^ vals[u]);
            vals[u] = x;
        } else {
            int a, b;
            cin >> a >> b;
            a--, b--;
            // calculate the enjoy
            int lca = sgtLCA.LCA(a, b).second;
            int resA = sgtXor.retrieve(a);
            int resB = sgtXor.retrieve(b);
            int resLCA = vals[lca];
            int res = resA ^ resB ^ resLCA;
            cout << res << '\n';
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