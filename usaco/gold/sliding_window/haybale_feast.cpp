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
    int n, m;
    cin >> n >> m;

    vector<pair<ll, ll>> meals(n);
    rep(i, n) {
        cin >> meals[i].first >> meals[i].second;
    }

    ll cur_flavour = 0;
    ll ans = 1e18;
    multiset<ll> spicy;
    for(int l = 0, r = 0; r < n; r++) {
        while(cur_flavour >= m) {
            ans = min(ans, *spicy.rbegin());
            cur_flavour -= meals[l].first;
            spicy.erase(spicy.find(meals[l].second));
            l++;
        }

        cur_flavour += meals[r].first;
        spicy.insert(meals[r].second);
        if(cur_flavour >= m) {
            ans = min(ans, *spicy.rbegin());
        }
    }

    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("hayfeast.in", "r", stdin);
	freopen("hayfeast.out", "w", stdout);
    
    solve();
}