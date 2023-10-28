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

struct DSU {
    vector<int> p, distanceFromBoss;

    DSU(int N) {
        p = vector<int>(N);
        distanceFromBoss = vector<int>(N);

        for(int i = 0; i < N; i++){
            p[i] = i;
        }
    }

    pair<int, int> get(int x) {
        if(p[x] == x) return make_pair(x, 0);
        pair<int, int> res = get(p[x]);
        p[x] = res.first;
        // update distance from boss
        int lastDistanceFromBoss = distanceFromBoss[x];
        distanceFromBoss[x] += res.second;
        res.second += lastDistanceFromBoss;
        return res;
    }

    void unite(int x, int y) {
        x = get(x).first, y = get(y).first;
        if(x == y) return ;
        p[x] = y;
        distanceFromBoss[x] = 1;
    }

    int queryDistance(int x) {
        return get(x).second;
    }
};

void solve(){
    int n, m;
    cin >> n >> m;
    DSU dsu = DSU(n);

    while(m--) {
        int op; cin >> op;
        if(op == 1) {
            int a, b; cin >> a >> b;
            a--, b--;
            dsu.unite(a, b);
        } else {
            int x; cin >> x;
            x--;
            cout << dsu.queryDistance(x) << '\n';
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}