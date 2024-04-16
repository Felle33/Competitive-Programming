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
const ll INF = 1e15;
const int INF_INT = 1e9;
const ll LL_MAX = 9223372036854775807;
const int LOG = 22;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

void solve(){
    int n; cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];

    vi pref(n), suf(n);
    pref[0] = a[0];
    for(int i = 1; i < n; i++) {
        pref[i] = __gcd(pref[i - 1], a[i]);
    }

    suf[n - 1] = a[n - 1];
    for(int i = n - 2; i >= 0; i--) {
        suf[i] = __gcd(suf[i + 1], a[i]);
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        int res = __gcd((i == 0 ? suf[i + 1] : pref[i - 1]), (i == n - 1 ? pref[i - 1] : suf[i + 1]));
        ans = max(ans, res);
    }

    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    solve();
}