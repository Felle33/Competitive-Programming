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
const int LETTERS = 26;

vll a, b;
int n, k;

pair<ll, ll> good(ll x) {
    ll tot_ops = 0;
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] < x) continue;
        ll dif = a[i] - x;
        ll cnt = dif / b[i] + 1;
        tot_ops += cnt;

        ans += a[i] * cnt - cnt * (cnt - 1) / 2 * b[i];
    }

    if(tot_ops > k) {
        ans -= (tot_ops - k) * x;
    }
    return {tot_ops, ans};
}

void solve(){
    cin >> n >> k;
    a = vll(n);
    b = vll(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];

    int r = *max_element(all(a)) + 1, l = 0;
    // l is the good pointer
    while(l + 1 < r) {
        int mid = l + (r - l) / 2;
        if(good(mid).first >= k) {
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << (good(l).second) << "\n";
}

int main(){
    FELLE
    int t; cin >> t;
    while(t--){
        solve();
    }
}