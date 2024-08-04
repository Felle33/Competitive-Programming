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
const ll MOD3 = 99999999999999997;
const ll DIM = 1e6;
const int INF = 1e9;
const ll LLINF = 1e15;
const ll LL_MAX = 9223372036854775807;
const int LOG = 22;

// NOT SOLVED
void solve(){
    int n, x; cin >> n >> x;

    vll pref(n);
    vll dp(n);
    ll sum = 0;
    rep(i, n) {
        ll a; cin >> a;
        sum += a;
        pref[i] = sum;
    }

    ll zeroes = 1;
    ll ans = 0;
    for(int i = n - 1; i >= 0; i--) {
        int l = i, r = n;
        while(l + 1 < r) {
            int mid = l + (r - l) / 2;
            ll int_sum = pref[mid] - (l == 0 ? 0 : pref[l - 1]);
            if(int_sum > x) {
                r = mid;
            } else {
                l = mid;
            }
        }

        dp[i] = dp[]
        ans += zeroes * (r - l);
        zeroes++;
        i = r;
    }

    cout << ans << "\n";
}

int main(){
    FELLE
    int t; cin >> t;
    while(t--){
        solve();
    }
}