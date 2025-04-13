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

void solve(){
    int n; cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    int m; cin >> m;
    vector<string> strings(m);
    rep(i, m) cin >> strings[i];

    map<int, char> intToChar;
    map<char, int> charToInt;
    vector<string> ans;

    for(string& s : strings) {
        if(s.size() != a.size()) {
            ans.push_back("NO\n");
            continue;
        }

        bool flag = 1;
        for(int i = 0; i < n; i++) {
            int num = a[i];
            char c = s[i];

            if(intToChar.count(num) && intToChar[num] != c) {
                // error
                flag = 0;
                break;
            }

            if(charToInt.count(c) && charToInt[c] != num) {
                // error
                flag = 0;
                break;
            }

            intToChar[num] = c;
            charToInt[c] = num;
        }

        if(flag) ans.push_back("YES\n");
        else ans.push_back("NO\n");

        intToChar.clear();
        charToInt.clear();
    }

    for(string& s : ans) cout << s;
}

int main(){
    FELLE
    int t; cin >> t;
    while(t--){
        solve();
    }
}