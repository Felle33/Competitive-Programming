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
#include <sstream>

#define all(x) (x).begin(), (x).end()
#define mp make_pair
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))
#define FELLE ios_base::sync_with_stdio(false); cin.tie(NULL); std::cout.precision(0); cout << std::fixed;

using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<unsigned long long> vull;
typedef vector<vector<int>> vvi;
typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;

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

vector<pair<ll, ll>> cities;
vector<vector<int>> states;

struct Edge {
    ll u, v, w;
};

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

ll dist(pair<ll, ll>& p1, pair<ll, ll>& p2) {
    ll x = p1.first - p2.first; ll y = p1.second - p2.second;
    return x * x + y * y;
}

bool cmp(Edge& e1, Edge& e2) {
    return e1.w < e2.w;
}

ld mstCities(vector<int>& state) {
    double ans = 0;
    int n = state.size();
    DSU dsu(n);
    vector<Edge> edges;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            edges.pb({i, j, dist(cities[state[i]], cities[state[j]])});
        }
    }

    sort(all(edges), cmp);

    int ed = n - 1;
    int m = edges.size();
    for(int i = 0; i < m && ed > 0; i++) {
        int u = edges[i].u, v = edges[i].v;
        ld w = edges[i].w;

        if(dsu.unite(u, v)) {
            ans += sqrt(w);
        }
    }

    return ans;
}

ld mstStates(vvi& states) {
    ld ans = 0;
    int numStates = states.size();
    DSU dsu(numStates);
    vector<Edge> edges;

    for(int i = 0; i < numStates; i++) {
        for(int j = i + 1; j < numStates; j++) {
            ll minRail = LLINF;
            for(int u : states[i]) {
                for(int v : states[j]) {
                    minRail = min(minRail, dist(cities[u], cities[v]));
                }
            }
            edges.pb({i, j, minRail});
        }
    }

    sort(all(edges), cmp);

    int ed = numStates - 1;
    int m = edges.size();
    for(int i = 0; i < m && ed > 0; i++) {
        int u = edges[i].u, v = edges[i].v;
        ld w = edges[i].w;

        if(dsu.unite(u, v)) {
            ans += sqrt(w);
        }
    }

    return ans;
}

void solve(int t) {
    ll n, r; cin >> n >> r;
    DSU dsu(n);
    cities = vector<pair<ll, ll>>(n);
    rep(i, n) {
        cin >> cities[i].first >> cities[i].second;
    }

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(i != j && dist(cities[i], cities[j]) <= r * r) {
                dsu.unite(i, j);
            }
        }
    }

    states.erase(all(states));
    vector<bool> assigned(n);

    rep(i, n) {
        if(!assigned[i]) {
            int par = dsu.get(i);
            vi state;
            state.pb(i); assigned[i] = 1;
            for(int j = i + 1; j < n; j++) {
                if(dsu.get(j) == par) {
                    state.pb(j); assigned[j] = 1;
                }
            }
            states.pb(state);
        }
    }

    ld ansRoads = 0;
    for(vi& state : states) ansRoads += mstCities(state);
    ld ansRail = mstStates(states);

    cout << "Case #" << t << ": " << states.size() << " " << ansRoads << " " << ansRail << "\n";
}

int main(){
    //freopen("catch.in", "r", stdin);
	//freopen("catch.out", "w", stdout);
    FELLE
    int t; cin >> t;
    rep(i, t) solve(i + 1);
}