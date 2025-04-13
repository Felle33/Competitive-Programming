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
const ll DIM = 1e6;
const int INF = 1e9;
const ll LLINF = 1e15;
const ll LL_MAX = 9223372036854775807;
const int LOG = 22;
vector<int> DI = {0, 1, -1, 0};
vector<int> DJ = {1, 0, 0, -1};

struct DSU {
	int n; vector<int> p; vector<unsigned int> r;

	DSU() {}

    DSU(int N) {
        p = vector<int>(N); r = vector<unsigned int>(N, 1);
        for(int i = 0; i < N; i++){
            p[i] = i;
        }
    }

    int get(int x) { return p[x] == x ? x : p[x] = get(p[x]); }

    bool can_unite(int x, int y) {
        return get(x) != get(y);
    }

    bool unite(int x, int y) {
        x = get(x), y = get(y);
        if(x == y) return false;
        if(r[x] == r[y]) r[x]++;
        
        if(r[x] > r[y]){
			p[y] = x;
		} else {
			p[x] = y;
		}  
        return true;
    }

    void reset() { rep(i, n) {p[i] = i; r[i] = 1;} }
};

void solve(){
    int n, m1, m2; cin >> n >> m1 >> m2;

    DSU dsu1(n), dsu2(n);

    rep(i, m1) {
        int a, b; cin >> a >> b;
        a--, b--;
        dsu1.unite(a, b);
    }

    rep(i, m2) {
        int a, b; cin >> a >> b;
        a--, b--;
        dsu2.unite(a, b);
    }

    vector<pii> edges;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(dsu1.can_unite(i, j) && dsu2.can_unite(i, j)) {
                edges.push_back({i + 1, j + 1});
                dsu1.unite(i, j);
                dsu2.unite(i, j);
            }
        }
    }

    cout << (edges.size()) << "\n";
    for(pii& p : edges) {
        cout << p.first << " " << p.second << "\n";
    }
}

int main(){
    FELLE
    solve();
}