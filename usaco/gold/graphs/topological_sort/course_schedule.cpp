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

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e9;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

void solve(){
    int n, m;
    cin >> n >> m;

    vector<int> adj[n];
    vector<int> ingoing_edges(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        ingoing_edges[b]++;
    }

    vector<int> ans;
    queue<int> q;

    for(int i = 0; i < n; i++) {
        if(ingoing_edges[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for(int e : adj[node]) {
            ingoing_edges[e]--;
            if(ingoing_edges[e] == 0) {
                q.push(e);
            }
        }
    }

    if(ans.size() != n) {
        cout << "IMPOSSIBLE\n";
    } else {
        for(int x : ans) {
            cout << x + 1 << ' ';
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}