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
    int n;
    cin >> n;
    if(n == 0) {
        cout << 1 << '\n';
        return;
    }

    vector<vector<int>> dp(n + 1, vector<int>(3));
    dp[1][0] = 1;
    dp[1][1] = 1;
    dp[1][2] = 1;

    for(int l = 2; l <= n; l++) {
        dp[l][0] = dp[l - 1][0] + dp[l - 1][1] + dp[l - 1][2];
        dp[l][1] = dp[l - 1][1] + dp[l - 1][2];
        dp[l][2] = dp[l - 1][0] + dp[l - 1][1] + dp[l - 1][2];
    }

    cout << dp[n][0] + dp[n][1] + dp[n][2] << '\n';
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
