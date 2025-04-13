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
    int n; cin >> n;
    vector<pii> edges_to_destroy, edges_to_build;
    int ans = 0;
    DSU dsu(n);
    rep(i, n - 1) {
        int a, b; cin >> a >> b;
        a--, b--;
        if(!dsu.unite(a, b)) {
            edges_to_destroy.push_back({a, b});
            ans++;
        }
    }

    for(int i = 1; i < n; i++) {
        if(dsu.get(i) != dsu.get(0))  {
            edges_to_build.push_back({0, i});
            dsu.unite(0, i);
        }
    }

    cout << ans << "\n";
    for(int i = 0; i < ans; i++) {
        pii to_destroy = edges_to_destroy[i];
        pii to_build = edges_to_build[i];
        cout << to_destroy.first + 1 << " " << to_destroy.second + 1 << " " << to_build.first + 1 << " " << to_build.second + 1 << "\n";
    }
}

int main(){
    FELLE
    solve();
}