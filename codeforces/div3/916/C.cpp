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
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

void solve(){
    int n, k; cin >> n >> k;
    vll a(n), b(n), maxs(n);
    vll pref(n);

    rep(i, n) {
        cin >> a[i];
    }

    rep(i, n) {
        cin >> b[i];
    }

    pref[0] = a[0];
    maxs[0] = b[0];
    for(int i = 1; i < n; i++) {
        pref[i] = pref[i - 1] + a[i];
        maxs[i] = max({maxs[i - 1], b[i]});
    }

    ll ans = 0;
    for(int i = 0; i < n; i++) {
        if(k <= i) break;
        ll cur_ans = pref[i];
        cur_ans += (k - i - 1) * maxs[i];
        ans = max(ans, cur_ans);
    }

    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    int t;
    cin >> t;

    while(t--){
        solve();
    }
}