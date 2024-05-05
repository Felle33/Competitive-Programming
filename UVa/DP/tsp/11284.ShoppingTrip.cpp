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
const int INF_INT = 1e9;
const ll LL_MAX = 9223372036854775807;
const int LOG = 22;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};

int n, m, p;
vector<vector<pair<int, ld>>> adj;
vector<vector<ld>> distances;
vector<pair<int, ld>> cds;

void shortest_path(int start) {
    priority_queue<pair<ld, int>, vector<pair<ld, int>>, greater<pair<ld, int>>> pq;
    pq.push({0, start});
    distances[start][start] = 0;

    while(!pq.empty()) {
        pair<ld, int> p = pq.top(); pq.pop();
        int node = p.second; ld dis = p.first;

        if(distances[start][node] < dis) continue;
        for(pair<int, ld> pt : adj[node]) {
            int to = pt.first; ld w = pt.second;

            if(dis + w < distances[start][to]) {
                distances[start][to] = dis + w;
                pq.push({distances[start][to], to});
            }
        }
    }
}

// ATTENTION DOUBLE GIVES ERROR!!!
void solve(){
    cin >> n >> m;
    adj = vector<vector<pair<int, ld>>>(n + 1);
    distances = vector<vector<ld>>(n + 1, vector<ld>(n + 1, 1e9));
    rep(i, m) {
        int a, b;
        ld w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    cin >> p;
    cds = vector<pair<int, ld>>(p);
    rep(i, p) cin >> cds[i].first >> cds[i].second;

    // Dijkstra starting from each node
    rep(i, n + 1) shortest_path(i);

    // dp
    vector<vector<ld>> dp(1 << p, vector<ld>(p, 1e9));

    for(int state = 1; state < (1 << p); state++) {
        for(int pos = 0; pos < p; pos++) {
            if((state & (1 << pos)) == 0) continue;
            int nodeCd = cds[pos].first;
            int prevState = state ^ (1 << pos);

            if(prevState == 0) {
                dp[state][pos] = min(dp[state][pos], distances[0][nodeCd]);
            } else {
                for(int lastPos = 0; lastPos < p; lastPos++) {
                    if(prevState & (1 << lastPos)) {
                        int nodeLastCd = cds[lastPos].first;
                        dp[state][pos] = min(dp[state][pos], dp[prevState][lastPos] + distances[nodeLastCd][nodeCd]);
                    }
                }
            }
        }
    }

    // watch if one of the state is better
    int ansState = 0;
    ld bestAns;
    ld ansStayHome = 0;
    rep(i, p) ansStayHome += cds[i].second;
    bestAns = ansStayHome;

    for(int state = 1; state < (1 << p); state++) {
        ld cdsHome = 0;
        for(int i = 0; i < p; i++) {
            if((state & (1 << i)) == 0) {
                cdsHome += cds[i].second;
            }
        }

        for(int pos = 0; pos < p; pos++) {
            if((state & (1 << pos)) == 0) continue;

            if(cdsHome + dp[state][pos] + distances[cds[pos].first][0] < bestAns) {
                bestAns = cdsHome + dp[state][pos] + distances[cds[pos].first][0];
                ansState = state;
            }
        }
    }

    if(ansState != 0) {
        cout << "Daniel can save $" << (ansStayHome - bestAns) << "\n";
    } else {
        cout << "Don't leave the house\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(2);
    cout << std::fixed;

    //freopen("catch.in", "r", stdin);
	//freopen("catch.out", "w", stdout);

    int t;
    cin >> t;

    while(t--){
        solve();
    }
}