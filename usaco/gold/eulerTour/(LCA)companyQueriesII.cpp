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
// nodes visited in the eulerian tour
vector<ll> nodes;
// depth of the i-th node in nodes
vector<ll> depths;
// first visit of all nodes
vector<ll> first;

struct SegmentTree {
    int size;
    // pair in which first is the min depth and second is  the index
    vector<pair<ll, int>> tree;

    SegmentTree(int n) {
        size = 1;
        while(size < n) size *= 2;
        tree.resize(2 * size, make_pair(INF, -1));
    }

    void build(vector<ll>& numbers){
        build(numbers, 0, 0, size);
    }

    void build(vector<ll>& numbers, int x, int lx, int rx) {
        if(rx - lx == 1) {
            if(lx < (int) numbers.size()) {
                tree[x] = {numbers[lx], nodes[lx]};
            }
            return;
        }

        int mid = (lx + rx) / 2;
        build(numbers, 2 * x + 1, lx, mid);
        build(numbers, 2 * x + 2, mid, rx);
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

void dfs(int node, int parent, int depth) {
    nodes.push_back(node);
    depths.push_back(depth);
    first[node] = nodes.size() - 1;

    for(int son : adj[node]) {
        if(son != parent) {
            dfs(son, node, depth + 1);
            nodes.push_back(node);
            depths.push_back(depth);
        }
    }
}

void solve(){
    int n, q;
    cin >> n >> q;

    adj.resize(n);
    first.resize(n);
    rep(i, n - 1) {
        int a;
        cin >> a;
        a--;
        adj[i + 1].push_back(a);
        adj[a].push_back(i + 1);
    }

    dfs(0, -1, 0);

    SegmentTree sgt(depths.size());
    sgt.build(depths);
    rep(i, q) {
        int a, b;
        cin >> a >> b;
        a--, b--;

        cout << sgt.LCA(a, b).second + 1 << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}