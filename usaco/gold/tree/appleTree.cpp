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
#define mp make_pair
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))

using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<unsigned long long> vull;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long>> vvll;
typedef long long ll;
typedef pair<int,int> pii;

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e15;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

vll waysToFall;
vvi adj;

ll ways(int node, int p) {
    if(adj[node].size() == 1 && adj[node][0] == p) {
        waysToFall[node] = 1;
        return 1;
    }
    ll ans = 0;
    for(int to : adj[node]) {
        if(to == p) continue;
        ans += ways(to, node);
    }
    waysToFall[node] = ans;
    return ans;
}

void solve(){
    int n; cin >> n;
    waysToFall = vll(n);
    adj = vvi(n);
    rep(i, n - 1) {
        int a, b; cin >> a >> b;
        a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    ways(0, -1);

    int q; cin >> q;
    rep(i, q) {
        int a, b; cin >> a >> b;
        a--, b--;
        ll tot = waysToFall[a];
        tot *= waysToFall[b];
        cout << tot << '\n';
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t-- > 0){
		solve();
	}
}