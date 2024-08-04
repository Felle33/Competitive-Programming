#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <map>
#include <set>
#include <iomanip>
#include <bitset>

#define all(x) (x).begin(), (x).end()
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))
#define FELLE ios_base::sync_with_stdio(false); cin.tie(NULL); std::cout.precision(10); cout << std::fixed;

using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<unsigned long long> vull;
typedef vector<vector<int>> vvi;
typedef long long ll;
typedef pair<int,int> pii;

const ll MOD1 = 1e9 + 7;
const ll MOD2 = 998244353;
const ll DIM = 1e6;
const int INF = 1e9;
const ll LLINF = 1e15;
const ll LL_MAX = 9223372036854775807;
const int LOG = 22;

void solve(){
    string s; cin >> s;
    int q; cin >> q;
    int n = s.size();

    vector<vll> dp(n, vll(n));
    vector<vector<bool>> pal(n, vector<bool>(n));

    for(int k = 0; k < n; k++) {
        for(int i = 0, j = k; j < n; i++, j++) {
            if(i == j) pal[i][j] = 1;
            else if(i + 1 == j) pal[i][j] = (s[i] == s[j]);
            else pal[i][j] = (s[i] == s[j] && pal[i + 1][j - 1]);
        }
    }

    for(int i = 0, j = 0; j < n; i++, j++) {
        dp[i][j] = 1;
    }

    for(int i = 0, j = 1; j < n; i++, j++) {
        dp[i][j] = 2 + (s[i] == s[j]);
    }

    for(int k = 2; k < n; k++) {
        for(int i = 0, j = k; j < n; i++, j++) {
            dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1] + (pal[i][j]);
        }
    }

    rep(_, q) {
        int l, r; cin >> l >> r;
        l--, r--;
        cout << dp[l][r] << "\n";
    }
}

int main(){
    FELLE
    solve();
}