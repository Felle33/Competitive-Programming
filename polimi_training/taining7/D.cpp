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

int n;
string strings[1000];
ll ans = INF;
bool already_mapped[10];
int conversion[10];
map<char, int> map_letter_int;
int next_int_to_map = 1;

ll convert_string(string& s) {
    ll conv = 0;
    int k = s.size();
    for(int i = 0; i < k; i++) {
        conv *= 10;
        conv += conversion[s[i] - 'a'];
    }
    return conv;
}

void calc_number() {
    ll cur = 0;
    for(int i = 0; i < n; i++) {
        cur += convert_string(strings[i]);
    }
    ans = min(ans, cur);
}

void rec(int missingLetters) {
    if(missingLetters == 0) {
        calc_number();
        return;
    }

    for(int i = 0; i < 10; i++) {
        char c = 'a' + i;
        if(!already_mapped[i]) {
            already_mapped[i] = 1;
            conversion[i] = next_int_to_map;
            next_int_to_map++;
            rec(missingLetters - 1);
            next_int_to_map--;
            already_mapped[i] = 0;
        }
    }
}

void solve(){
    cin >> n;
    set<int> first_letters;

    rep(i, n) {
        cin >> strings[i];
        first_letters.insert(strings[i][0]);
    }

    for(int i = 0; i < 10; i++) {
        char c = 'a' + i;
        if(first_letters.count(c) == 0) {
            already_mapped[i] = 1;
            conversion[i] = 0;
            rec(9);
            already_mapped[i] = 0;
        }
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