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
    int n;
    ll m;
    cin >> n >> m;

    vector<pair<ll, ll>> a(n);
    rep(i, n) cin >> a[i].first;
    rep(i, n) cin >> a[i].second;

    sort(all(a));

    ll ans = 0;

    for(int i = 0; i < n; i++) {
        ll x = a[i].first * min(m / a[i].first, a[i].second);
        ans = max(ans, x);
    }

    for(int i = 0; i < n - 1; i++) {
        if(a[i].first + 1 != a[i + 1].first) continue;

        ll cur = m;
        ll cnt1 = min(cur / a[i].first, a[i].second);
        cur -= cnt1 * a[i].first;

        ll cnt2 = min(cur / a[i + 1].first, a[i + 1].second);
        cur -= cnt2 * a[i + 1].first;

        ll tot_flo = m - cur;
        ll swaps = min({cnt1, a[i + 1].second - cnt2, cur});
        tot_flo += swaps;

        ans = max(ans, tot_flo);
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