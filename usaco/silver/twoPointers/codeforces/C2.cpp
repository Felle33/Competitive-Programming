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
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

void solve(){
    ll n, s; cin >> n >> s;
    vll a(n);
    rep(i, n) cin >> a[i];
    
    ll cur = 0, ans = 0, lastIndex = -1;
    ll l = 0, r = 0;
    for(; r < n; r++) {
        cur += a[r];
        if(cur > s) {
            if(lastIndex < l) {
                ll in = r - l;
                ans += (in + 1) * in / 2;
                lastIndex = r - 1;
            } else {
                ll numbersAdded = r - 1 - lastIndex;
                ll in = r - l;
                ll oldNum = in - numbersAdded;
                lastIndex = r - 1;

                ans += (in + 1) * in / 2 - (oldNum + 1) * oldNum / 2;
            }

            while(cur > s) {
                cur -= a[l];
                l++;
            }
        }
    }

    if(lastIndex < l) {
        ll in = r - l;
        ans += (in + 1) * in / 2;
        lastIndex = r - 1;
    } else {
        ll numbersAdded = r - 1 - lastIndex;
        ll in = r - l;
        ll oldNum = in - numbersAdded;
        lastIndex = r - 1;

        ans += (in + 1) * in / 2 - (oldNum + 1) * oldNum / 2;
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