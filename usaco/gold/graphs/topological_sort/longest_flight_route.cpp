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

int n, m;
vector<int> ans; 

void compute(vector<vector<int>>& adj, vector<vector<int>>& back_edge, vector<int>& ingoing_edges, vector<int>& dp, vector<int>& parent) {
    queue<int> q;
    rep(i, n) {
        if(ingoing_edges[i] == 0) q.push(i);
    }

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for(int e : adj[node]) {
            ingoing_edges[e]--;
            if(ingoing_edges[e] == 0) q.push(e);
        }

        int mx = -999999999;
		int mx_node = -1;
		for (int prev : back_edge[node]) {
			if (dp[prev] >= mx) {
				mx = dp[prev] + 1;
				mx_node = prev;
			}
		}

		dp[node] = mx;
		if (node == 0) dp[node] = 1;
		parent[node] = mx_node;
    }
}

void solve(){
    cin >> n >> m;

    vector<vector<int>> adj(n);
    vector<vector<int>> back_edge(n);
    vector<int> ingoing_edges(n);
    vector<int> dp(n, -1);
    vector<int> parent(n, -1);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        ingoing_edges[b]++;
        adj[a].push_back(b);
        back_edge[b].push_back(a);
    }

    compute(adj, back_edge, ingoing_edges, dp, parent);

    bool contains_0 = false;
    int tmp = n - 1;
    vector<int> ans;

    while(tmp != -1) {
        ans.push_back(tmp);
        tmp = parent[tmp];
        if(tmp == 0){
            contains_0 = true;
            ans.push_back(tmp);
            break;
        } 
    }

    if(contains_0) {
        cout << ans.size() << '\n';
        for(int i = ans.size() - 1; i >= 0; i--) {
            cout << ans[i] + 1 << ' ';
        }
    } else {
        cout << "IMPOSSIBLE";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}