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
#define mp make_pair
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))

using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<unsigned long long> vull;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long>> vvll;
typedef long long ll;
typedef pair<int,int> pii;

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 8e18;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

void add(int &a, int b) {
    a += b;
    if(a >= MOD) a-= MOD;
}

void solve(){
    int n; cin >> n;
    vvi dp(n + 1, vi(5002, 0));
    vector<char> states(n);
    rep(i, n) cin >> states[i];

    dp[0][0] = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= 5001; j++) {
            if(dp[i][j] == 0) continue;

            if(states[i] == 'f') {
                add(dp[i + 1][j + 1], dp[i][j]);
            } else {
                add(dp[i + 1][j], dp[i][j]);
            }

            if(j > 0 && i > 0 && states[i - 1] != 'f') {
                if(states[i] == 'f') {
                    add(dp[i + 1][j], dp[i][j]);
                } else {
                    add(dp[i + 1][j - 1], dp[i][j]);
                }
            }
        }
    }

    int ans = 0;
    for(int j = 0; j <= 5001; j++) add(ans, dp[n][j]);
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}