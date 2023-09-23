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

void topSort(int end, int n, vector<bitset<2001>>& dp, vector<int>& arcIn, vector<vector<int>>& adj, vector<vector<int>>& adj_rev) {
    queue<int> q;
    for(int i = 0; i < n; i++) {
        if(arcIn[i] == 0) {
            q.push(i);
            dp[i][0] = 1;
        }
    }

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for(int to : adj[node]) {
            arcIn[to]--;
            if(arcIn[to] == 0) {
                q.push(to);
                // calculate dp[to]
                for(int from : adj_rev[to]) {
                    dp[to] |= (dp[from] << 1);
                }
            }
        }
    }
}

void solve(){
    int n1, n2, m1, m2, q;
    cin >> n1 >> n2 >> m1 >> m2;

    vector<vector<int>> adj1(n1);
    vector<vector<int>> adj2(n2);
    vector<vector<int>> adj1_rev(n1);
    vector<vector<int>> adj2_rev(n2);
    vector<int> arcIn1(n1);
    vector<int> arcIn2(n2);

    rep(i, m1) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj1[a].push_back(b);
        arcIn1[b]++;
        adj1_rev[b].push_back(a);
    }

    rep(i, m2) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj2[a].push_back(b);
        arcIn2[b]++;
        adj2_rev[b].push_back(a);
    }

    vector<bitset<2001>> dp1(n1);
    vector<bitset<2001>> dp2(n2);

    topSort(n1 - 1, n1, dp1, arcIn1, adj1, adj1_rev);
    topSort(n2 - 1, n2, dp2, arcIn2, adj2, adj2_rev);

    bitset<4001> tmp, sumPath;

    for(int i = 0; i < 2001; i++) {
        tmp[i] = dp1[n1 - 1][i];
    }

    for(int i = 0; i < 2001; i++) {
        if(dp2[n2 - 1][i]) {
            sumPath |= (tmp << i);
        }
    }

    cin >> q;

    int sum;
    rep(i, q) {
        cin >> sum;

        if(sumPath[i]) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}