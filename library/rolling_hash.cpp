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

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e15;
const ll LL_MAX = 9223372036854775807;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

void search(string& haystack, string& needle, ll mod, vi& v) {
    ll b = 31;
    int n = haystack.size();
    int m = needle.size();
    // the last power used in the algo
    ll h = 1;
    ll hash_needle = 0;
    ll hash_hay = 0;

    for(int i = 0; i < m - 1; i++) {
        h = (h * b) % mod;
    }

    for(int i = 0; i < m; i++) {
        hash_needle = (b * hash_needle + needle[i]) % mod;
        hash_hay = (b * hash_hay + haystack[i]) % mod;
    }

    for(int i = 0; i <= n - m; i++) {
        if(hash_needle == hash_hay) {
            v.pb(i);
            cout << "Found an equal substring at index " << i << '\n';
        }

        if(i < n - m) {
            hash_hay = (b * (mod + hash_hay - h * haystack[i]) + haystack[i + m]) % mod;
        }
    }
}

void solve(){
    string s = "abcdefghijabcdefghabcabcd";
    string p = "abcd";
    vi v1;
    search(s, p, MOD, v1);
    vi v2;
    search(s, p, MOD + 2, v2);

    vi inters(max(v1.size(), v2.size()));
    auto it = set_intersection(all(v1), all(v2), inters.begin());
    inters.resize(it - inters.begin());

    cout << "Interns integers:\n";
    for(int x : inters) {
        cout << x << ' ';
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    solve();
}