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
int n;

int max_skii(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
    if (i == n - 1) return grid[i][j];

    if(dp[i + 1][j] == -1) {
        dp[i + 1][j] = max_skii(i + 1, j, grid, dp);
    }

    if(dp[i + 1][j + 1] == -1) {
        dp[i + 1][j + 1] = max_skii(i + 1, j + 1, grid, dp);
    }

    dp[i][j] = grid[i][j] + max(dp[i + 1][j], dp[i + 1][j + 1]);
    
    return dp[i][j];
}

void solve(){
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));
    vector<vector<int>> dp(n, vector<int>(n, -1));
    rep(i, n) {
        for(int j = 0; j <= i; j++) {
            cin >> grid[i][j];
        }
    }

    for(int i = 0; i < n; i++) dp[n - 1][i] = grid[n - 1][i];
    cout << max_skii(0, 0, grid, dp);
}

int main(){
    //freopen("slalom.in", "r", stdin);
	//freopen("slalom.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}

/*
4
1
4 3
5 6 7
8 9 0 9
*/
