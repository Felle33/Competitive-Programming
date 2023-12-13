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

struct interval {
    ll length;
    int left, right;
};

bool cmp(interval& i1, interval& i2) {
    if(i1.length == i2.length) return i1.left < i2.left;
    return i1.length < i2.length;
}

void solve(){
    int k, n; cin >> k >> n;
    vector<int> times(n);

    rep(i, n) {
        cin >> times[i];
    }

    sort(all(times));

    vector<interval> intervals;
    for(int i = 1; i < n; i++) {
        intervals.pb({times[i] - times[i - 1], times[i - 1], times[i]});
    }

    sort(all(intervals), cmp);

    set<int> left_int, right_int;

    ll ans = 0;
    int to_add = k;
    for(int i = 0; to_add > 0; i++) {
        interval& interv = intervals[i];

        if(left_int.count(interv.right) == 0 && right_int.count(interv.left) == 0) {
            ans += interv.length;
            left_int.insert(interv.left);
            right_int.insert(interv.right);
            to_add--;
        }
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