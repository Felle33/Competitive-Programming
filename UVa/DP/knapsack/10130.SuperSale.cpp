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

int n;

int rec(int i, int wleft, vector<pii>& a, vvi& dp) {
    if(i == n) return 0;
    if(dp[i][wleft] != -1) return dp[i][wleft];

    int ans = rec(i + 1, wleft, a, dp);
    if(wleft >= a[i].second) ans = max(ans, a[i].first + rec(i + 1, wleft - a[i].second, a, dp));
    dp[i][wleft] = ans;

    return ans;
}

void solve(){
    cin >> n;
    vector<pii> a(n);
    rep(i, n) cin >> a[i].first >> a[i].second;

    int g; cin >> g;
    vi people(g);
    rep(i, g) cin >> people[i];

    // dp[i][j] = max value if I am at the current i-th object and i have j weight left
    vector<vector<int>> dp(n + 1, vector<int>(31));

    int ans = 0;
    rep(i, g) ans += rec(0, people[i], a, dp);
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    //freopen("catch.in", "r", stdin);
	//freopen("catch.out", "w", stdout);
    int t; cin >> t;
    while(t--) solve();
}