#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>
#include <map>
#include <set>
#include <iomanip>

#define all(x) (x).begin(), (x).end()
#define mp make_pair
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))

using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<unsigned long long> vull;
typedef vector<vector<int>> vvi;
typedef long long ll;
typedef pair<int,int> pii;

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e15;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

int n, m;
vll a;

ll f(int i, ll y) {
    if(i == n) return INF;
    if(a[i] >= y) return 0;
    ll op = y - a[i] + f(i + 1, y - 1);
    return op;
}

bool good(ll mid) {
    vector<ll> minOp(n);
    for(int i = 0; i < n; i++) {
        minOp[i] = f(i, mid);
    }

    return *min_element(all(minOp)) <= m;
}

void solve(){
    cin >> n >> m;
    a.resize(n);
    rep(i, n) cin >> a[i];

    ll l = 0, r = 1e16;
    while(l + 1 < r) {
        ll mid = l + (r - l) / 2;
        if(good(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << l << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        solve();
    }
}