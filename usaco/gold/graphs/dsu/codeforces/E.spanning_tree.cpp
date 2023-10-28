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
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e9;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

struct Edge {
    int a, b;
    ll w;

    bool operator<(const Edge other) {
        return w < other.w;
    }
};

struct DSU {
    vector<int> p, r;

    DSU(int N) {
        p = vector<int>(N);
        r = vector<int>(N);

        for(int i = 0; i < N; i++){
            p[i] = i;
        }
    }

    int get(int x) {
        if(p[x] == x) return x;
        p[x] = get(p[x]);
        return p[x];
    }

    bool unite(int x, int y) {
        x = get(x), y = get(y);
        if(x == y) return false;
        if(r[x] == r[y]) r[x]++;

        if(r[x] > r[y]) {
            p[y] = x;
        } else {
            p[x] = y;
        }
        return true;
    }

};

void solve(){
    int n, m;
    cin >> n >> m;
    vector<Edge> edges;
    rep(i, m) {
        int a, b, w; cin >> a >> b >> w;
        a--, b--;
        edges.push_back({a, b, w});
    }
    sort(all(edges));
    DSU dsu = DSU(n);

    int e = 0, i = 0;
    ll ans = 0;
    while(e < n - 1) {
        if(dsu.unite(edges[i].a, edges[i].b)) {
            e++;
            ans += edges[i].w;
        }

        i++;
    }

    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}