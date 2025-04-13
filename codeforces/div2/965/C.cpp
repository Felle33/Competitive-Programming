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
vector<int> DI = {0, 1, -1, 0};
vector<int> DJ = {1, 0, 0, -1};

ll n, k;

bool good(ll med, vector<pair<ll, ll>>& a) {
    int less = 0;
    ll ops = 0;
    for(int i = 0; i < n; i++) {
        if(a[i].first < med) less++;
    }

    int toBeGreater = n - (n - 1) / 2;
    for(int i = n - 1; i >= 0 && toBeGreater > 0; i--) {
        if(a[i].first >= med) toBeGreater--;
        else if(a[i].second) {
            ops += med - a[i].first;
            toBeGreater--;
        }
    }

    return ops <= k && toBeGreater == 0;
}

void solve(){
    cin >> n >> k;
    vector<pair<ll, ll>> a(n);
    rep(i, n) cin >> a[i].first;
    rep(i, n) cin >> a[i].second;

    sort(all(a));
    ll ans = 0;

    for(int i = n - 1; i >= 0; i--) {
        if(a[i].second) {
            int idxMed = (n - 2) / 2;
            if(idxMed >= i) idxMed++;
            ans = a[i].first + k + a[idxMed].first;
            break;
        }
    }

    if(a[n - 1].second == 0) {
        ll last = a[n - 1].first;
        a.pop_back();
        n--;

        ll lo = 0, hi = 1e10;

        while(lo + 1 < hi) {
            ll mid = lo + (hi - lo) / 2;
            if(good(mid, a)) {
                lo = mid;
            } else {
                hi = mid;
            }
        }

        ans = max(ans, last + lo);
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