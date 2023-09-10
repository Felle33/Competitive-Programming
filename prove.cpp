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
#include <numeric>

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

void solve(){
    int n; cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];

    vi pref(n + 1);
    pref[0] = 0;
    for(int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] ^ a[i - 1];
    }

    string str; cin >> str;
    int xor0 = 0, xor1 = 0;
    for(int i = 0; i < n; i++) {
        if(str[i] == '1') xor1 ^= a[i];
        else xor0 ^= a[i];
    }

    int q; cin >> q;
    rep(i, q) {
        int op; cin >> op;
        if(op == 1) {
            int l, r;
            cin >> l >> r;
            l--;

            int xorDiff = pref[r] ^ pref[l];
            xor0 ^= xorDiff;
            xor1 ^= xorDiff;
        } else {
            int num; cin >> num;

            if(num == 0) cout << xor0 << ' ';
            else cout << xor1 << ' ';
        }
    }

    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) {
        solve();
    }
    
}