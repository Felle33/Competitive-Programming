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
const ll DIM = 2e5;
const int INF = 1e9;
const ll LLINF = 1e15;
const ll LL_MAX = 9223372036854775807;
const int LOG = 22;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};

int freq[DIM + 20];
int n;
vi a;
ll ans;

void operate() {
    for(int i = 0; i <= n; i++) freq[i] = 0;

    int mx = 0;
    for(int i = 0; i < n; i++) {
        ans += a[i];
        freq[a[i]]++;
        if(freq[a[i]] >= 2) mx = max(mx, a[i]);
        a[i] = mx;
    }
}

void solve(){
    cin >> n;
    a = vi(n);
    ans = 0;

    rep(i, n) {
        cin >> a[i];
    }

    operate();
    operate();

    for(int i = n - 1; i >= 0; i--) {
        ans += 1ll * a[i] * (n - i);
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