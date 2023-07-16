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
    int s, n;
    cin >> s >> n;

    vector<int> weights(n + 1);
    vector<vector<int>> dp(s + 1, vector<int>(n + 1));
    rep(i, n) {
        cin >> weights[i + 1];
    }

    dp[0][0] = 0;
    for(int j = 1; j < n + 1; j++) {
        for(int cap = 1; cap <= s; cap++) {
            int max1 = dp[cap][j - 1];
            int max2 = cap - weights[j] >= 0 ? dp[cap - weights[j]][j - 1] + weights[j] : 0;
            dp[cap][j] = max(max1, max2);
        }
    }

    cout << *max_element(all(dp[s]));
}

int main(){
    //freopen("pacefulsets.in", "r", stdin);
	//freopen("pacefulsets.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}

/*
10 3
1 4 8

20 4
5 7 12 18
*/
