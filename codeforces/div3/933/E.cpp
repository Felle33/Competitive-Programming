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

const ll MOD1 = 1e9 + 7;
const ll MOD2 = 998244353;
const ll MOD3 = 99999999999999997;
const ll DIM = 1e6;
const ll INF = 1e15;
const int INF_INT = 1e9;
const ll LL_MAX = 9223372036854775807;
const int LOG = 22;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

int n, m, k, d;

ll calc(vll& row) {
    vector<ll> minCost(m);
    deque<pair<ll, ll>> dq;

    for(int i = 0; i < m && i <= d; i++) {
        while(!dq.empty() && dq.front().first >= row[i]) {
            dq.pop_front();
        }

        if(!dq.empty() && dq.back().second < i - d) {
            dq.pop_back();
        }
        dq.push_front({row[i], i});
    }
    
    for(int i = d; i < m; i++) {
        minCost[i] = dq.back().first + 1;
        
        while(!dq.empty() && dq.front().first >= minCost[i] + row[i]) {
            dq.pop_front();
        }

        if(!dq.empty() && dq.back().second < i - d) {
            dq.pop_back();
        }
        dq.push_front({minCost[i] + row[i], i});
    }

    return minCost[n - 1] + 1;
}

// UNFINISHED
void solve(){
    cin >> n >> m >> k >> d;

    vector<vll> grid(n, vll(m));
    rep(i, n) {
        rep(j, m) {
            cin >> grid[i][j];
        }
    }

    vll cost(n);
    rep(i, n) {
        cost[i] = calc(grid[i]);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    int t;
    cin >> t;

    while(t--){
        solve();
    }
}