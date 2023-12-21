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
const ll DIM = 1e6;
const ll INF = 1e15;
const int INF_INT = 1e9;
const ll LL_MAX = 9223372036854775807;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

int n;

bool cmp(pair<ll, ll>& a, pair<ll, ll>& b) {
    return a.second > b.second;
}

void max_3(vll& a, vector<pair<ll, ll>>& ans) {
    for(int i = 0; i < 3; i++) {
        ans[i] = {i, a[i]};
    }

    sort(all(ans), cmp);

    for(int i = 3; i < n; i++) {
        if(a[i] > ans[0].second) {
            ans[2] = ans[1];
            ans[1] = ans[0];
            ans[0].first = i;
            ans[0].second = a[i];
        } else if(a[i] > ans[1].second) {
            ans[2] = ans[1];
            ans[1].first = i;
            ans[1].second = a[i];
        } else if(a[i] > ans[2].second) {
            ans[2].first = i;
            ans[2].second = a[i];
        }
    }
}

void compute_max(vector<pair<ll, ll>>& ans1, vector<pair<ll, ll>>& ans2, vector<pair<ll, ll>>& ans3) {
    ll ans = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(ans2[j].first == ans1[i].first) continue;

            for(int k = 0; k < 3; k++) {
                if(ans3[k].first == ans2[j].first || ans3[k].first == ans1[i].first) continue;
                ans = max(ans, ans1[i].second + ans2[j].second + ans3[k].second);
            }
        }
    }
    cout << ans << '\n';
}

void solve(){
    cin >> n;

    vll a(n), b(n), c(n);
    rep(i, n) {
        cin >> a[i];
    }

    rep(i, n) {
        cin >> b[i];
    }

    rep(i, n) {
        cin >> c[i];
    }

    vector<pair<ll, ll>> ans1(3), ans2(3), ans3(3);
    max_3(a, ans1);
    max_3(b, ans2);
    max_3(c, ans3);

    compute_max(ans1, ans2, ans3);
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