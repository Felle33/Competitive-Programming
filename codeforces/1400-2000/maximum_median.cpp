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
int DI[] = {0, 1, -1, 0};
int DJ[] = {1, 0, 0, -1};

ll n, k;
vll a;

bool good(ll med) {
    ll ops = 0;
    for(int i = n - 1; i >= n / 2; i--) {
        ops += max(med - a[i], 0ll);
    }

    return ops <= k;
}

void solve(){
    cin >> n >> k;
    a = vll(n);
    rep(i, n) cin >> a[i];

    sort(all(a));

    ll l = 0, r = 3e9;
    while(l + 1 < r) {
        ll mid = l + (r - l) / 2;

        if(good(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << l << "\n";
}

int main(){
    FELLE
    solve();
}