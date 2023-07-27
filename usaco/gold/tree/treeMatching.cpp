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

vector<vector<int>> adj;
vector<ll> dp1, dp2;

void maxMatches(int v, int pv) {
    for(int child : adj[v]) {
        if(child == pv) continue;
        maxMatches(child, v);
        dp2[v] += max(dp1[child], dp2[child]);
    }

    for(int child : adj[v]) {
        if(child != pv) {
            dp1[v] = max(dp1[v], 1 + dp2[child] + dp2[v] - max(dp1[child], dp2[child]));
        }
    }
}

void solve(){
    int n;
    cin >> n;

    adj.resize(n + 1);
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dp1.resize(n + 1), dp2.resize(n + 1);
    maxMatches(1, 0);

    cout << max(dp1[1], dp2[1]);
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}