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

void solve(){
    int n, m, k, w; cin >> n >> m >> k >> w;
    vll gor(w);
    rep(i, w) cin >> gor[i];
    sort(gor.rbegin(), gor.rend());

    priority_queue<ll> pq;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int lb_i = max(0, i - k + 1);
            int upp_i = min(n - k, i);
            int lb_j = max(j - k + 1, 0);
            int upp_j = min(m - k, j);
            ll to_add = 1ll * (upp_i - lb_i + 1) * (upp_j - lb_j + 1);

            pq.push(to_add);
        }
    }

    ll ans = 0;
    int i = 0;
    while(w--) {
        ans += pq.top() * gor[i];
        pq.pop();
        i++;
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