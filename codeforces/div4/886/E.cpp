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

ll n, c;
vector<ll> lati;

ll calc_card(int w) {
    ll sum_area = 0;
    for(int i = 0; i < n; i++) {
        ll area_i = (lati[i] + 2 * w) * (lati[i] + 2 * w);
        if(area_i > c || sum_area + area_i > c) {
            return c + 1;
        }
        sum_area += area_i;
    }
    return sum_area;
}

void solve(){
    
    cin >> n >> c;
    lati.resize(n);
    
    rep(i, n) {
        cin >> lati[i];
    }

    ll l = -1, r = 1e9;
    while(l <= r) {
        ll m = l + (r - l) / 2;
        ll sum_area = calc_card(m);
        if(sum_area == c) {
            cout << m << '\n';
            return;
        } else if(sum_area < c) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    
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