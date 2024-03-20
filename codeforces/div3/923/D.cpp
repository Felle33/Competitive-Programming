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
const ll DIM = 2e5;
const ll INF = 1e15;
const int INF_INT = 1e9;
const ll LL_MAX = 9223372036854775807;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";
const int LOG = 22;

typedef struct {
    bool allEquals;
    pair<int, int> num;
} node;

int n;
node sparse[LOG][DIM + 1];
pair<int, int> res;
vi a;

void build() {
    for(int k = 1; k < LOG; k++) {
        for(int i = 0; i + (1 << k) - 1 < n; i++) {
            if(sparse[k - 1][i].allEquals && sparse[k - 1][i + (1 << (k - 1))].allEquals) {
                int first_index = sparse[k - 1][i].num.first;
                int second_index = sparse[k - 1][i + (1 << (k - 1))].num.first;
                if(a[first_index] == a[second_index]) {
                    sparse[k][i].allEquals = 1;
                    sparse[k][i].num.first = sparse[k - 1][i].num.first;
                } else {
                    sparse[k][i].allEquals = 0;
                    sparse[k][i].num.first = sparse[k - 1][i].num.first;
                    sparse[k][i].num.second = sparse[k - 1][i + (1 << (k - 1))].num.first;
                }
            } else {
                if(sparse[k - 1][i].allEquals == 0) {
                    sparse[k][i].allEquals = 0;
                    sparse[k][i].num.first = sparse[k - 1][i].num.first;
                    sparse[k][i].num.second = sparse[k - 1][i].num.second;
                } else {
                    sparse[k][i].allEquals = 0;
                    sparse[k][i].num.first = sparse[k - 1][i + (1 << (k - 1))].num.first;
                    sparse[k][i].num.second = sparse[k - 1][i + (1 << (k - 1))].num.second;
                }
            }
        }
    }
}

// indexes, true => allEquals
bool query(int l, int r) {
    int dif = r - l + 1;
    bool ans = 1;
    int eq_el = -1;

    for(int k = 0; k < 31 && ans; k++) {
        if(dif & (1 << k)) {
            if(sparse[k][l].allEquals) {
                if(eq_el == -1) {
                    eq_el = sparse[k][l].num.first;
                } else if(a[eq_el] != a[sparse[k][l].num.first]) {
                    res.first = eq_el;
                    res.second = sparse[k][l].num.first;
                    ans = 0;
                }
            } else {
                res.first = sparse[k][l].num.first;
                res.second = sparse[k][l].num.second;
                ans = 0;
            }

            l += (1 << k);
        }
    }

    return ans;
}

void solve(){
    cin >> n;

    a.resize(n);
    rep(i, n) {
        cin >> a[i];
        sparse[0][i].num.first = i;
        sparse[0][i].allEquals = 1;
    }

    build();
    int q;
    cin >> q;

    while(q--) {
        int l, r;
        cin >> l >> r;
        r--, l--;

        if(query(l, r)) {
            cout << -1 << " " << -1 << '\n';
        } else {
            cout << res.first + 1 << " " << res.second + 1 << '\n';
        }
        
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
        cout << '\n';
        solve();
        
    }
}