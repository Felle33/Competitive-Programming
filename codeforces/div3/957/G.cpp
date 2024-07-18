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

int NCR[5005][5005];

void calc_ncr() {
    NCR[0][0] = 1;
    for(int n = 1; n <= 5004; n++) {
        NCR[n][0] = NCR[n][n] = 1;
        for(int k = 1; k < n; k++) {
            NCR[n][k] = NCR[n - 1][k - 1] + NCR[n - 1][k];
            if(NCR[n][k] >= MOD1) NCR[n][k] -= MOD1;
        }
    }
}

void solve(){
    int n; cin >> n;
    ll ans = 0;

    for(int m = 0; m <= n; m++) {
        for(int k = 1; k <= 2 * n + 5; k++) {
            int f1 = min(k - 1, n);
            int f2 = max(n - k, 0);
            int d1 = k - m - 1;
            int d2 = m - d1;

            if(d1 < 0 || d2 < 0) continue;
            if(f1 < d1 || f2 < d2) continue;

            ans += 1ll * k * NCR[f1][d1] % MOD1 * NCR[f2][d2] % MOD1;
            if(ans >= MOD1) ans -= MOD1;
        }
    }

    cout << ans << "\n";
}

int main(){
    FELLE
    calc_ncr();
    int t; cin >> t;
    while(t--){
        solve();
    }
}