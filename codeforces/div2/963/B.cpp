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

int n;

bool allEven(vll& a) {
    rep(i, n) {
        if(a[i] % 2 == 1) return 0;
    }
    return 1;
}

bool allOdds(vll& a) {
    rep(i, n) {
        if(a[i] % 2 == 0) return 0;
    }
    return 1;
}

void solve(){
    cin >> n;
    vll a(n);
    rep(i, n) cin >> a[i];

    if(allEven(a) || allOdds(a)) {
        cout << 0 << "\n";
        return;
    }

    sort(all(a));

    ll mx_odd = -1, mx_even = 0;
    int ans = 0;

    rep(i, n) {
        if(a[i] % 2 == 1) {
            mx_odd = max(mx_odd, a[i]);
        } else {
            mx_even = max(mx_even, a[i]);
        }
    }

    for(int i = 0; i < n; ) {
        if(a[i] % 2 == 0) {
            if(a[i] < mx_odd) {
                ans++;
                a[i] += mx_odd;
                mx_odd = a[i];
                i++;
            } else {
                ans++;
                mx_odd = mx_even + mx_odd;
            }
        } else {
            i++;
        }
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