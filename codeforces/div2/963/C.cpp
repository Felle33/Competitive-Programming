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
const ll DIM = 1e6;
const int INF = 1e9;
const ll LLINF = 1e15;
const ll LL_MAX = 9223372036854775807;
const int LOG = 22;

void solve(){
    int n, k; cin >> n >> k;
    vi a(n);
    rep(i, n) cin >> a[i];

    sort(all(a));
    int len = k - 1;

    int sel = a[0];
    bool flag = 1;
    for(int i = 1; i < n; i++) {
        int dif = (a[i] - sel) / k;

        if(dif % 2 == 0) {
            int left_sel = sel + dif * k;
            int right_sel = sel + dif * k + len;

            int left_a = a[i];
            int right_a = a[i] + k - 1;

            if(left_a >= left_sel && left_a <= right_sel || left_a <= left_sel && right_sel <= right_a) {
                sel = max(left_a, left_sel);
                len -= max(left_a - left_sel, 0);
            } else {
                flag = 0;
            }
        } else {
            dif++;
            int left_sel = sel + dif * k;
            int right_sel = sel + dif * k + len;

            int left_a = a[i];
            int right_a = a[i] + k - 1;

            if(left_sel >= left_a && left_sel <= right_a || left_a <= left_sel && right_sel <= right_a) {
                sel = max(left_a, left_sel);
                len -= max(right_sel - right_a, 0);
            } else {
                flag = 0;
            }
        }
    }

    if(!flag) cout << -1 << "\n";
    else cout << sel << "\n";
}

int main(){
    FELLE
    int t; cin >> t;
    while(t--){
        solve();
    }
}