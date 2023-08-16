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
vector<ll> pathSum;
vector<ll> vals;
vector<ll> subtreeSize;
int nNodeVisited = 0;
// where the subtree of i is connected in the pathSum
// ex: trans[5] = 1 -> the subtree of the node 5 starts in pathSum[1]
// if vals[5] changes, also the subtree of node 5 changes and I have to
// set a new value for all the subtree
vector<int> trans;

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
            tree[x] += v;
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
        return s1 + tree[x];
    }

    ll retrieve(int i) {
        return retrieve(i, 0, 0, size);
    }
};

int dfs(int node, int parent, ll sum) {
    trans[node] = nNodeVisited;
    nNodeVisited++;
    ll size = 1;
    ll newSum = sum + vals[node];
    pathSum.push_back(newSum);

    for(int son : adj[node]) {
        if(son != parent) {
            size += dfs(son, node, newSum);
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
    trans.resize(n);
    subtreeSize.resize(n);
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

    dfs(0, -1, 0);

    SegmentTree sgt(n);
    sgt.build(pathSum);
    rep(i, q) {
        int op;
        cin >> op;

        if(op == 1) {
            int u, x;
            cin >> u >> x;
            u--;
            // change node u to x
            // modify all the subtree of node u to x - vals[u]
            sgt.set(trans[u], trans[u] + subtreeSize[u], x - vals[u]);
            vals[u] = x;
        } else {
            int u;
            cin >> u;
            u--;
            // retrieve the pathSum of node u
            cout << sgt.retrieve(trans[u]) << '\n';
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}