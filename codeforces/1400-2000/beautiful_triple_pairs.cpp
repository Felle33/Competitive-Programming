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

void solve(){
    int n; cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];

    deque<int> dq;
    map<pair<int, int>, int> pairLastDiffer, pairMidDiffer, pairFirstDiffer;
    map<vector<int>, int> triplets;
    dq.push_back(a[0]);
    dq.push_back(a[1]);

    ll ans = 0;
    for(int i = 2; i < n; i++) {
        dq.push_back(a[i]);
        int alls1 = pairLastDiffer[{dq[0], dq[1]}];
        int do_not_count1 = triplets[{dq[0], dq[1], dq[2]}];
        ans += alls1 - do_not_count1;

        alls1 = pairMidDiffer[{dq[0], dq[2]}];
        ans += alls1 - do_not_count1;

        alls1 = pairFirstDiffer[{dq[1], dq[2]}];
        ans += alls1 - do_not_count1;

        triplets[{dq[0], dq[1], dq[2]}]++;
        pairLastDiffer[{dq[0], dq[1]}]++;
        pairMidDiffer[{dq[0], dq[2]}]++;
        pairFirstDiffer[{dq[1], dq[2]}]++;

        dq.pop_front();
    }

    cout << ans << "\n";
}

int main(){
    FELLE
    int t; cin >> t;
    while(t--){
        solve();
    }
}