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
typedef long long ll;
typedef pair<int,int> pii;

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e15;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

void solve(){
    int n, k; cin >> n >> k;
    vector<ll> lec(n), awake(n);
    rep(i, n) cin >> lec[i];
    rep(i, n) cin >> awake[i];

    vector<ll> pref(n);
    pref[0] = lec[0];
    for(int i = 1; i < n; i++) pref[i] = pref[i - 1] + lec[i];

    vector<ll> p(n);
    p[0] = lec[0] * awake[0];
    for(int i = 1; i < n; i++) p[i] = p[i - 1] + lec[i] * awake[i];

    vector<ll> s(n);
    s[n - 1] = lec[n - 1] * awake[n - 1];
    for(int i = n - 2; i >= 0; i--) s[i] = s[i + 1] + lec[i] * awake[i];

    ll ans = 0;
    for(int i = 0; i < n - k + 1; i++) {
        ll cur = 0;
        if(i > 0) cur += p[i - 1];
        if(i < n - k) cur += s[i + k];

        cur += pref[i + k - 1];
        if(i > 0) cur -= pref[i - 1];
        ans = max(ans, cur);
    }

    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}