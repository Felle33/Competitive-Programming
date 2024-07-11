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
    int n; cin >> n;
    string s; cin >> s;

    int ans = 1e9;
    vi a(n - 1);
    for(int i = 0; i < n - 1; i++) {
        int cnt = 0;
        for(int j = 0; j < n; j++) {
            if(j == i) {
                a[cnt++] = 10 * (s[j] - '0') + (s[j + 1] - '0');
                j++;
            } else {
                a[cnt++] = (s[j] - '0');
            }
        }

        int val = 0;
        int sum;
        for(int j = 0; j < (int)a.size(); j++) {
            if(a[j] == 0) {
                val = -1;
                break;
            }

            if(a[j] == 1) continue;
            val += a[j];
        }

        if(val == 0) sum = 1;
        else if(val == -1) sum = 0;
        else sum = val;

        ans = min(ans, sum);
    }

    cout << ans << "\n";
}

int main(){
    FELLE
    int t; cin >> t;
    while(t--){
        solve();
    }
}