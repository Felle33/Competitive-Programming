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

int n, k;
vector<pair<ll, ll>> intervals;

ll count(ll mid) {
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        if(intervals[i].first >= mid) continue;
        sum += min(mid - intervals[i].first, intervals[i].second - intervals[i].first + 1);
    }

    return sum;
}

void solve(){
    cin >> n >> k;
    intervals = vector<pair<ll, ll>>(n);

    ll mi = INF, ma = -INF;
    rep(i, n) {
        ll a, b;
        cin >> a >> b;
        intervals[i].first = a;
        intervals[i].second = b;
        mi = min(mi, a);
        ma = max(ma, b);
    }

    ll l = mi, r = ma + 1;
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