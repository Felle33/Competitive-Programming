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
const ll MAX_N = 1001;
const ll LOG = 15;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

vector<int> children[MAX_N];
int up[MAX_N][LOG];
int depth[MAX_N];

void dfs(int node, int parent) {
    for(int child : children[node]) {
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

int get_lca(int a, int b) {
    if(depth[a] < depth[b]) swap(a, b);
    int k = depth[a] - depth[b];

    for(int j = 0; j < LOG; j++) {
        if(k & (1 << j)) {
            a = up[a][j];
        }
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
