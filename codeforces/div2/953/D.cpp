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
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};

void solve(){
    ll n, c; cin >> n >> c;
    vll a(n);
    rep(i, n) cin >> a[i];
    a[0] += c;

    ll pref = 0;
    multiset<ll> left_max_set, right_max_set;
    for(int i = 1; i < n; i++) right_max_set.insert(a[i]);

    for(int i = 0; i < n; i++) {
        ll left_max = left_max_set.empty() ? -1 : *left_max_set.rbegin();
        ll right_max = right_max_set.empty() ? -1 : *right_max_set.rbegin();

        if(a[i] > left_max && a[i] >= right_max) {
            cout << 0 << " ";
        } else if(a[i] <= left_max && a[i] >= right_max) {
            cout << i << " ";
        } else {
            if(a[i] + pref >= right_max) {
                cout << i << " ";
            } else {
                cout << i + 1 << " ";
            }
        }

        left_max_set.insert(a[i]);
        if(i + 1 < n) right_max_set.erase(right_max_set.find(a[i + 1]));
        pref += a[i];
    }

    cout << "\n";
}

int main(){
    FELLE
    int t; cin >> t;
    while(t--){
        solve();
    }
}