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
const ll LL_MAX = 9223372036854775807;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

bool cmp(pair<ll, ll> p1, pair<ll, ll> p2) {
    if(p1.first != p2.first) return p1.first < p2.first;
    return p1.second > p2.second;
}

void solve(){
    int n, p; cin >> n >> p;
    vector<pair<ll, ll>> cop(n);

    rep(i, n) cin >> cop[i].second;
    rep(i, n) cin >> cop[i].first;

    cop.push_back({p, INF});

    // sort by efficiency
    sort(all(cop), cmp);

    ll cost = p;
    int toInform = n - 1;

    for(int i = 0; i < n + 1; i++) {
        if(cop[i].second >= toInform) {
            cost += toInform * cop[i].first;
            break;
        } else {
            cost += cop[i].first * cop[i].second;
            toInform -= cop[i].second;
        }
    }

    cout << cost << '\n';
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