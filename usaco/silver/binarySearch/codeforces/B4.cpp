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
typedef long double ld;

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e8;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

vector<vector<pair<int, ld>>> adj;
vi prec;
int n, m;

bool good(ld mean, vi in_arc) {
    queue<int> q_top;
    vector<ld> dp(n + 1, INF);
    q_top.push(1);
    dp[1] = 0;

    for(int i = 2; i < n; i++) {
        if(in_arc[i] == 0) q_top.push(i);
    }

    while(!q_top.empty()) {
        int node = q_top.front();
        q_top.pop();

        for(pii to : adj[node]) {
            int node_adj = to.first;
            ld weight = to.second;
            in_arc[node_adj]--;
            if(in_arc[node_adj] == 0) q_top.push(node_adj);
            if(dp[node_adj] > dp[node] + weight - mean) {
                dp[node_adj] = dp[node] + weight - mean;
                prec[node_adj] = node;
            }
        }
    }

    return dp[n] <= 0;
}

void solve(){
    cin >> n >> m;
    adj = vector<vector<pair<int, ld>>>(n + 1);
    vi in_arc(n + 1);
    prec = vi(n + 1);
    rep(i, m) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].pb({b, c});
        in_arc[b]++;
    }

    ld l = -1, r = 101;
    rep(i, 120) {
        ld mid = l + (r - l) / 2;
        fill(all(prec), -1);

        if(good(mid, in_arc)) {
            r = mid;
        } else {
            l = mid;
        }
    }

    fill(all(prec), -1);
    good(r, in_arc);

    vi path;
    int node = n;
    while(node != -1) {
        path.pb(node);
        node = prec[node];
    }

    reverse(all(path));

    cout << (path.size() - 1) << '\n';
    for(int x : path) {
        cout << x << " ";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    solve();
}