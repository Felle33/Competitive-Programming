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
const ll INF = 1e17;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

struct SegmentTree {
    int size;
    vector<ll> maxPref, sumSubsegment;

    ll NEUTRAL_ELEMENT = 0;
    ll NOP = INF;

    SegmentTree(int n) {
        size = 1;
        while(size < n) size *= 2;
        maxPref.resize(2 * size, NEUTRAL_ELEMENT);
        sumSubsegment.resize(2 * size, NEUTRAL_ELEMENT);
    }

    void build(vector<ll>& numbers){
        build(numbers, 0, 0, size);
    }

    void build(vector<ll>& numbers, int x, int lx, int rx) {
        if(rx - lx == 1) {
            if(lx < (int) numbers.size()) {
                sumSubsegment[x] = numbers[lx];
                maxPref[x] = (sumSubsegment[x] < 0 ? 0 : sumSubsegment[x]);
            }
            return;
        }

        int mid = (lx + rx) / 2;
        build(numbers, 2 * x + 1, lx, mid);
        build(numbers, 2 * x + 2, mid, rx);
        sumSubsegment[x] = sumSubsegment[2 * x + 1] + sumSubsegment[2 * x + 2];
        maxPref[x] = max(maxPref[2 * x + 1], sumSubsegment[2 * x + 1] + maxPref[2 * x + 2]);
    }

    void set(int i, ll v, int x, int lx, int rx) {
        if(rx - lx == 1){
            sumSubsegment[x] = v;
            maxPref[x] = (sumSubsegment[x] < 0 ? 0 : sumSubsegment[x]);
            return;
        }

        int m = (lx + rx) / 2;
        if(i < m) {
            set(i, v, 2 * x + 1, lx, m);
        } else {
            set(i, v, 2 * x + 2, m, rx);
        }
        
        sumSubsegment[x] = sumSubsegment[2 * x + 1] + sumSubsegment[2 * x + 2];
        maxPref[x] = max(maxPref[2 * x + 1], sumSubsegment[2 * x + 1] + maxPref[2 * x + 2]);
    }

    void set(int i, ll v) {
        set(i, v, 0, 0, size);
    }

    pair<ll, ll> pref(int l_query, int r_query, int x, int lx, int rx) {
        if(l_query >= rx || r_query <= lx) return mp(NEUTRAL_ELEMENT, NEUTRAL_ELEMENT);
        if(l_query <= lx && rx <= r_query) return mp(maxPref[x], sumSubsegment[x]);
        int mid = (lx + rx) / 2;
        pair<ll, ll> s1 = pref(l_query, r_query, 2 * x + 1, lx, mid);
        pair<ll, ll> s2 = pref(l_query, r_query, 2 * x + 2, mid, rx);
        return mp(max(s1.first, s1.second + s2.first), s1.second + s2.second);
    }

    ll pref(int l, int r) {
        return pref(l, r, 0, 0, size).first;
    }
};

void solve(){
    int n, q; cin >> n >> q;
    vll a(n);
    rep(i, n) cin >> a[i];
    SegmentTree sgt(n);
    sgt.build(a);
    while(q--) {
        int c; cin >> c;
        if(c == 1) {
            ll i, v; cin >> i >> v;
            i--;
            sgt.set(i, v);
        } else {
            ll l, r; cin >> l >> r;
            l--;
            cout << sgt.pref(l, r) << '\n';
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    solve();
}