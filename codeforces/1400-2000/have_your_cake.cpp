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
const ll MOD3 = 99999999999999997;
const ll DIM = 1e6;
const int INF = 1e9;
const ll LLINF = 1e15;
const ll LL_MAX = 9223372036854775807;
const int LOG = 22;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};

void solve(){
    int n; cin >> n;
    vll a(n), b(n), c(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    rep(i, n) cin >> c[i];

    ll tot = 2;
    for(int i = 0; i < n; i++) tot += a[i];
    ll as = 0, bs = 0, cs = 0;
    bool first = 1;
    int la, ra, lb, rb, lc, rc;
    la = lb = lc = ra = rb = rc = -1;

    for(int i = 0; i < n; i++) {
        as += a[i];
        bs += b[i];
        cs += c[i];

        // control if one exceeded (tot + 2) / 3
        if(as >= tot / 3 || bs >= tot / 3 || cs >= tot / 3) {
            ll mnn = INF;
            if(as >= tot / 3) mnn = min(mnn, as);
            if(bs >= tot / 3) mnn = min(mnn, bs);
            if(cs >= tot / 3) mnn = min(mnn, cs);
            
            if(mnn == as) {
                if(first) {
                    first = 0;
                    la = 0;
                } else {
                    la = max(rb, rc) + 1;
                }
                ra = i;
                as = -INF;
                bs = min(bs, 0ll);
                cs = min(cs, 0ll);
            } else if(mnn == bs) {
                if(first) {
                    first = 0;
                    lb = 0;
                } else {
                    lb = max(ra, rc) + 1;
                }
                rb = i;
                bs = -INF;
                as = min(as, 0ll);
                cs = min(cs, 0ll);
            } else {
                if(first) {
                    first = 0;
                    lc = 0;
                } else {
                    lc = max(ra, rb) + 1;
                }
                rc = i;
                cs = -INF;
                as = min(as, 0ll);
                bs = min(bs, 0ll);
            }
        }
    }

    if(la != -1 && lb != -1 && lc != -1) {
        cout << la + 1 << " " << ra + 1 << " " << lb + 1 << " " << rb + 1 << " " << lc + 1 << " " << rc + 1 << "\n";
    } else {
        cout << -1 << "\n";
    }
}

int main(){
    FELLE
    int t; cin >> t;
    while(t--){
        solve();
    }
}