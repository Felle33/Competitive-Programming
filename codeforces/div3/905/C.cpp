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
#include <bitset>

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
const ll LL_MAX = 9223372036854775807;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

void solve(){
    int n, k; cin >> n >> k;
    vi a(n);
    rep(i, n) cin >> a[i];

    if(k != 4) {
        int ans = 1000;
        rep(i, n) {
            int fin_num = k;
            int j = 2;
            while(fin_num < a[i]) {
                fin_num = k * j;
                j++;
            }

            ans = min(ans, fin_num - a[i]);
        }

        cout << ans << '\n';
    } else {
        int div4 = 0, div2 = 0;
        rep(i, n) {
            if(a[i] % 4 == 0) div4++;
            if(a[i] % 2 == 0) div2++;
        }

        if(div4 >= 1 || div2 >= 2) {
            cout << 0 << '\n';
            return;
        }

        int ans4 = 1000;
        int n1 = 100, n2 = 100;
        rep(i, n) {
            int fin_num2 = 2;
            int fin_num4 = 4;
            int j = 2;
            while(fin_num2 < a[i]) {
                fin_num2 = 2 * j;
                j++;
            }

            j = 2;
            while(fin_num4 < a[i]) {
                fin_num4 = 4 * j;
                j++;
            }

            ans4 = min(ans4, fin_num4 - a[i]);

            int dif2 = fin_num2 - a[i];
            if(dif2 < n1) {
                n2 = n1;
                n1 = dif2;
            } else if(dif2 < n2) {
                n2 = dif2;
            }
        }

        int ans = min(ans4, n1 + n2);
        cout << ans << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    int t;
    cin >> t;

    while(t--){
        solve();
    }
}