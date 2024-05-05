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
const int INF_INT = 1e9;
const ll LL_MAX = 9223372036854775807;
const int LOG = 22;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};

int n, d, m;
vi a;

// dp[i][j][k] = how many ways starting from i-th position we can sum up k numbers to get a result congruent to j mod D
int rec(int i, int j, int k, vector<vvi>& dp) {
    if(k < 0) return 0;
    if(i == n) return k == 0 && j == 0;
    
    if(dp[i][j][k] != -1) return dp[i][j][k];

    int sumNextNum = (j - a[i]) % d < 0 ? (j - a[i]) % d + d : (j - a[i]) % d;

    int ans = rec(i + 1, sumNextNum, k - 1, dp) + rec(i + 1, j, k, dp);
    dp[i][j][k] = ans;
    return dp[i][j][k];
}

void reset(vector<vvi>& dp) {
    rep(i, n) rep(j, 20) rep(k, 11) dp[i][j][k] = -1;
}

void solve(){
    int t = 0;
    int q;

    while(cin >> n >> q) {
        if(n == 0 && q == 0) return;

        a = vi(n);
        vector<vvi> dp(n, vvi(21, vi(11)));
        rep(i, n) cin >> a[i];

        cout << "SET " << ++t << ":\n";
        rep(i, q) {
            cin >> d >> m;
            reset(dp);
            cout << "QUERY " << i + 1 << ": " << rec(0, 0, m, dp) << "\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    //freopen("catch.in", "r", stdin);
	//freopen("catch.out", "w", stdout);
    solve();
}