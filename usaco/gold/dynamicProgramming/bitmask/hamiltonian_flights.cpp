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

    vector<vector<int>> adj_rev(n);
    rep(i, m) {
        int s, e;
        cin >> s >> e;
        s--, e--;
        adj_rev[e].push_back(s);
    }

    vector<vector<int>> dp(1 << n, vector<int>(n));
    dp[1][0] = 1;
    // iteration over all subsets
    for(int s = 2; s < (1 << n); s++) {
        // consider only the subset with the first city (because it is the departure city)
        if((s & 1) == 0) continue;
        // if the last bit is on (the last city is in the subset) also all the bit has to be on in order to 
        // calculate all the combination to arrive to the end
        // it has no sense to calculate the combinations to arrive to the last city but the trip does not visit all the cities
        if((s & (1 << (n - 1))) && s != ((1 << n) - 1)) continue;

        // iteration over all endings
        for(int end = 0; end < n; end++) {
            if((s & (1 << end)) == 0) continue;
            
            // subset without end
            int prev_sub = s - (1 << end);
            // iteration over the rev adj list
            for(int edge : adj_rev[end]) {
                // only if end is part of the subset
                if((s & (1 << edge))) {
                    dp[s][end] = (dp[s][end] + dp[prev_sub][edge]) % MOD;
                }
            }
        }
    }

    cout << dp[(1 << n) - 1][n - 1] << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}