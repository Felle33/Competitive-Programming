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
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e9;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

void solve(){
    int n;
    cin >> n;

    map<int, ll> ver, hor, diag1, diag2;
    
    rep(i, n) {
        int x, y;
        cin >> x >> y;

        ver[x]++;
        hor[y]++;
        diag1[x - y]++;
        diag2[x + y]++;
    }

    ll ans = 0;
    for(auto it = ver.begin(); it != ver.end(); it++) {
        ll x = it->second;

        ans += x * (x - 1);
    }

    for(auto it = hor.begin(); it != hor.end(); it++) {
        ll x = it->second;

        ans += x * (x - 1);
    }

    for(auto it = diag1.begin(); it != diag1.end(); it++) {
        ll x = it->second;

        ans += x * (x - 1);
    }

    for(auto it = diag2.begin(); it != diag2.end(); it++) {
        ll x = it->second;

        ans += x * (x - 1);
    }
    
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        solve();
    }
}