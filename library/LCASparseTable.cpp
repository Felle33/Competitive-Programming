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
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

int log2_floor(unsigned long long i) {
    return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

// LCA in O(1) and build in O(n * log(n))
struct LCASparseTable {
    static const int K = 25;
    vector<pair<ll, ll>> table[K];
    vector<ll> height, first, euler;
    int n;

    LCASparseTable(vector<vector<int>> &adj, int root = 0) {
        n = adj.size();
        height.resize(n);
        first.resize(n);
        dfs(adj, root, -1);
        int m = euler.size();
        build();
    }

    void dfs(vector<vector<int>> &adj, int node, int parent, int h = 0) {
        height[node] = h;
        first[node] = euler.size();
        euler.push_back(node);
        for (auto to : adj[node]) {
            if (to != parent) {
                dfs(adj, to, node, h + 1);
                euler.push_back(node);
            }
        }
    }

    void build() {
        int m = euler.size();
        for(int i = 0; i < K; i++) table[i].resize(m);
        for(int i = 0; i < m; i++) {
            table[0][i] = mp(height[euler[i]], euler[i]);
        }

        for(int i = 1; i < K; i++) {
            for(int j = 0; j + (1 << i) <= m; j++) {
                if(table[i - 1][j].first < table[i - 1][j + (1 << (i - 1))].first) {
                    table[i][j] = table[i - 1][j];
                } else {
                    table[i][j] = table[i - 1][j + (1 << (i - 1))];
                }
            }
        }
    }

    int lca(int u, int v) {
        int left = first[u], right = first[v];
        if (left > right)
            swap(left, right);
        int ln2 = log2_floor(right - left + 1);
        if(table[ln2][left].first < table[ln2][right - (1 << ln2) + 1].first) return table[ln2][left].second;
        return table[ln2][right - (1 << ln2) + 1].second;
    }
};