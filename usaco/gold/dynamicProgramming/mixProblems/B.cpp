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
typedef vector<vector<long long>> vvll;
typedef long long ll;
typedef pair<int,int> pii;

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 8e18;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

struct SegmentTree {
    int size;
    vector<ll> minimum;
    vector<ll> maximum;

    ll NEUTRAL_ELEMENT_MAX = -INF;
    ll NEUTRAL_ELEMENT_MIN = INF;

    SegmentTree(int n) {
        size = 1;
        while(size < n) size *= 2;
        minimum.resize(2 * size, NEUTRAL_ELEMENT_MIN);
        maximum.resize(2 * size, NEUTRAL_ELEMENT_MAX);
    }

    void build(vector<ll>& numbers){
        build(numbers, 0, 0, size);
    }

    void build(vector<ll>& numbers, int x, int lx, int rx) {
        if(rx - lx == 1) {
            if(lx < (int) numbers.size()) {
                minimum[x] = numbers[lx];
                maximum[x] = numbers[lx];
            }
            return;
        }

        int mid = (lx + rx) / 2;
        build(numbers, 2 * x + 1, lx, mid);
        build(numbers, 2 * x + 2, mid, rx);
        minimum[x] = min(minimum[2 * x + 1], minimum[2 * x + 2]);
        maximum[x] = max(maximum[2 * x + 1], maximum[2 * x + 2]);
    }

    // l_query = da dove inizia la query
    // r_query = dove finisce la query non compresa
    // x = nodo
    // lx = dove inizia la zona di competenza del nodo
    // rx = dove finisce la zona di competenza del nodo non compreso
    ll maxi(int l_query, int r_query, int x, int lx, int rx) {
        if(l_query >= rx || r_query <= lx) return NEUTRAL_ELEMENT_MAX;
        if(l_query <= lx && rx <= r_query) return maximum[x];
        int mid = (lx + rx) / 2;
        ll s1 = maxi(l_query, r_query, 2 * x + 1, lx, mid);
        ll s2 = maxi(l_query, r_query, 2 * x + 2, mid, rx);
        return max(s1, s2);
    }

    ll maxi(int l, int r) {
        return maxi(l, r, 0, 0, size);
    }

    // l_query = da dove inizia la query
    // r_query = dove finisce la query non compresa
    // x = nodo
    // lx = dove inizia la zona di competenza del nodo
    // rx = dove finisce la zona di competenza del nodo non compreso
    ll mini(int l_query, int r_query, int x, int lx, int rx) {
        if(l_query >= rx || r_query <= lx) return NEUTRAL_ELEMENT_MIN;
        if(l_query <= lx && rx <= r_query) return minimum[x];
        int mid = (lx + rx) / 2;
        ll s1 = mini(l_query, r_query, 2 * x + 1, lx, mid);
        ll s2 = mini(l_query, r_query, 2 * x + 2, mid, rx);
        return min(s1, s2);
    }

    ll mini(int l, int r) {
        return mini(l, r, 0, 0, size);
    }
};

void solve(){
    int n; cin >> n;
    ll p, q, r; cin >> p >> q >> r;
    vll nums(n);
    rep(i, n) cin >> nums[i];

    SegmentTree seg(n);
    seg.build(nums);

    ll ans = -INF;
    for(int i = 0; i < n; i++) {
        ll cur = q * nums[i];
        cur += (p > 0 ? seg.maxi(0, i + 1) * p : seg.mini(0, i + 1) * p);
        cur += (r > 0 ? seg.maxi(i, n) * r : seg.mini(i, n) * r);
        ans = max(ans, cur);
    }

    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}