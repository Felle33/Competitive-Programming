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

struct SegmentTree {
    int size;
    vector<ll> dis, delta;

    SegmentTree(int n) {
        size = 1;
        while(size < n) size *= 2;
        dis.resize(2 * size, 0LL);
        delta.resize(2 * size, 0LL);
    }

    ll g(pair<ll, ll>& p1, pair<ll, ll>& p2) {
        return abs(p1.first - p2.first) + abs(p1.second - p2.second);
    }

    void build(vector<pair<ll, ll>>& points){
        build(points, 0, 0, size);
    }

    void build(vector<pair<ll, ll>>& points, int x, int lx, int rx) {
        if(rx - lx == 1) {
            int n = points.size();
            if(lx < n - 1) {
                dis[x] = g(points[lx], points[lx + 1]);
            }

            if(lx < n - 2) {
                delta[x] = g(points[lx], points[lx + 1]) + g(points[lx + 1], points[lx + 2]) - g(points[lx], points[lx + 2]);
            }
            return;
        }

        int mid = (lx + rx) / 2;
        build(points, 2 * x + 1, lx, mid);
        build(points, 2 * x + 2, mid, rx);
        dis[x] = dis[2 * x + 1] + dis[2 * x + 2];
        delta[x] = max(delta[2 * x + 1], delta[2 * x + 2]);
    }

    void updateCheckPointDis(int i, vector<pair<ll, ll>>& points, int x, int lx, int rx) {
        if(rx - lx == 1) {
            dis[x] = g(points[lx], points[lx + 1]);
            return;
        }

        int mid = (lx + rx) / 2;
        if(i < mid) {
            updateCheckPointDis(i, points, 2 * x + 1, lx, mid);
        } else {
            updateCheckPointDis(i, points, 2 * x + 2, mid, rx);
        }
        dis[x] = dis[2 * x + 1] + dis[2 * x + 2];
    }

    void updateCheckPointDelta(int i, vector<pair<ll, ll>>& points, int x, int lx, int rx) {
        if(rx - lx == 1) {
            delta[x] = g(points[lx], points[lx + 1]) + g(points[lx + 1], points[lx + 2]) - g(points[lx], points[lx + 2]);
            return;
        }

        int mid = (lx + rx) / 2;
        if(i < mid) {
            updateCheckPointDelta(i, points, 2 * x + 1, lx, mid);
        } else {
            updateCheckPointDelta(i, points, 2 * x + 2, mid, rx);
        }
        delta[x] = max(delta[2 * x + 1], delta[2 * x + 2]);
    }

    ll querySgt1(int l_query, int r_query, int x, int lx, int rx) {
        if(r_query <= lx || l_query >= rx) return 0;
        if(l_query <= lx && rx <= r_query) return dis[x];

        int mid = (lx + rx) / 2;
        return querySgt1(l_query, r_query, 2 * x + 1, lx, mid) + querySgt1(l_query, r_query, 2 * x + 2, mid, rx);
    }

    ll querySgt2(int l_query, int r_query, int x, int lx, int rx) {
        if(r_query <= lx || l_query >= rx) return 0;
        if(l_query <= lx && rx <= r_query) return delta[x];

        int mid = (lx + rx) / 2;
        return max(querySgt2(l_query, r_query, 2 * x + 1, lx, mid), querySgt2(l_query, r_query, 2 * x + 2, mid, rx));
    }

    ll queryDis(int l_query, int r_query) {
        int d1 = querySgt1(l_query, r_query, 0, 0, size);
        int d1_d2 = querySgt2(l_query, r_query - 1, 0, 0, size);
        return d1 - d1_d2;
    }

};

void solve(){
    int n, q; cin >> n >> q;
    vector<pair<ll, ll>> points(n);
    rep(i, n) {
        cin >> points[i].first >> points[i].second;
    }

    SegmentTree sgt(n);
    sgt.build(points);

    while(q--) {
        char c; cin >> c;
        if(c == 'Q') {
            int l, r;
            cin >> l >> r;
            l--, r--;
            cout << sgt.queryDis(l, r) << '\n';

        } else {
            int i, a, b;
            cin >> i >> a >> b;
            i--;
            points[i].first = a, points[i].second = b;

            for(int j = i - 1; j <= i; j++) {
                if(j < 0 || j >= n - 1) continue;
                sgt.updateCheckPointDis(j, points, 0, 0, sgt.size);
            }

            for(int j = i - 2; j <= i; j++) {
                if(j < 0 || j >= n - 2) continue;
                sgt.updateCheckPointDelta(j, points, 0, 0, sgt.size);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    freopen("marathon.in", "r", stdin);
	freopen("marathon.out", "w", stdout);

    solve();
}