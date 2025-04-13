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
vector<int> DI = {0, 1, -1, 0};
vector<int> DJ = {1, 0, 0, -1};

int n;

vector<pii> possible(vector<int>& a, int x, int not_insert_idx) {
    vector<pii> ans;
    multiset<int> s;
    for(int i = 0; i < (int)a.size(); i++) {
        if(i != not_insert_idx) {
            s.insert(a[i]);
        }
    }
    
    ans.push_back({x, a[not_insert_idx]});
    while(s.size() > 0) {
        auto it_max = s.end();
        it_max--;
        int max_el = *it_max;
        int to_search = x - max_el;
        s.erase(it_max);

        auto it_searched = s.find(to_search);
        if(it_searched == s.end()) return {};

        ans.push_back({max_el, to_search});
        x = max_el;
        s.erase(it_searched);
    }

    return ans;
}

void solve(){
    cin >> n;
    int sz = 2 * n;
    vector<int> a(sz);
    vector<pii> ans;
    
    rep(i, sz) {
        cin >> a[i];
    }
    
    sort(all(a));
    int max_el = a[sz - 1];
    a.pop_back();
    
    bool is_possible = 0;
    int start;

    for(int i = 0; i < sz - 1; i++) {
        start = a[i] + max_el;
        ans = possible(a, max_el, i);

        if(ans.size()) {
            is_possible = 1;
            break;
        }
    }

    if(is_possible) {
        cout << "YES\n" << start << "\n";
        for(pii& p : ans) {
            cout << p.first << " " << p.second << "\n";
        }
    } else {
        cout << "NO\n";
    }
}

int main(){
    FELLE
    int t; cin >> t;
    while(t--)
        solve();
}