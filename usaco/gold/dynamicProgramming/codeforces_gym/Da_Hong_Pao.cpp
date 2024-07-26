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

ll n;
int a[5001];
ll dp[5001][5001];

void solve(){
    cin >> n;
    rep(i, n) cin >> a[i];
    memset(dp, -1, sizeof(dp));

    for(int i = 0; i < n; i++) dp[i][i] = a[i] * n;

    for(ll sz = 2; sz <= n; sz++) {
        for(int i = 0, j = sz - 1; j < n; i++, j++) {
            dp[i][j] = max(dp[i + 1][j] + 1ll * (n - sz + 1) * a[i], dp[i][j - 1] + 1ll * (n - sz + 1) * a[j]);
        }
    }

    cout << dp[0][n - 1];
}

int main(){
    FELLE
    solve();
}