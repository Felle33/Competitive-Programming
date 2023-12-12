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

const ll MOD1 = 1e7 + 3;
const ll MOD2 = 998244353;
const ll MOD3 = 99999999999999997;
const ll DIM = 1e6;
const ll INF = 1e15;
const ll LL_MAX = 9223372036854775807;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

int n;
vll prefs1;
vll prefs2;
vll pows1;
vll pows2;

ll b = 67;

int ord(char c) {
    return c - '0' + 1;
}

void calc_hash(char* s) {
    pows1[0] = 1;
    pows2[0] = 1;
    for(int i = 1; i < n; i++) {
        pows1[i] = pows1[i - 1] * b % MOD1;
        //pows2[i] = pows2[i - 1] * b % MOD2;
    }

    for(int i = 0; i < n; i++) {
        prefs1[i + 1] = (b * prefs1[i] + ord(s[i])) % MOD1;
        //prefs2[i + 1] = (b * prefs2[i] + ord(s[i])) % MOD2;
    }
}

char is_substring(char* t) {
    int m = strlen(t);
    ll hash1 = 0;
    ll hash2 = 0;

    for(int i = 0; i < m; i++) {
        hash1 = (hash1 * b + ord(t[i])) % MOD1;
        //hash2 = (hash2 * b + ord(t[i])) % MOD2;
    }

    for(int j = m; j <= n; j++) {
        ll pref1_hash = prefs1[j] - prefs1[j - m] * pows1[m] % MOD1;
        if(pref1_hash < 0) pref1_hash += MOD1;

        /*ll pref2_hash = prefs2[j] - prefs2[j - m] * pows2[m] % MOD2;
        if(pref2_hash < 0) pref2_hash += MOD2;
        if(pref1_hash == hash1 && pref2_hash == hash2) {
            return 'Y';
        }*/

        if(pref1_hash == hash1) {
            return 'Y';
        }

        
    }

    return 'N';
}

void solve(){
    char* s = (char *) malloc(sizeof(char) * 100001);
    scanf("%s[^\n]", s);
    n = strlen(s);
    int q;
    scanf("%d", &q);

    prefs1 = vll(n + 1);
    prefs2 = vll(n + 1);
    pows1 = vll(n);
    pows2 = vll(n);
    calc_hash(s);
    char* t = (char *) malloc(sizeof(char) * 2001);

    rep(i, q) {
        scanf("%s[^\n]", t);
        printf("%c\n", is_substring(t));
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    solve();
}