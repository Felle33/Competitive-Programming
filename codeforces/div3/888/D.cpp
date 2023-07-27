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
    vector<ll> pref(n);
    pref[0] = 0;
    rep(i, n - 1) {
        cin >> pref[i + 1];
    }

    vector<ll> diff(n - 1);
    for(int i = 0; i < n - 1; i++) {
        diff[i] = pref[i + 1] - pref[i];
    }

    vector<bool> used(n + 1);
    int l = 0, r = n - 2;
    for(; l < n - 1; l++) {
        ll number = diff[l];
        if(number <= n && !used[number]) {
            used[number] = true;
        } else {
            break;
        }
    }

    if(l == n - 1) {
        cout << "YES\n";
        return;
    }

    for(; r >= 0; r--) {
        ll number = diff[r];
        if(number <= n && !used[number]) {
            used[number] = true;
        } else {
            break;
        }
    }

    int n1 = -1, n2 = -1;
    for(int i = 1; i <= n; i++) {
        if(!used[i]) {
            if(n1 == -1) {
                n1 = i;
            } else {
                n2 = i;
            }
        }
    }

    if(diff[l] == n1 + n2) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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