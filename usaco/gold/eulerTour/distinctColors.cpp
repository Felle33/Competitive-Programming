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
const ll MAX_N = 2e5 + 1;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

vvi adj;
set<int> colorsSet[MAX_N];
int distinct_nums[MAX_N];

void dfs(int node, int parent) {
    for(int child : adj[node]) {
        if(child != parent) {
            dfs(child, node);
            if (colorsSet[node].size() < colorsSet[child].size()) {
				swap(colorsSet[node], colorsSet[child]);
			}
			for (int item : colorsSet[child]) { colorsSet[node].insert(item); }
        }
    }

    distinct_nums[node] = colorsSet[node].size();
}

void solve(){
    int n; cin >> n;
    rep(i, n) {
        int c; cin >> c;
        colorsSet[i].insert(c);
    }

    adj = vvi(n);
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    dfs(0, -1);

    for(int i = 0; i < n; i++) {
        cout << distinct_nums[i] << " ";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    solve();
}