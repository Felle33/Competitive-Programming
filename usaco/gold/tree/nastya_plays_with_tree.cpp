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
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))
#define RED 0
#define GREEN 1
#define BLUE 2

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
vector<int> reserveNodes;
int moves;
vector<vector<int>> ans;

bool leaf(int u, int p) {
    return adj[u].size() == 1 && adj[u][0] == p;
}

void dfs(int u, int p, bool root) {
    if(leaf(u, p)) {
        reserveNodes[u] = u;
        return;
    }

    int sz = adj[u].size();
    if(sz > 2) moves += sz - 2;
    for(int to : adj[u]) {
        if(to != p) dfs(to, u, 0);
    }

    if(!root) {
        int reserveNode = -1;
        for(int i = 0; i < sz; i++) {
            int to = adj[u][i];
            if(to == p) continue;
            if(reserveNode == -1) {
                reserveNode = reserveNodes[to];
            } else {
                ans.push_back({u, to, to, reserveNode});
                reserveNode = reserveNodes[to];
            }
        }
        reserveNodes[u] = reserveNode;
    }
    
}

void solve(){
    int n;
    cin >> n;

    adj = vector<vector<int>>(n + 1);
    reserveNodes = vector<int>(n + 1);
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0, 1);

    cout << moves << "\n";
    for(vector<int>& v : ans) {
        cout << v[0] << " " << v[1] << " " << v[2] << " " << v[3] << "\n";
    }
    ans.erase(all(ans));
    moves = 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}