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

    vector<vector<int>> dp(n, vector<int>(m));
    dp[n - 1][m - 1] = 1;
    for(int i = n - 2; i >= 0; i--) {
        for(int j = m - 2; j >= 0; j--) {
            dp[i][j] = ((i + 1 < n && j + 2 < m) ? dp[i + 1][j + 2] : 0) +
            ((i + 2 < n && j + 1 < m) ? dp[i + 2][j + 1] : 0);
        }
    }

    cout << dp[0][0];
}

int main(){
    freopen("knight.in", "r", stdin);
	freopen("knight.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}