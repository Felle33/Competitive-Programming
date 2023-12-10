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

const ll MOD1 = 99999999999999997;
const ll MOD2 = 998244353;
const ll DIM = 1e6;
const ll INF = 1e15;
const ll LL_MAX = 9223372036854775807;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

int ord(char c) {
    return c - 'a' + 1;
}

bool cmp(pii& a, pii& b) {
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

// NON VIENE!!!!
// EDIT: E' VENUTO CAZZO!!!
void solve(){
    string s; cin >> s;
    string good; cin >> good;
    int k; cin >> k;
    int n = s.size();
    ll b1 = 31;
    //ll b2 = 37;
    //vector<pii> goodSubstring;
    vi goodSubstring;
    int ans = 0;
 
    for(int len = 1; len <= n; len++) {
        int notGoodLetters = 0;
        int l = 0, r = 0;
        ll h1 = 0;
        //ll h2 = 0;
        ll last_base1 = 1;
        //ll last_base2 = 1;
 
        while(r < len) {
            if(good[s[r] - 'a'] != '1') notGoodLetters++;
            h1 = (b1 * h1 + ord(s[r])) % MOD1;
            //h2 = (b2 * h2 + ord(s[r])) % MOD2;
 
            if(r < len - 1) last_base1 = (last_base1 * b1) % MOD1;
            //if(r < len - 1) last_base2 = (last_base2 * b2) % MOD2;
            r++;
        }
 
        if(notGoodLetters <= k) {
            //goodSubstring.pb(mp(h1, h2));
            goodSubstring.pb(h1);
        }
 
        for(; r < n; r++) {
            h1 = (b1 * (MOD1 + h1 - (last_base1 * ord(s[r - len]) % MOD1)) + ord(s[r])) % MOD1;
            //h2 = (b2 * (MOD2 + h2 - (last_base2 * ord(s[r - len]) % MOD2)) + ord(s[r])) % MOD2;
            if(good[s[r] - 'a'] != '1') notGoodLetters++;
            if(good[s[r - len] - 'a'] != '1') notGoodLetters--;
 
            if(notGoodLetters <= k) {
                //goodSubstring.pb(mp(h1, h2));
                goodSubstring.pb(h1);
            }
        }

        //sort(all(goodSubstring), cmp);
        sort(all(goodSubstring));
        ans += goodSubstring.size() > 0 ? 1 : 0;

        for(int i = 1; i < (int)goodSubstring.size(); i++) {
            /*if(goodSubstring[i].first != goodSubstring[i - 1].first || goodSubstring[i].second != goodSubstring[i - 1].second) {
                ans++;
            }*/
            if(goodSubstring[i] != goodSubstring[i - 1]) {
                ans++;
            }
        }

        goodSubstring.clear();
    }
    
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    solve();
}