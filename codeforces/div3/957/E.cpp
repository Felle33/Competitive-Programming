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
    ll n; cin >> n;
    ll cnt = 0;
    vector<pair<ll, ll>> ans;
    int digits;
    if(n < 10) digits = 1;
    else if(n < 100) digits = 2;
    else digits = 3;

    for(ll a = 1; a <= 1e4; a++) {
        ll letters = digits * a;
        for(ll b = max(1LL, letters - 7); b <= letters - 1; b++) {
            string s;
            for(int i = 0; i < (letters - b) / digits; i++) {
                s += to_string(n);
            }

            if(digits == 2 && (letters - b) % digits == 1) {
                s += to_string(n);
                s.pop_back();
            }

            if(digits == 3 && (letters - b) % digits != 0) {
                s += to_string(n);
                if((letters - b) % digits == 2) {
                    s.pop_back();
                } else {
                    s.pop_back(); s.pop_back();
                }
            }

            ll res1 = n * a - b;
            ll res2 = stoi(s);

            if(res1 == res2) {
                cnt++;
                ans.pb({a, b});
            }
        }
    }

    cout << cnt << "\n";
    for(pair<ll, ll>& p : ans) {
        cout << p.first << " " << p.second << "\n";
    }
}

int main(){
    FELLE
    int t; cin >> t;
    while(t--){
        solve();
    }
}