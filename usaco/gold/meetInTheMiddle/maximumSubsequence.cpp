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

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e15;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

vector<ll> a;
ll n, m;

void add(ll &a, ll &b) {
    a += b;
    if(a >= m) a -= m;
}

// subsets from l to r inclusive [l, r]
vll subset_from_l_to_r(int l, int r) {
    int len = r - l + 1;
    vll res;

    for(int i = 0; i < (1 << len); i++) {
        ll sum = 0;
        for(int j = 0; j < len; j++) {
            if((i & (1 << j)) > 0) add(sum, a[l + j]);
        }
        res.push_back(sum);
    }
    return res;
}

void solve(){
    cin >> n >> m;
    a = vll(n);
    rep(i, n) {
        cin >> a[i];
        a[i] %= m;
    }

    vll resLeft = subset_from_l_to_r(0, n / 2 - 1);
    vll resRight = subset_from_l_to_r(n / 2, n - 1);

    sort(all(resLeft));
    sort(all(resRight));
    
    ll ans = 0;
    for(ll left : resLeft) {
        auto it = lower_bound(all(resRight), m - left);
        --it;
        ans = max(ans, left + *it);
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