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

ll n, k;
vector<pair<ll, ll>> intervals;
vll a, b;

ll count(ll mid) {
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        if(mid <= intervals[i].first) continue;
        if(mid > intervals[i].second) sum += n;
        else {
            auto it = lower_bound(a.begin(), a.end(), mid - b[i]);
            int index = it - a.begin();
            sum += index;
        }
    }

    return sum;
}

void solve(){
    cin >> n >> k;
    a = vll(n), b = vll(n);

    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];

    sort(all(a));
    sort(all(b));

    intervals = vector<pair<ll, ll>>(n);
    for(int i = 0; i < n; i++) {
        intervals[i].first = b[i] + a[0];
        intervals[i].second = b[i] + a[n - 1];
    }

    ll l = a[0] + b[0], r = a[n - 1] + b[n - 1] + 1;
    k--;
    while(l + 1 < r) {
        ll mid = l + (r - l) / 2;

        if(count(mid) <= k) {
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
    std::cout.precision(10);
    cout << std::fixed;

    solve();
}