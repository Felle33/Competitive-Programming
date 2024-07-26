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
const ll MOD3 = 99999999999999997;
const ll DIM = 1e6;
const int INF = 1e9;
const ll LLINF = 1e15;
const ll LL_MAX = 9223372036854775807;
const int LOG = 22;

int n, k, p1, p2;

ll compute(vi& next_node, vll& points, int initial_node, ll k) {
    vector<bool> visited(n + 1);
    int node = initial_node;
    ll ans = 0;
    ll path = 0;

    while(!visited[node] && k > 0) {
        visited[node] = 1;
        ans = max(ans, path + k * points[node]);
        path += points[node];
        node = next_node[node];
        k--;
    }

    return ans;
}

void solve(){
    cin >> n >> k >> p1 >> p2;

    vector<int> next_node(n + 1);
    vll points(n + 1);
    rep(i, n) {
        cin >> next_node[i + 1];
    }

    rep(i, n) {
        cin >> points[i + 1];
    }

    ll points_bo = compute(next_node, points, p1, k), points_sa = compute(next_node, points, p2, k);

    if(points_bo > points_sa) {
        cout << "Bodya\n";
    } else if(points_bo < points_sa) {
        cout << "Sasha\n";
    } else {
        cout << "Draw\n";
    }
}

int main(){
    FELLE
    int t; cin >> t;
    while(t--){
        solve();
    }
}