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
#include <numeric>

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
const ll DIM = 1e6 + 20;
const int INF = 1e9;
const ll LLINF = 1e15;
const ll LL_MAX = 9223372036854775807;
const int LOG = 22;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};

vector<pair<ll, ll>> a;

bool cmp(int p1, int p2) {
    if(a[p1].first == a[p2].first) return a[p1].second > a[p2].second;
    return a[p1].first < a[p2].first;
}

void solve(){
    int n, m; cin >> n >> m;
    vll c(m);
    a = vector<pair<ll, ll>>(n);

    rep(i, n) cin >> a[i].first;
    rep(i, n) cin >> a[i].second;
    rep(i, m) cin >> c[i];

    vi order(n);
    iota(all(order), 0);
    sort(all(order), cmp);
    vector<pair<ll, ll>> swords;

    for(int t = 0; t < n; t++) {
        int i = order[t];
        if(swords.empty() || (a[i].first - a[i].second) < swords.back().second) {
            swords.push_back({a[i].first, a[i].first - a[i].second});
        }
    }

    vector<ll> dp(DIM);
    int ptr = 0;
    for(int i = 1; i < DIM; i++) {
        while(ptr < swords.size() && swords[ptr].first <= i) ptr++;
        if(ptr > 0) dp[i] = dp[i - swords[ptr - 1].second] + 2;
    }

    ll ans = 0;
    for(int i = 0; i < m; i++) {
        if(c[i] >= DIM) {
            ll dif = c[i] - DIM;
            ll ops = dif / swords.back().second + 1;
            ans += 2 * ops;
            c[i] -= ops * swords.back().second;
        }

        ans += dp[c[i]];
    }

    cout << ans << "\n";
}

int main(){
    FELLE
    solve();
}