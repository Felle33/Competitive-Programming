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
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

vll a;
int n;

bool good(ll time) {
    ll pleft = a[0];
    int l = 1;
    while(l < n) {
        ll diff = a[l] - pleft;
        ll tmpMax = (diff + 1) / 2 ;
        if(tmpMax > time) break;
        l++;
    }

    ll sright = a[n - 1];
    int r = n - 2;
    while(r >= 0) {
        ll diff = sright - a[r];
        ll tmpMax = (diff + 1) / 2 ;
        if(tmpMax > time) break;
        r--;
    }

    if(l >= r) return true;
    return a[r] - a[l] <= 2 * time;
}

void solve(){
    cin >> n;
    a = vll(n);
    rep(i, n) cin >> a[i];
    sort(all(a));

    ll l = -1, r = 1e9;
    while(l + 1 < r) {
        ll mid = l + (r - l) / 2;

        if(good(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }

    cout << r << '\n';
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