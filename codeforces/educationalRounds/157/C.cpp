#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>
#include <map>
#include <set>
#include <iomanip>
#include <bitset>

#define all(x) (x).begin(), (x).end()
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

void solve(){
    int n; cin >> n;
    // map the sum of a string of length 4 with the number of such strings
    map<int, int> mp[6];

    vector<string> a(n);
    rep(i, n) {
        cin >> a[i];
    }

    ll ans = n;
    for(string& s : a) {
        int sum = 0, length = s.size();
        for(char c : s) {
            sum += (c - '0');
        }

        ans += 2 * mp[length][sum];
        mp[length][sum]++;
    }

    for(string& s : a) {
        int sum = 0, length = s.size();

        if(length == 1 || length == 2) continue;
        for(char c : s) {
            sum += (c - '0');
        }

        if(length == 3) {
            // the longest part is at right
            ll add = mp[1][sum - 2 * (s[0] - '0')];
            ans += add;
            // the longest part is at left
            add = mp[1][sum - 2 * (s[2] - '0')];
            ans += add;
        } else if(length == 4) {
            ll add = mp[2][sum - 2 * (s[0] - '0')];
            ans += add;

            add = mp[2][sum - 2 * (s[3] - '0')];
            ans += add;
        } else {
            ll add = mp[3][sum - 2 * (s[0] - '0')];
            ans += add;

            add = mp[1][sum - 2 * ((s[0] - '0') + (s[1] - '0'))];
            ans += add;


            add = mp[3][sum - 2 * (s[4] - '0')];
            ans += add;

            add = mp[1][sum - 2 * ((s[4] - '0') + (s[3] - '0'))];
            ans += add;
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