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
    int n = 8;

    vector<vector<int>> grid(n, vector<int>(n));
    vector<vector<int>> dp(n, vector<int>(n));
    rep(i, n) {
        rep(j, n) {
            cin >> grid[i][j];
        }
    }

    for(int i = n - 2; i >= 0; i--){
        dp[0][i] = dp[0][i + 1] + grid[0][i + 1];
    }

    for(int i = 1; i < n; i++){
        dp[i][n - 1] = dp[i - 1][n - 1] + grid[i - 1][n - 1];
    }

    for(int i = 1; i < n; i++) {
        for(int j = n - 2; j >= 0; j--) {
            dp[i][j] = min({dp[i - 1][j] + grid[i - 1][j],
            dp[i][j + 1] + grid[i][j + 1],
            dp[i - 1][j + 1] + grid[i - 1][j + 1]});
        }
    }

    cout << dp[n - 1][0];
}

int main(){
    //freopen("king2.in", "r", stdin);
	//freopen("king2.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}

/*
9 9 9 9 9 9 1 9
9 9 9 9 9 1 9 2
9 9 9 9 9 9 1 9
9 9 9 9 9 9 9 9
9 9 9 9 9 9 9 9
9 9 9 9 9 9 9 9
9 9 9 9 9 9 9 9
0 9 9 9 9 9 9 9

*/