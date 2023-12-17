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

const int MAX_N = 1000;

vector<pair<char, ll>> weights(10);

void compute_weight(string& s) {
    int k = s.size();
    ll weight = 1;
    for(int i = k - 1; i >= 0; i--) {
        weights[s[i] - 'a'].second += weight;
        weight *= 10;
    }
}

bool cmp(pair<char, ll>& p1, pair<char, ll>& p2) {
    return p1.second > p2.second;
}

void solve(){
    int n; cin >> n;
    set<int> first_letters;
    vector<string> strings(n);
    for(int i = 0; i < 10; i++) weights[i].first = 'a' + i;
    
    rep(i, n) {
        cin >> strings[i];
        first_letters.insert(strings[i][0]);
        compute_weight(strings[i]);
    }

    sort(all(weights), cmp);
    vector<bool> assigned(10);
    vector<int> digits(10);

    int it = 0;
    char c = weights[it].first;
    while(first_letters.count(c) > 0) {
        it++;
        c = weights[it].first;
    }
    digits[c - 'a'] = 0;
    assigned[c - 'a'] = 1;

    for(int digit = 1; digit < 10; digit++) {
        for(pair<char, ll>& p : weights) {
            char c = p.first;
            if(assigned[c - 'a']) continue;
            
            digits[c - 'a'] = digit;
            assigned[c - 'a'] = 1;
            break;
        }
    }

    ll ans = 0;
    for(string& s : strings) {
        ll cur = 0;
        for(int i = s.size() - 1, weight = 1; i >= 0; i--) {
            cur += digits[s[i] - 'a'] * weight;
            weight *= 10;
        }
        ans += cur;
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