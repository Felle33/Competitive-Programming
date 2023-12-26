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

const int MAX_N = 1e6;

int n;
int letters[26];
int permuatations[MAX_N + 1];

ll exponentiation(ll b, ll e){
    ll res = 1;
    b %= MOD1;
    while(e > 0){
        if(e & 1) {
            res = res * b % MOD1;
        }  
        
        b = b * b % MOD1;
        e >>= 1;
    }

    return res;
}

ll factorial() {
    ll res = 1;
    permuatations[0] = 1;
    for(ll i = 1; i <= n; i++) {
        res = (res * i) % MOD1;
        permuatations[i] = res;
    }
    return res;
}

void solve(){
    string s; cin >> s;
    n = s.size();

    for(char c : s) {
        letters[c - 'a']++;
    }

    ll fact = factorial();

    for(int i = 0; i < 26; i++) {
        if(letters[i] > 1) {
            ll inv = exponentiation(permuatations[letters[i]], MOD1 - 2);
            fact = fact * inv % MOD1;
        }
    }

    cout << fact << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    solve();
}