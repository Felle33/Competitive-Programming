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
#define mp make_pair
#define pb push_back
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
const ll MOD3 = 99999999999999997;
const ll DIM = 1e6;
const int INF = 1e9;
const ll LLINF = 1e15;
const ll LL_MAX = 9223372036854775807;
const int LOG = 22;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};

void solve(){
    int n; cin >> n;

    vvi a(n, vi(n));
    rep(i, n) {
        rep(j, n) {
            cin >> a[i][j];
        }
    }

    vvi dp(n + 1, vi(1 << n));
    dp[0][0] = 1;

    for(int i = 1; i <= n; i++) {
        for(int mask = 1; mask < (1 << n); mask++) {
            if(__builtin_popcount(mask) != i) continue;
            for(int j = 0; j < n; j++) {
                if((mask & (1 << j)) == 0) continue;
                if(a[i - 1][j]) {
                    dp[i][mask] = (dp[i][mask] + dp[i - 1][mask ^ (1 << j)]) % MOD1;
                }
            }
        }
    }
    
    cout << dp[n][(1 << n) - 1] << "\n";
}

int main(){
    FELLE
    solve();
}