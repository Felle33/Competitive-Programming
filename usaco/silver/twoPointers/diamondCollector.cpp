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

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e15;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

struct Interval {
    int l, r;

    bool operator<(const Interval& i) {
        return (r - l) < (i.r - i.l);
    }
};

void solve(){
    int n, k; cin >> n >> k;

    vi a(n);
    rep(i, n) cin >> a[i];

    sort(all(a));
    vector<Interval> intervals;
    for(int l = 0, r = 0; r < n; ) {
        while(r < n && a[r] - a[l] <= k) {
            r++;
        }

        intervals.push_back({l, r});
        while(l < r && a[r] - a[l] > k) {
            l++;
        }
    }

    sort(all(intervals));
    int m = intervals.size();
    Interval in1 = intervals[m - 1], in2 = {-1, -1};
    for(int i = m - 2; i >= 0; i--) {
        Interval pr = intervals[i];
        if(pr.r <= in1.l || pr.l >= in1.r) {
            in2 = pr;
            break;
        }
    }

    if(in2.l == -1 && in2.r == -1) {
        cout << (in1.r - in1.l);
    } else {
        cout << (in1.r - in1.l + in2.r - in2.l);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    freopen("diamond.in", "r", stdin);
	freopen("diamond.out", "w", stdout);

    solve();
}