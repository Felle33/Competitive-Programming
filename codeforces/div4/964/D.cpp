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
    string s, t; cin >> s >> t;

    int n = s.size(), m = t.size();
    int i = 0, j = 0;
    for(; i < n && j < m; ) {
        if(s[i] == '?') {
            s[i] = t[j];
            i++, j++;
        } else if(s[i] == t[j]) {
            i++, j++;
        } else {
            i++;
        }
    }

    bool flag = (j == m);
    for(int i = 0; i < n; i++) {
        if(s[i] == '?') s[i] = 'a';
    }

    if(!flag) {
        cout << "NO\n";
    } else {
        cout << "YES\n" << s << "\n";
    }
}

int main(){
    FELLE
    int t; cin >> t;
    while(t--){
        solve();
    }
}