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
    vector<ll> sum, mini, op;

    ll NEUTRAL_ELEMENT_SUM = 0;
    ll NEUTRAL_ELEMENT_MIN = INF;
    ll NOP = INF;

    SegmentTree(int n) {
        size = 1;
        while(size < n) size *= 2;
        sum.resize(2 * size, NEUTRAL_ELEMENT_SUM);
        mini.resize(2 * size, 0LL);
        op.resize(2 * size, NOP);
    }

    void build(vector<ll>& numbers){
        build(numbers, 0, 0, size);
    }

    void build(vector<ll>& numbers, int x, int lx, int rx) {
        if(rx - lx == 1) {
            if(lx < (int) numbers.size()) {
                sum[x] = numbers[lx];
                mini[x] = numbers[lx];
            }
            return;
        }

        int mid = (lx + rx) / 2;
        build(numbers, 2 * x + 1, lx, mid);
        build(numbers, 2 * x + 2, mid, rx);
        sum[x] = sum[2 * x + 1] + sum[2 * x + 2];
        mini[x] = min(mini[2 * x + 1], mini[2 * x + 2]);
    }

    void propagate(int x, int lx, int rx) {
        if(rx - lx == 1 || op[x] == NOP) return;
        int mid = (rx + lx) / 2;
        sum[2 * x + 1] += op[x] * (mid - lx);
        sum[2 * x + 2] += op[x] * (rx - mid);
        mini[2 * x + 1] += op[x];
        mini[2 * x + 2] += op[x];
        op[2 * x + 1] = (op[2 * x + 1] == NOP ? op[x] : op[2 * x + 1] + op[x]);
        op[2 * x + 2] = (op[2 * x + 2] == NOP ? op[x] : op[2 * x + 2] + op[x]);
        op[x] = NOP;
    }

    void add(int l_query, int r_query, ll v, int x, int lx, int rx) {
        propagate(x, lx, rx);
        if(l_query >= rx || r_query <= lx) return;
        if(l_query <= lx && rx <= r_query) {
            sum[x] += (rx - lx) * v;
            mini[x] += v;
            op[x] = (op[x] == NOP ? v : op[x] + v);
            return;
        }

        int m = (lx + rx) / 2;
        add(l_query, r_query, v, 2 * x + 1, lx, m);
        add(l_query, r_query, v, 2 * x + 2, m, rx);
        
        sum[x] = sum[2 * x + 1] + sum[2 * x + 2];
        mini[x] = min(mini[2 * x + 1], mini[2 * x + 2]);
    }

    void add(int l, int r, ll v) {
        add(l, r, v, 0, 0, size);
    }

    ll sumQuery(int l_query, int r_query, int x, int lx, int rx) {
        propagate(x, lx, rx);
        if(l_query >= rx || r_query <= lx) return NEUTRAL_ELEMENT_SUM;
        if(l_query <= lx && rx <= r_query) return sum[x];
        int mid = (lx + rx) / 2;
        ll s1 = sumQuery(l_query, r_query, 2 * x + 1, lx, mid);
        ll s2 = sumQuery(l_query, r_query, 2 * x + 2, mid, rx);
        return s1 + s2;
    }

    ll sumQuery(int l, int r) {
        return sumQuery(l, r, 0, 0, size);
    }

    ll minimumQuery(int l_query, int r_query, int x, int lx, int rx) {
        propagate(x, lx, rx);
        if(l_query >= rx || r_query <= lx) return NEUTRAL_ELEMENT_MIN;
        if(l_query <= lx && rx <= r_query) return mini[x];
        int mid = (lx + rx) / 2;
        ll s1 = minimumQuery(l_query, r_query, 2 * x + 1, lx, mid);
        ll s2 = minimumQuery(l_query, r_query, 2 * x + 2, mid, rx);
        return min(s1, s2);
    }

    ll minimumQuery(int l, int r) {
        return minimumQuery(l, r, 0, 0, size);
    }
};

void solve(){
    int n, q; cin >> n >> q;
    vll a(n);
    rep(i, n) cin >> a[i];
    SegmentTree sgt(n);
    sgt.build(a);

    vector<vector<ll>> queries;
    int print = 0;

    while(q--) {
        char c; cin >> c;
        if(c == 'M') {
            ll l, r; cin >> l >> r;
            l--;
            queries.push_back({c, l, r});
            print++;
        } else if(c == 'P'){
            ll l, r, v; cin >> l >> r >> v;
            l--;
            queries.push_back({c, l, r, v});
        } else {
            ll l, r; cin >> l >> r;
            l--;
            queries.push_back({c, l, r});
            print++;
        }
    }

    for(vector<ll>& query : queries) {
        if(query[0] == 'M') {
            if(print == 1) {
                cout << sgt.minimumQuery(query[1], query[2]);
            } else {
                cout << sgt.minimumQuery(query[1], query[2]) << '\n';
            }
            print--;
        } else if(query[0] == 'P'){
            sgt.add(query[1], query[2], query[3]);
        } else {
            if(print == 1) {
                cout << sgt.sumQuery(query[1], query[2]);
            } else {
                cout << sgt.sumQuery(query[1], query[2]) << '\n';
            }
            print--;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    freopen("haybales.in", "r", stdin);
	freopen("haybales.out", "w", stdout);

    solve();
}