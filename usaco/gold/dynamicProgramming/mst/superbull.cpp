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
typedef pair<int,int> pii;

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e9;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

struct DSU {
	int n;
	vector<int> p;
    vector<unsigned int> r;

	DSU() {}

    DSU(int N) {
        p = vector<int>(N);
        r = vector<unsigned int>(N, 1);

        for(int i = 0; i < N; i++){
            p[i] = i;
        }
    }

    int get(int x) { return p[x] == x ? x : p[x] = get(p[x]); }

    bool unite(int x, int y) {
        x = get(x), y = get(y);
        if(x == y) return false;
        if(r[x] == r[y]) 
            r[x]++;
        
        if(r[x] > r[y]){
			p[y] = x;
		}
        else {
			p[x] = y;
		}  
        return true;
    }

    void reset() {
		for(int i = 0; i < n; i++){
            p[i] = i;
			r[i] = 1;
        }
	}
};

struct Edge {
    int a, b, cost;
};

bool cmp(const Edge& e1, const Edge& e2) {
    return e1.cost > e2.cost;
}

void solve(){
    int n;
    cin >> n;

    vector<int> teams(n);
    rep(i, n) {
        cin >> teams[i];
    }

    vector<Edge> scores;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            scores.push_back({i, j, teams[i] ^ teams[j]});
        }
    }

    sort(all(scores), cmp);
    DSU dsu = DSU(n);
    int conn = 0;
    ll total_cost = 0;

    for(Edge e : scores) {
        int pa = dsu.get(e.a), pb = dsu.get(e.b);
        if(pa != pb) {
            dsu.unite(e.a, e.b);
            conn++;
            total_cost += e.cost;
        }

        if(conn == n - 1) {
            break;
        }
    }

    if(conn == n - 1) {
        cout << total_cost << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("superbull.in", "r", stdin);
	freopen("superbull.out", "w", stdout);

    solve();
}